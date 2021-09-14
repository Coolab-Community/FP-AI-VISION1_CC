#   Copyright (c) 2020 STMicroelectronics.
#
#   This software component is licensed by ST under BSD-3-Clause license,
#   the "License"; You may not use this file except in compliance with the
#   License. You may obtain a copy of the License at:
#             https://opensource.org/licenses/BSD-3-Clause

import pandas as pd
import shutil
from pathlib import Path


def filter_coco(area_threshold, labels_dir, input_dir, output_dir):
    """Filter COCO dataset subset filtering person area.

    Args:
      area_threshold: Threshold of fraction of image area below which
      persons are filtered.
      labels_dir: COCO dataset labels directory path.
      input_dir: COCO dataset path.
      output_dir: new dataset output path.
    """
    labels_dpath = Path(labels_dir)
    labels_fpaths = labels_dpath.glob('*.txt')
    input_dpath = Path(input_dir)
    output_dpath = Path(output_dir)
    f = open(input_dpath.stem + '.txt','w+')
    f.write('filename label\n')
    for label_fpath in labels_fpaths:
        img_fname = label_fpath.name.replace('.txt', '.jpg')
        label = 'not-person'
        annotations = pd.read_csv(label_fpath, delimiter=' ', header=None)
        persons = annotations.loc[annotations[0] == 0]
        if persons.shape[0] != 0:
            big_persons = ((persons[3] * persons[4] * 100.0) > area_threshold).sum()
            if big_persons > 0:
                label = 'person'
            else:
                continue
        src_fpath = input_dpath / img_fname
        dst_dpath = output_dpath / label
        dst_dpath.mkdir(parents=True, exist_ok=True)
        shutil.copy(src_fpath, dst_dpath)
        f.write(img_fname + ' ' + label + '\n')
    f.close()


filter_coco(20.0, 'labels/train2014', 'train2014', 'person20')
filter_coco(20.0, 'labels/val2014', 'val2014', 'person20')
