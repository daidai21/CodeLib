#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: get_code.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 02 Aug 2019 04:41:19 PM CST
# =============================================================================


import sys
import requests


VERSION = 2 if sys.version < '3' else 3


__call__ = ["GetCode"]


class GetCode(object):
    """
    import code and exec from github, gitlab or gitee.

    Params:
        url:        complete url
        website:    option
        proxy:      dict
        use_proxy:  bool

    Returns:
        code exec over and no return anything.
    """
    def __init__(self, url, website="github", proxy=None, use_proxy=False):
        self.website = {
            "github": "https://raw.githubusercontent.com/",
            "gitee": "https://gitee.com/UserName/ProjectName/raw/",  # not use
            "gitlab": "https://gitlab.com/UserName/ProjectName/raw/",  # not use
        }
        self.proxy = {
            "http": "http://127.0.0.1:1080",
            "https": "https://127.0.0.1:1080",
        }
        err_msg = "param website must be in {0}".format(list(self.website))
        assert website in self.website, err_msg

        if website == "github":
            url = self.website["github"] + url
        else:
            url.replace("blob", "raw", 1)
        if use_proxy:
            self.proxy = proxy if proxy else self.proxy
        else:
            self.proxy = None
        code = requests.get(url, self.proxy).text
        if VERSION == 3:  # for print
            exec("from __future__ import print_function")
        exec(code)


if __name__ == "__main__":
    pass
