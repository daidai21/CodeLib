#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: atomicity.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sat Jan 18 14:31:41 2020
# =============================================================================


def write_to_file(path, file_name, content):
    """
    path:      the path to the folder where the file is located
    file_name: will be created file name
    content:   type is str, will be write content
    """
    import os
    try:
        if os.path.exists(os.path.join(path, "temp.txt")):
            print("have temp file in path, because program interrupted in pre \
                step on running.")
            os.remove(os.path.join(path, "temp.txt"))
        with open(os.path.join(path, "temp.txt")) as f:
            f.write(content)
            # make sure that all data is on disk
            # see https://stackoverflow.com/questions/7433057/is-rename-without-fsync-safe
            f.flush()
            os.fsync(f.fileno())
        os.rename(os.path.join(path, "temp.txt"), os.path.join(path, file_name))
    except Exception as err:
        print("Error: ", err)
