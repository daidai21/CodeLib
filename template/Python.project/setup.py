#!/usr/bin/python
# coding:utf-8

# ==================================================
# File Name: setup.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: 一  4/29 10:43:48 2019
# ==================================================


# learn more: https://github.com/daidai21/Python-Project-Guide/tree/Project/setup.py


from setuptools import setup, find_packages


with open('README.md') as f:
    readme = f.read()

with open('LICENSE') as f:
    license = f.read()

setup(
    name='Python-Project-Guide',
    version='0.1.0',
    description='Sample package for Python-Guide.org',
    long_description=readme,
    author='DaiDai',
    author_email='daidai4269@aliyun.com',
    url='https://github.com/daidai21/Python-Project-Guide/tree/project',
    license=license,
    packages=find_packages(exclude=('tests', 'docs'))
)
