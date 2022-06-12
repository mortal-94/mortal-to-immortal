# -*- coding = utf-8 -*-
# @Time : 2022/5/8 20:55
# @Author : 林悦宁
# @File : python_repos.py
# @Software : PyCharm
import requests
import pygal
from pygal.style import LightColorizedStyle as LCS, LightenStyle as LS
import time

# 执行API调用并存储相应
url = 'https://api.github.com/search/repositories?q=language:python&sort=stars'
r = requests.get(url)
print('Status code:', r.status_code)  # 状态码200表示请求成功

# 将API响应存储在一个变量中
response_dict = r.json()
print("Total repositories:", response_dict['total_count'])  # 仓库总数

# 研究有关仓库的信息
repo_dicts = response_dict['items']
print("Repositories returned:", len(repo_dicts))  # 获取的仓库个数

names, plot_dicts = [], []
for repo_dict in repo_dicts:
    names.append(repo_dict['name'])
    # 鼠标放置显示的内容
    plot_dict = {
        'value': repo_dict['stargazers_count'],  # 星星数
        'label': repo_dict['description'],  # 描述消息
        'xlink': repo_dict['html_url'],  # 链接
    }
    plot_dicts.append(plot_dict)

# 可视化
my_style = LS('#333366', base_style=LCS)  # 少红33，少绿33，多蓝66
my_style.title_font_size = 24  # 标题字体大小
my_style.label_font_size = 14  # 轴副标签字体大小
my_style.major_label_font_size = 18  # 轴主标签字体大小，y轴上一些特定的刻度突出

my_config = pygal.Config()
my_config.x_label_rotation = 45  # 旋转45度
my_config.show_legend = False  # 无需显示图例
my_config.truncate_label = 15  # 截断标签 长度15 如果将鼠标指向被截断的标签，将显示完整标签
my_config.show_y_guides = False  # 以隐藏图表中的水平线

my_config.width = 1000  # 图形宽度

chart = pygal.Bar(my_config, style=my_style)
chart.title = 'Most-Starred Python Projects on GitHub\nAs of ' + time.strftime('%Y-%m-%d %H:%M:%S',
                                                                               time.localtime(time.time()))
chart.x_labels = names

chart.add('', plot_dicts)
chart.render_to_file('python_repos.svg')

# 处理结果
# 打印第一个仓库信息
# repo_dict = repo_dicts[0]
# print('\nKeys:', len(repo_dict))
# print("\nSelected information about first repository:")
# print('Name:', repo_dict['name'])  # 打印项目名称
# print('Owner:', repo_dict['owner']['login'])  # 打印所有者
# print('Stars:', repo_dict['stargazers_count'])
# print('Repository:', repo_dict['html_url'])
# print('Created:', repo_dict['created_at'])
# print('Updated:', repo_dict['updated_at'])
# print('Description:', repo_dict['description'])

# # 对每个库进行信息打印
# print("\nSelected information about each repository:")
# for repo_dict in repo_dicts:
#     print('\nName:', repo_dict['name'])
#     print('Owner:', repo_dict['owner']['login'])
#     print('Stars:', repo_dict['stargazers_count'])
#     print('Repository:', repo_dict['html_url'])
#     print('Description:', repo_dict['description'])
