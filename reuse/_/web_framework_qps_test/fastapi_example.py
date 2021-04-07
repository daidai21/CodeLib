#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# #############################################################################
# File Name   : fastapi_example.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  4/ 7 20:56:21 2021
# #############################################################################

from fastapi import FastAPI

app = FastAPI()


@app.get("/")
async def read_root():
    return {"Hello": "World"}
