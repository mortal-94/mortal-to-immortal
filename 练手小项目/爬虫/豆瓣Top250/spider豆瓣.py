# -*- coding = utf-8 -*-
# @Time : 2022/6/2 20:54
# @Author : mortallyn
# @File : spider豆瓣.py
# @Software : PyCharm
import re
import urllib.error
import urllib.request
import xlwt
from bs4 import BeautifulSoup


def main():
    # 爬取网页的网页
    baseurl = "https://movie.douban.com/top250?start="
    # 得到数据
    datalist = getData(baseurl)
    # 保存数据
    savepath = ".\\豆瓣Top250.xls"
    saveData(datalist, savepath)


# 正则查找规则
findLink = re.compile(r'<a href="(.*?)">')
findImgSrc = re.compile(r'<img.*src="(.*?)"', re.S)  # 让换行包含
findTitle = re.compile(r'<span class="title">(.*)</span>')
findRating = re.compile(r'<span class="rating_num" property="v:average">(.*)</span>')
findJudge = re.compile(r'<span>(\d*)人评价</span>')
findInq = re.compile(r'<span class="inq">(.*)</span>')
findBd = re.compile(r'<p class="">(.*?)</p>', re.S)


def getData(baseurl):
    datalist = []  # 总数据列表
    # 解析数据
    for i in range(0, 25):  # 解析25页
        url = baseurl + str(i * 25)  # 每页25条
        html = askURL(url)  # 获取一页
        # 逐一解释数据
        #  用html解释器解释获取的一页内容
        soup = BeautifulSoup(html, "html.parser")
        #  找符号要求的字符串 div开头 class = item 的数据
        for item in soup.find_all('div', class_="item"):
            # print(item)
            data = []  # 一部电影的所有信息
            item = str(item)  # 转字符串

            # 找链接 re  规则  查找源头
            link = re.findall(findLink, item)[0]  # 得到的一个列表，只有一个元素
            data.append(link)
            imgSrc = re.findall(findImgSrc, item)[0]
            data.append(imgSrc)
            titles = re.findall(findTitle, item)
            # 名称可能有两个
            if len(titles) == 2:
                ctitle = titles[0]
                data.append(ctitle)
                otitle = titles[1].replace("/", "")
                data.append(otitle)
            else:
                data.append(titles[0])
                data.append(' ')

            rating = re.findall(findRating, item)[0]
            data.append(rating)
            judgenum = re.findall(findJudge, item)[0]
            data.append(judgenum)
            inq = re.findall(findInq, item)
            # 概述可能没有
            if len(inq) != 0:
                inq = inq[0].replace("。", "")
                data.append(inq)
            else:
                data.append(' ')

            bd = re.findall(findBd, item)[0]
            bd = re.sub(r'<br(\s+)?/>(\s+)?', " ", bd)  # 去 <br/>
            bd = re.sub("/", " ", bd)  # 去 /
            data.append(bd.strip())  # 去空格

            datalist.append(data)
    print(datalist)
    return datalist


# 得到指定的一个URL网页内容
def askURL(url):
    head = {  # 伪装爬虫
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
                      "Chrome/101.0.4951.54 Safari/537.36 "
    }
    # 以head为用户 发出请求
    request = urllib.request.Request(url, headers=head)
    html = ""
    try:
        # request请求得到的响应；  urlopen--以request请求打开这个url
        response = urllib.request.urlopen(request)
        # 得到的响应中的 内容 read()
        html = response.read().decode("utf-8")  # 以utf-8解码
        # print(html)
    except urllib.error.URLError as e:  # 可能会遇到的问题
        if hasattr(e, "code"):
            print(e.code)
        if hasattr(e, "reason"):
            print(e.reason)

    return html


def saveData(datalist, savepath):
    book = xlwt.Workbook(encoding="utf-8")
    sheet = book.add_sheet('豆瓣Top250', cell_overwrite_ok=True)
    col = ("电影详情链接", "图片链接", "影片中文名", "影片外国名", "评分", "评分数", "概述", "相关信息")
    for i in range(0, len(col)):
        sheet.write(0, i, col[i])  # 写列名
    for i in range(0, 250):
        print('第{}条'.format(i + 1))
        data = datalist[i]
        for j in range(0, len(col)):
            sheet.write(i + 1, j, data[j])
    book.save(savepath)


if __name__ == "__main__":
    main()
