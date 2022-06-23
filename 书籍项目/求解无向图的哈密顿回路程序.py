# -*- coding = utf-8 -*-
# @Time : 2022/5/16 13:22
# @Author : mortallyn
# @File : 求解无向图的哈密顿回路程序5.py
# @Software : PyCharm
"""
原子命题定义
设有n^2个原子命题 H[a,b]，1 ≤ a,b ≤ n。
这里的 H[a,b] 表示哈密顿回路中的第 a 个位置被节点 b 占据。

故这些原子命题的赋值要满足以下几点：
1.每个节点 b 必须出现在路径中。---                 H[1,b] V H[2,b] V H[3,b] ...V... H[n,b]
2.路径中没有节点 b 出现两次。---                  (¬H[1,b] V ¬H[2,b]) ∧ (¬H[2,b] V ¬H[3,b]) ..∧.. (¬H[n-1,b] V ¬H[n,b])
3.路径上的每个位置 a 都必须被占用。---             H[a,1] V H[a,2] V H[a,3] ...V... H[a,n]
4.非连通节点 b 和 c 在路径中不能相邻。---          (¬H[1,b] V ¬H[2,c]) ∧ (¬H[2,b] V ¬H[3,c]) ..∧.. (¬H[n-1,b] V ¬H[n,c])
（在哈密顿回路中第一个节点和最后一个节点视为相邻---    ¬H[1,b] V ¬H[n,c]

程序实现
根据这些要求用CNF格式的逻辑公式表示出来，调用pycosat求解器求出满足要求的赋值列表。
再根据求解结果解释出该无向图的图哈密顿路径。

Sample Input
5 7
2 1
3 1
4 1
4 2
5 2
5 3
5 4
Sample Output
1 2 4 5 3 1
1 3 5 2 4 1
1 3 5 4 2 1
1 4 2 5 3 1

Sample Input
4 5
1 2
2 3
3 4
4 1
2 4
Sample Output
1 2 3 4 1
1 4 3 2 1
"""
import pycosat
import numpy as np
from time import time


def require():
    """
    满足上面列要求并把对应的简单析取式组成列表添加进CNF中
    :return: 无
    """
    global CNF, nodes, n, mymap
    for i in nodes:
        CNF.append([int(H[x - 1, i - 1]) for x in nodes])  # 每个节点 b 必须出现在路径中，这里的 b 是 i
        CNF.append([int(H[i - 1, x - 1]) for x in nodes])  # 路径中每个位置 a 必须被占用，这里的 a 是 i
        for j in nodes:
            if i < j:
                for k in nodes:
                    CNF.append([-int(H[i - 1, k - 1]), -int(H[j - 1, k - 1])])  # 路径中没有节点 b 出现两次，这里的 b 是 k

            if i != j and mymap[i - 1, j - 1] == 0:  # 非连通节点 b c 在路径中不能相邻，这里的 b c 是 i j
                for k in range(1, n):
                    CNF.append([-int(H[k - 1, i - 1]), -int(H[k, j - 1])])
                CNF.append([-int(H[0, i - 1]), -int(H[-1, j - 1])])  # 哈密顿回路中第一个节点和最后一个节点视为相邻，非连通则不能相邻


def convert_path(sol):
    """
    根据求解结果解释出该无向图的图哈密顿路径 的函数
    :param sol: 求解器求出的解决方案，即所有原子命题的赋值
    :return: 哈密顿路径
    """
    global n
    path_nodes_num = sorted(sol, reverse=True)[:n]
    path_ = [0] * n  # 创建一个长度为 n 的路径列表
    for item in path_nodes_num:
        a = (item - 1) // n + 1  # 哈密顿回路上的第 a 个位置
        b = item - (a - 1) * n  # 节点 b
        path_[a - 1] = b
    path_.append(path_[0])  # 回路
    return path_


"""全局变量"""
CNF = []
n, m = map(int, input().split())  # 接受输入的 顶点数 边数
mymap = np.zeros(shape=(n, n))  # 两点相同则值为1
H = np.arange(1, n * n + 1).reshape(n, n)  # 原子命题数字编号，行索引+1表示哈密顿回路的第几个点，列索引+1表示顶点编号
nodes = range(1, n + 1)  # 规定顶点的 数字编号 1..n
"""全局变量"""

"""接受边输入"""
for _ in range(m):
    u, v = map(int, input().split())
    mymap[u - 1, v - 1] = 1
    mymap[v - 1, u - 1] = 1
"""接受边输入"""

start = time()  # 开始时间
"""实现要求"""
require()
"""实现要求"""

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
