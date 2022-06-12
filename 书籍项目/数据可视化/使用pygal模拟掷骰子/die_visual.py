# -*- coding = utf-8 -*-
# @Time : 2022/5/8 14:54
# @Author : 林悦宁
# @File : die_visual.py
# @Software : PyCharm
from die import Die
import pygal  # 用来生成可缩放的矢量图形文件

# 创建一个D6和一个D10
die_1 = Die()
die_2 = Die(10)
# 掷几次骰子，并将结果存储在一个列表里
results = []
for roll_num in range(50000):
    result = die_1.roll() + die_2.roll()  # 结果相加
    results.append(result)
# print(results)

# 分析结果
frequencies = []
max_result = die_1.num_sides + die_2.num_sides
for value in range(2, max_result + 1):
    frequency = results.count(value)
    frequencies.append(frequency)
# print(frequencies)

# 对结果进行可视化
hist = pygal.Bar()  # 创建了一个pygal.Bar()实例

hist.title = 'Results of rolling a D6 and a D10 50,000 times.'
hist.x_labels = [str(i) for i in range(2, 16)]
hist.x_title = 'Result'
hist.y_title = 'Frequency of Result'

hist.add('D6 + D10', frequencies)
hist.render_to_file('dice_visual.svg')
