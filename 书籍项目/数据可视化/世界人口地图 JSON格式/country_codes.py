# -*- coding = utf-8 -*-
# @Time : 2022/5/8 18:32
# @Author : mortallyn
# @File : country_codes.py
# @Software : PyCharm
from pygal_maps_world.i18n import COUNTRIES


def get_country_code(country_name):
    """根据指定的国家,返回pygal使用的两个字母的国别码"""
    for code, name in COUNTRIES.items():
        if name == country_name:
            return code
    # 如果没有找到指定国家,就返回none
    return None
