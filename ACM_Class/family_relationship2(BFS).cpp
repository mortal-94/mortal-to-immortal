// D:\SCNU\algorithm_design\ACM程序设计课堂讲义\chap08
// --计算该家族是属于几代同堂
// 输入：孩子个数 孩子编号···
// 2 2 3
// 2 4 5
// 2 6 7
// 1 8
// 2 9 10
// 0
// 2 11 12
// 1 13
// 0
// 0
// 0
// 0
// 0
// 输出：
// 5

// -----广度优先搜索算法-----
// 一层一层来，用队列结构

#include <iostream>
#include <queue>
using namespace std;

//老师讲义这样写
struct queuenode
{
    int child;
    int level;
};
int generate(int root) // root第一代的孩子数
{
    queue<queuenode> qu;
    queuenode temp, newtemp;
    int child_num, child, i, maxlevel = 0;

    temp.child = root;
    temp.level = 1; //从第一代开始
    qu.push(temp);

    while (!qu.empty())
    {
        temp = qu.front();
        qu.pop();
        if (temp.level > maxlevel)
            maxlevel = temp.level;
        cin >> child_num; //输入孩子个数
        for (i = 0; i < child_num; i++)
        {
            cin >> child; //输入孩子编号
            newtemp.child = child;
            newtemp.level = temp.level + 1;
            qu.push(newtemp);
        }
    }
    return maxlevel;
}

// 我觉得可以这样改（就这题而言
int generate_()
{
    queue<int> qu;
    int level = 1; //从第一代开始
    int child_num, child, i, maxlevel = 0;

    qu.push(level);

    while (!qu.empty())
    {
        level = qu.front();
        qu.pop();
        if (level > maxlevel)
            maxlevel = level;
        cin >> child_num; //输入孩子个数
        for (i = 0; i < child_num; i++)
        {
            cin >> child; //输入孩子编号
            int next = level + 1;
            qu.push(next); //下一代
        }
    }
    return maxlevel;
}

int main()
{
    cout << generate_() << endl;
}