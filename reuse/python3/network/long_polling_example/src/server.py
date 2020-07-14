#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : server.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 二  7/14 23:32:39 2020
# #############################################################################


from flask import Flask
from flask import render_template
import flask_restful as restful

import os
import time
from datetime import datetime


app = Flask(__name__)
api = restful.Api(app)


@app.route("/")
def index():
    return render_template("index.html")


class DataUpdate(restful.Resource):
    def _is_updated(self, req_time):
        """
        Returns if resource is updated or it's the first time it has been requested.
        """
        return os.stat("data.txt").st_mtime > req_time  # last modify file time > req_time

    def get(self):
        """
        Returns 'data.txt' content when the resource has changed after the request time
        """
        req_time = time.time()
        while not self._is_updated(req_time):
            time.sleep(0.5)
        content = ''
        with open('data.txt') as data:
            content = data.read()
        return {
            "content": content,
            "date":    datetime.now().strftime('%Y/%m/%d %H:%M:%S')
        }


class Data(restful.Resource):
    def get(self):
        """
        Returns the current data content
        """
        content = ""
        with open("data.txt") as data:
            content = data.read()
        return {
            "content": content
        }


api.add_resource(DataUpdate, "/data-update")
api.add_resource(Data, "/data")


if __name__ == "__main__":
    app.run(port=8080, debug=True)
