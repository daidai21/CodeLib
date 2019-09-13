#!/usr/bin/python
# coding:utf-8

# ==================================================
# File Name: config.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: 一  4/29 11:18:46 2019
# ==================================================


import argparse
import json


def initialization():
    parser = argparse.ArgumentParser(description='parameter initialization')
    parser.add_argument('path', default='config.json')
    args = parser.parse_args()

    with open(args.path, 'r') as file:
        config = json.load(file)

    return config


if __name__ == "__main__":
    config = initialization()
