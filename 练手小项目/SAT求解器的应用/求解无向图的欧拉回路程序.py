# -*- coding = utf-8 -*-
# @Time : 2022/7/4 12:16
# @Author : mortallyn
# @File : 求解无向图的欧拉回路程序.py
# @Software : PyCharm

import pycosat
import numpy as np
from time import time


def require():
    """
    满足上面列要求并把对应的简单析取式组成列表添加进CNF中
    :return: 无
    """
    global CNF, side, n, mymap, m
    for i in side:
        CNF.append([int(H[x - 1, i - 1]) for x in side])  # 每条边 b 必须出现在路径中，这里的 b 是 i
        CNF.append([int(H[i - 1, x - 1]) for x in side])  # 路径中每个位置 a 必须被一条边占用，这里的 a 是 i
        for j in side:
            if i < j:
                for k in side:
                    CNF.append([-int(H[i - 1, k - 1]), -int(H[j - 1, k - 1])])  # 路径中没有边 b 出现两次，这里的 b 是 k
                    if mymap[i] & mymap[j] & mymap[k]

            if i != j and not (mymap[i] & mymap[j]):  # 非连通的边 b c 在路径中不能相邻，这里的 b c 是 i j
                for k in range(1, m):
                    CNF.append([-int(H[k - 1, i - 1]), -int(H[k, j - 1])])
                CNF.append([-int(H[0, i - 1]), -int(H[-1, j - 1])])  # 欧拉回路中第一条边和最后一条边视为相邻，非连通则不能相邻


def convert_path(sol):
    """
    根据求解结果解释出该无向图的图哈密顿路径 的函数
    :param sol: 求解器求出的解决方案，即所有原子命题的赋值
    :return: 哈密顿路径
    """
    global n, m, mymap
    path_sides_num = sorted(sol)[m * (m - 1):]
    print(path_sides_num)
    path_ = [0] * (m + 1)  # 创建一个长度为 m+1 的路径列表
    path_[0] = (mymap[(path_sides_num[0] - 1) % m + 1] - mymap[(path_sides_num[1] - 1) % m + 1]).pop()
    for index, item in enumerate(path_sides_num):
        b = (item - 1) % m + 1  # 边 b
        mymap[b].discard(path_[index])
        path_[index + 1] = mymap[b].pop()
    path_.append(path_[0])  # 回路
    return path_


"""全局变量"""
CNF = []
n, m = map(int, input().split())  # 接受输入的 顶点数 边数
# mymap = np.zeros(shape=(n, n))  # 两点相同则值为1
mymap = {}
H = np.arange(1, m * m + 1).reshape(m, m)  # 原子命题数字编号，行索引+1表示欧拉回路的第几条边，列索引+1表示边编号
nodes = range(1, n + 1)  # 规定顶点的 数字编号 1..n
side = range(1, m + 1)  # 规定边的 数字编号 1..m
"""全局变量"""

"""接受边输入"""
for i in range(m):
    u, v = map(int, input().split())
    mymap[i + 1] = {u, v}
    # mymap[u - 1, v - 1] = 1
    # mymap[v - 1, u - 1] = 1
"""接受边输入"""
print(H)
print(mymap)

start = time()  # 开始时间
"""实现要求"""
require()
"""实现要求"""

# print(CNF)

"""SAT求解"""
sol = pycosat.solve(CNF)
if sol != 'UNSAT':
    HamiltonianCircuit = convert_path(sol)
    print(' '.join(str(x) for x in HamiltonianCircuit))
else:
    print("NO")
"""SAT求解"""
end = time()  # 结束时间
print('耗时： ', end - start, 's')
