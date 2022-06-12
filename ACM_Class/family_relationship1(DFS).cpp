// D:\SCNU\algorithm_design\ACM程序设计课堂讲义\chap08
// --计算该家族是属于几代同堂
// 输入：
// A 2 B C
// C 2 F H
// H 2 I J
// J 0
// I 0
// F 0
// B 2 D E
// E 2 G H
// H 0
// G 0
// D 1 M
// M 1 N
// N 0
// 输出
// 5

// -----深度优先搜索算法-----
// 一边到底再一边到底······，用栈结构

#include <iostream>
#include <stack>
using namespace std;

struct stacknode //定义结构体
{
    char info; //记录是谁
    int level; //记录是第几代
};
int generate_iterate() //迭代法的深度优先搜索
{
    stack<stacknode> stk1;
    char ch;
    int child_num, i, maxlevel = 0;
    stacknode temp, newtemp;

    temp.info = '0';
    temp.level = 1; //第一代开始
    stk1.push(temp);

    while (!stk1.empty())
    {
        cin >> ch;
        temp = stk1.top();
        stk1.pop();
        if (temp.level > maxlevel)
            maxlevel = temp.level;
        cin >> child_num;
        for (i = 0; i < child_num; i++)
        {
            cin >> newtemp.info;
            newtemp.level = temp.level + 1;
            stk1.push(newtemp);
        }
    }
    return maxlevel;
}
// 用递归则不用自定义结构体和自己使用栈结构了
int generate_recursion(int cur_level) //递归法的深度优先搜索，参数为当前的代数
{
    char ch;
    int templevel, childlevel;
    int child_num, i;

    cin >> ch; //跳过当前结点值
    cin >> child_num;
    templevel = cur_level;
    for (i = 0; i < child_num; i++)
        cin >> ch; //跳过所有的孩子结点值
    for (i = 0; i < child_num; i++)
    {
        childlevel = generate_recursion(cur_level + 1); //每个孩子都求出其对应的层次数
        if (childlevel > templevel)
            templevel = childlevel; //找出孩子中最大的层次数
    }
    return templevel;
}
int main()
{
    // cout << generate_iterate() << endl;    //迭代法函数使用
    cout << generate_recursion(1) << endl; //递归法函数使用
    return 0;
}