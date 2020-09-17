#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : metrics.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 四  9/17 16:31:22 2020
# #############################################################################


import pandas as pd


def _check_df_val(df):
    """
    df value only in set(0, 1) check
    
    Input:
        DataFrame
    Output:
        bool
    """
    st = set()
    for idx, row in df.iterrows():
        for val in row.tolist():
            st.add(val)
            if len(st) > 2:
                return False
    if st != set([0, 1]):
        return False
    return True


def support(df, X, Y):
    """
    Input:
        DataFrame
            value in set(0, 1)
        str
        str
    Output:
        float
    """
    assert df is not None
    assert isinstance(df, pd.DataFrame)
    assert _check_df_val(df) == True
    assert isinstance(X, str)
    assert isinstance(Y, str)

    return df[(df[X] == 1) & (df[Y] == 1)].shape[0] / df.shape[0]


def confidence(df, X, Y):
    """
    X -> Y

    Input:
        DataFrame
            value in set(0, 1)
        str
        str
    Output:
        float
    """
    assert df is not None
    assert isinstance(df, pd.DataFrame)
    assert _check_df_val(df) == True
    assert isinstance(X, str)
    assert isinstance(Y, str)

    return (df[(df[X] == 1) & (df[Y] == 1)].shape[0] / df.shape[0]) / (df[df[X] == 1].shape[0] / df.shape[0])


def lift(df, X, Y):
    """
    Input:
        DataFrame
            value in set(0, 1)
        str
        str
    Output:
        float
    """
    assert df is not None
    assert isinstance(df, pd.DataFrame)
    assert _check_df_val(df) == True
    assert isinstance(X, str)
    assert isinstance(Y, str)

    if (df[(df[X] == 0) & (df[Y] == 1)].shape[0] / df.shape[0]) == 0:
        return float("inf")
    return (df[(df[X] == 1) & (df[Y] == 1)].shape[0] / df.shape[0]) / \
        (df[(df[X] == 0) & (df[Y] == 1)].shape[0] / df.shape[0])
