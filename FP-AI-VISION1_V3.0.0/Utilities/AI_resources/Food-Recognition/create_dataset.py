'''
File: create_dataset.py
Brief: helper script to create a dataset for onboard validation application
Copyright: 2020 STMicroelectronics
Licence: BSD-3 Clause
'''

import os
import click
import shutil
import platform
from struct import *
import subprocess

BMP_HEADER_HEIGHT_OFFSET = 0x16


@click.command()
@click.argument("path", required=True, type=click.Path(exists=True))
@click.option("--output", default="dataset",
              help="Name of the output directory")
@click.option("--resize/--no-resize", default=False,
              help="Resize images ? Disabled by default")
@click.option("--width", default=224, help="Target width if resize is True")
@click.option("--height", default=224, help="Target height if resize is True")
def create_dataset(path, output, resize, width, height):
    '''Creates a dataset of PPM images to use in Onboard validation application

    Reads images in any format from PATH and saves them in an ouput directory in BMP 565 format.
    '''
    if not os.path.exists(output):
        os.makedirs(output)
    else:
        valid_input = False
        while not valid_input:
            print(
                'directory {} already exists. Do you want to remove it ? (y/n)'.format(output))
            choice = input()
            if choice == 'y':
                shutil.rmtree(output, ignore_errors=True)
                valid_input = True
            elif choice == 'n':
                print('Cannot continue. Exiting')
                exit(-1)

    # Magick exe
    magick_exe = 'convert'
    if platform.system() == 'Windows':
        magick_exe = 'magick.exe convert'

    # Check imagemagick installation
    ret = os.system('{} --version'.format(magick_exe))
    if ret != 0:
        print('Error: ImageMagick not found. Please check your installation of ImageMagick')
        exit(-1)

    # Args
    magick_args = []
    if resize:
        magick_args.append('-resize {}x{}!'.format(width, height))

    magick_args.append('-format bmp')
    magick_args.append('-define bmp:subtype=RGB565')
    magick_args.append('-flip')

    # Filter out the directories
    labels = [f for f in os.listdir(
        path) if os.path.isdir(os.path.join(path, f))]
    print(labels)
    if len(labels) < 1:
        print("No subdirectories found.")
        exit(-1)

    for label in labels:
        label_full_path = os.path.join(path, label)
        filenames = os.listdir(label_full_path)
        if len(filenames) < 1:
            print("No image found in {}".format(label))
            exit(-1)
        for filename in filenames:
            file_full_path = os.path.join(label_full_path, filename)
            if os.path.isdir(file_full_path):  # Ignore directories
                continue

            filename_no_ext = filename.split('.')[0]
            img_path = os.path.join(path, label, filename)

            # in the case of food demo, the classname is not the same as in
            # the Food-101 dataset
            # to match the labels in the code, underscores must be replaced
            # with spaces and words needs to be capitalized
            label_out = label.replace('_', ' ').title()
            output_classdir = os.path.join(output, label_out)

            if not os.path.exists(output_classdir):
                os.makedirs(output_classdir)

            output_file_path = os.path.join(
                output, label_out, '{}.bmp'.format(filename_no_ext))

            img_path_q = '"{}"'.format(img_path)
            output_file_path_q = '"{}"'.format(output_file_path)

            command = [
                magick_exe,
                img_path_q,
                *magick_args,
                output_file_path_q]
            command_str = r' '.join(command)

            print(command_str)

            ret = os.system(command_str)

            if ret == 0:
                # Trick to speed up BMP reading on MCU side
                # We have fliped the image buffer in order to have it in
                # the proper ordering and here we replace the height in
                # the header by the opposite of the height in order to have
                # a valid file
                with open(output_file_path, 'rb+') as f:
                    f.seek(BMP_HEADER_HEIGHT_OFFSET)
                    height_b = f.read(4)
                    height_i = unpack('i', height_b)[0]
                    neg_height_i = -height_i
                    height_b = pack('i', neg_height_i)
                    f.seek(-4, os.SEEK_CUR)
                    f.write(height_b)


if __name__ == '__main__':
    create_dataset()
