//大体思路就是
//从(0,0)开始，一旦找到可以放置的点，进入递归，找到在该点放置的情况下所有的可以放置的个数
//          出来再找可以放置的点，又递归……

#include <iostream>
using namespace std;
//全局变量
int maxn = INT32_MIN;
int n;
char a[4][4]; //依题意最大的是4×4

bool judge(int row, int col) //判断函数，可放置返回真，否则返回假
{
    for (int i = row - 1; i >= 0; i--) //扫描col列，在row行上面的所有位置
    {
        if (a[i][col] == '@') //发现有之前放置有，直接返回假
            return false;
        else if (a[i][col] == 'X') //发现有墙，说明该位置在col列上看是没问题的，退出循环
            break;
    }
    for (int i = col - 1; i >= 0; i--) //扫描row行，在col列左边所有的位置
    {
        if (a[row][i] == '@') //发现之前放置有，直接返回假
            return false;
        else if (a[row][i] == 'X') //发现有墙，说明该位置在row行上看是没问题的，退出循环
            break;
    }
    return true;
}
void DFS(int pos, int count) //搜索函数，深度优先搜索
{
    if (pos == n * n) //全部位置都测试过了
    {
        if (maxn < count) //是否有更大的放置数
        {
            maxn = count;
        }
        return;
    }
    else
    {
        //根据pos计算行列坐标
        int row = pos / n;
        int col = pos % n;
        //测试该位置是否可放置
        if (a[row][col] == '.' && judge(row, col)) //可放置
        {
            a[row][col] = '@';       //赋予特殊值
            DFS(pos + 1, count + 1); //进入下一个位置，并且当前数量加1

            a[row][col] = '.'; //出来后恢复这次的数据
        }
        //该位置不可放置，或搜索完该位置的所有放置后，对下一个位置进行操作
        DFS(pos + 1, count); //进入下一个位置，但数量没变化
    }
}
int main()
{
    while (cin >> n && n != 0)
    {
        //数据读入存储
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        //搜索，处理好Max
        DFS(0, 0); //从位置为0，放置数量为0开始
        //输出结果
        cout << maxn << endl;

        //重置Max，以备下个数据使用
        maxn = INT32_MIN;
    }
    return 0;
}