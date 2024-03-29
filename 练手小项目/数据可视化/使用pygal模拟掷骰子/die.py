# -*- coding = utf-8 -*-
# @Time : 2022/5/8 14:46
# @Author : mortallyn
# @File : die.py
# @Software : PyCharm
from random import randint


class Die():
    """表示一个骰子的类"""

    def __init__(self, num_sides=6):
        """骰子默认6面"""
        self.num_sides = num_sides

    def roll(self):
        """返回一个位于1和骰子面数之间的随机值"""
        return randint(1, self.num_sides)  # 起始值1、终止值num_sides或这两个值之间的任何整数。
