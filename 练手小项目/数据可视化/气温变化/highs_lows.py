# -*- coding = utf-8 -*-
# @Time : 2022/5/8 15:36
# @Author : mortallyn
# @File : highs_lows.py
# @Software : PyCharm
import csv
import os
from matplotlib import pyplot as plt
from datetime import datetime

os.chdir(r'D:\SCNU\High_level_language_programming\Python_learning\资源\《Python编程》源代码文件\chapter_16')
# 从文件中获取日期,最高气温,最低气温
filename = 'death_valley_2014.csv'
# filename = 'sitka_weather_07-2014.csv'
# filename = 'sitka_weather_2014.csv'
with open(filename) as f:
    reader = csv.reader(f)
    header_row = next(reader)

    # for index, column_header in enumerate(header_row):
    #     print(index, column_header)

    dates, highs, lows = [], [], []
    for row in reader:
        # 错误检查
        try:
            current_date = datetime.strptime(row[0], '%Y-%m-%d')  # 修改日期格式
            high = int(row[1])
            low = int(row[3])
        except ValueError:
            print(current_date, 'missing data')
        else:
            dates.append(current_date)
            highs.append(high)
            lows.append(low)

# 根据数据绘制图形
fig = plt.figure(dpi=128, figsize=(10, 6))
plt.plot(dates, highs, c='red', alpha=0.5)  # 最高气温
plt.plot(dates, lows, c='blue', alpha=0.5)  # 最低气温
plt.fill_between(dates, highs, lows, facecolor='blue', alpha=0.1)  # 填充两者之间的区域

# # 刻度制作
# index = 0
# my_xticks = []
# for i in [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30]:
#     index += i
#     my_xticks.append(dates[index])
# plt.xticks(my_xticks)

# 设置图形格式
plt.title('Daily high and low temperatures - 2014\nDeath Valley, CA', fontsize=24)
plt.xlabel('', fontsize=16)
fig.autofmt_xdate()  # 绘制斜的日期标签，以免它们彼此重叠。
plt.ylabel('Temperature (F)', fontsize=16)
# fontsize 参数调整字体大小
plt.tick_params(axis='both', which='major', labelsize=10)  # 刻度设置

plt.show()
