# -*- coding = utf-8 -*-
# @Time : 2022/5/8 17:14
# @Author : 林悦宁
# @File : world_population.py
# @Software : PyCharm
import json
import os
from country_codes import get_country_code
import pygal_maps_world.maps
from pygal.style import LightColorizedStyle, RotateStyle  # 设置地图样式

os.chdir(r'D:\SCNU\High_level_language_programming\Python_learning\资源\《Python编程》源代码文件\chapter_16')

# 将数据加载到一个列表中
filename = 'population_data.json'
with open(filename) as f:
    pop_data = json.load(f)  # 将数据转换为Python能够处理的格式

# 创建一个包含人口数量的字典
cc_populations = {}
for pop_dict in pop_data:
    if pop_dict['Year'] == '2010':
        country_name = pop_dict['Country Name']
        population = int(float(pop_dict['Value']))  # 人口数量值可能异常,要先转float再转int
        code = get_country_code(country_name)
        if code:
            cc_populations[code] = population

# 根据人口数量将所有的国家分成三组
cc_pops_1, cc_pops_2, cc_pops_3 = {}, {}, {}
for cc, pop in cc_populations.items():
    if pop < 10000000:
        cc_pops_1[cc] = pop
    elif pop < 1000000000:
        cc_pops_2[cc] = pop
    else:
        cc_pops_3[cc] = pop

wm_style = RotateStyle('#336699', base_style=LightColorizedStyle)  # 十六进制的RGB颜色,少红33,多绿66,更多蓝99,后面参数是高亮
wm = pygal_maps_world.maps.World(style=wm_style)
wm.title = 'World Population in 2010, by Country'
wm.add('0-10m', cc_pops_1)
wm.add('10m-1bn', cc_pops_2)
wm.add('>1bn', cc_pops_3)

os.chdir(r'D:\SCNU\High_level_language_programming\Python_learning\python_program\书籍项目\数据可视化\世界人口地图 JSON格式')
wm.render_to_file('world_population.svg')
