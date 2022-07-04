# -*- coding = utf-8 -*-
# @Time : 2022/5/8 13:52
# @Author : mortallyn
# @File : rw_visual.py
# @Software : PyCharm
import matplotlib.pyplot as plt
from random_work import RandomWalk

# 只要程序处于活动状态，就不断模拟随机漫步
while True:
    # 创建一个RandomWalk实例，并将其包含的点都绘制出来
    rw = RandomWalk(5000)
    rw.fill_walk()

    # 设置绘图窗口的尺寸
    plt.figure(figsize=(10, 6), dpi=128)

    # 隐藏坐标轴，注意要放在绘图之前
    current_axes = plt.axes()
    current_axes.xaxis.set_visible(False)
    current_axes.yaxis.set_visible(False)

    # 给点着色，并绘制
    point_numbers = list(range(rw.num_points))
    plt.scatter(rw.x_values, rw.y_values, c=point_numbers,
                cmap='Blues', edgecolors='none', s=1)
    # 这里的参数c指定着颜色的深度，cmap指定着颜色（colormap，颜色映射）
    # edgecolors=none以删除每个点周围的轮廓

    # 突出起点和终点
    plt.scatter(0, 0, c='green', edgecolors='none', s=100)
    plt.scatter(rw.x_values[-1], rw.y_values[-1], c='red', edgecolors='none', s=100)
    # 这里的参数c指定颜色

    plt.show()

    keep_running = input('Make another walk? (y/n): ')
    if keep_running == 'n':
        break
