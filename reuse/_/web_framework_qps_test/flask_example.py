#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# #############################################################################
# File Name   : flask_example.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  4/ 7 20:56:38 2021
# #############################################################################

from flask import Flask
import logging

log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)

app = Flask(__name__)


@app.route('/')
def hello_world():
    return 'Hello, World!'
