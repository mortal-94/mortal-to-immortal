# -*- coding = utf-8 -*-
# @Time : 2022/5/8 18:43
# @Author : 林悦宁
# @File : na_populations.py
# @Software : PyCharm
import pygal_maps_world.maps

wm = pygal_maps_world.maps.World()
wm.title = 'Populaition of Countries in North America'
wm.add('North America', {'ca': 34126000, 'us': 309349000, 'mx': 113423000})

wm.render_to_file('na_populations.svg')