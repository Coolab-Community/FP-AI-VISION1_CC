How to create a dataset for validation
======================================

Requirements:
-------------

* ImageMagick: 
For Debian-based OS, it can be installed with `sudo apt install imagemagick`
For other platforms please follow installation instructions [here](https://imagemagick.org/script/download.php)

* Python 3.4: Can be installed from [here](https://www.python.org/downloads/)

* Python dependencies: run `pip install -r requirements.txt` in this directory

How to use the script:
----------------------

You need a directory containing one sub-directory per class for your classification. The images you want to use for testing must be placed in these sub-directories.
For instance, if you classify cats and dogs, you should have:

```

 my_images
 ├── cats
 │   ├── cat0001.jpg
 │   ├── kat.jpeg
 │   ├── other_cat.png
 │   └── ...
 └── dogs
     ├── dog1.jpg
     ├── dog2.tiff
     ├── other_dog.png
     └── ...

```

You can then run the `create_dataset.py` script as following:

`python create_dataset.py path/to/my_images`

This will create a directory called `dataset` containing images converted in BMP with RGB565 encoding.
