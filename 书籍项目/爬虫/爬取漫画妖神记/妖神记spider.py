# -*- coding = utf-8 -*-
# @Time : 2022/6/3 18:54
# @Author : 林悦宁
# @File : 妖神记spider.py
# @Software : PyCharm
import requests
import os
import re
from bs4 import BeautifulSoup
from contextlib import closing
from tqdm import tqdm
import time

"""
    Author:
        Jack Cui
    Wechat:
        https://mp.weixin.qq.com/s/OCWwRVDFNslIuKyiCVUoTA
"""

# 创建保存目录
save_dir = '妖神记'
if save_dir not in os.listdir('./'):
    os.mkdir(save_dir)

# 爬取的网页
target_url = "https://www.dmzj.com/info/yaoshenji.html"

# 获取动漫章节链接和章节名，共后面爬取下载
r = requests.get(url=target_url)
bs = BeautifulSoup(r.text, 'lxml')
list_con_li = bs.find('ul', class_="list_con_li")
cartoon_list = list_con_li.find_all('a')
chapter_names = []
chapter_urls = []
for cartoon in cartoon_list:
    href = cartoon.get('href')  # 章节链接
    name = cartoon.text  # 章节名
    chapter_names.insert(0, name)
    chapter_urls.insert(0, href)

# 下载漫画
for i, url in enumerate(tqdm(chapter_urls)):
    download_header = {
        'Referer': url  # 该章的链接，因为要打开这个链接才可访问图片
    }
    name = chapter_names[i]  # 章名
    # 去掉.
    while '.' in name:
        name = name.replace('.', '')
    # 逐章保存
    chapter_save_dir = os.path.join(save_dir, name)  # 制作以章名命名的文件夹路径
    if name not in os.listdir(save_dir):  # 加个if
        os.mkdir(chapter_save_dir)  # 创建该章的文件夹
        # 开始爬一章的图片
        r = requests.get(url=url)
        html = BeautifulSoup(r.text, 'lxml')
        script_info = html.script
        #   解析出图片链接  4个数字固定/5个数字固定/13或14个数字随一章中的页变化
        pics = re.findall('\d{13,14}', str(script_info))
        for j, pic in enumerate(pics):  # 长度13的后面拼0，以便后面排序
            if len(pic) == 13:
                pics[j] = pic + '0'
        pics = sorted(pics, key=lambda x: int(x))  # 排序，匹配每页顺序
        chapterpic_qian = re.findall('\|(\d{4})\|', str(script_info))[0]
        chapterpic_hou = re.findall('\|(\d{5})\|', str(script_info))[0]
        #      下载链接制作  图片保存
        for idx, pic in enumerate(pics):
            #      下载链接制作
            if pic[-1] == '0':
                url = 'https://images.dmzj.com/img/chapterpic/' + chapterpic_qian + '/' + chapterpic_hou + '/' + pic[
                                                                                                                 :-1] + '.jpg'
            else:
                url = 'https://images.dmzj.com/img/chapterpic/' + chapterpic_qian + '/' + chapterpic_hou + '/' + pic + '.jpg'
            #       图片保存
            pic_name = '%03d.jpg' % (idx + 1)  # 这章的第 idx+1 页 (用三位数命名文件
            pic_save_path = os.path.join(chapter_save_dir, pic_name)  # 制作路径
            # with伪装，让它以为我还在网页里面，并非拿出网页内容出来分析（要用closing方法
            with closing(requests.get(url, headers=download_header, stream=True)) as response:
                if response.status_code == 200:  # 状态码为 200 表示响应成功
                    with open(pic_save_path, "wb") as file:  # 二进制写入图片
                        for data in response.iter_content(chunk_size=1024):
                            file.write(data)
                else:
                    print('链接异常')
        time.sleep(10)
