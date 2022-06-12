/*
Sample Input
50 12346
376 144139
927438 927438
18 3312
9 3142
25 1299
111 33333
103 862150
6 1104
0 0

Sample Output
43 1 2 34 6
283 144 139
927438 927438
18 3 3 12
error
21 1 2 9 9
rejected
103 86 2 15 0
rejected
*/
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int target;
string num;
int sums[10][10]; //部分和，第一个索引表示哪个位置位置开始，第二个索引表示哪个位置结束
int maxn, Case;
bool f[10], flag[10];    //最终切片方式 和 dfs同步的切片方式
void dfs(int x, int sum) // x为新的开始位置索引，sum是前面的总和
{
    flag[x] = true;                         //改为访问过
    if (x == num.length() && sum <= target) //到底了并且总和小于目标值
    {
        if (sum == maxn) //最接近值出现过
            Case++;
        if (sum > maxn) //最接近值没出现过的
        {
            maxn = sum;                 //记录最接近值
            Case = 1;                 //赋予判断标志
            memcpy(f, flag, sizeof(f)); //拷贝切片方式
        }
        flag[x] = false; //改回没访问过
        return;
    }
    //从当前位置继续与后面的切片和相加
    for (int i = x; i < num.length(); i++)
        dfs(i + 1, sum + sums[x][i]);
    flag[x] = false; //改回没访问过
}
void part_Sigma() //算出部分和
{
    for (int i = 0; i < num.length(); i++)
    {
        for (int j = i; j < num.length(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum = sum * 10 + num[k] - '0';
            sums[i][j] = sum;
        }
    }
}
void print() //打印结果
{
    //三种情况
    if (Case == 0)
        cout << "error" << endl;
    else if (Case > 1)
        cout << "rejected" << endl;
    else
    {
        cout << maxn;
        for (int i = 0; i < num.length(); i++)
        {
            if (f[i]) //切割点
                cout << " ";
            cout << num[i];
        }
        cout << endl;
    }
}
int main()
{
    while (cin >> target >> num && target != 0) //输入
    {
        maxn = -1;                     //重置
        Case = 0;                    //重置
        memset(flag, 0, sizeof(flag)); //重置
        part_Sigma();                  //算出部分和
        dfs(0, 0);                     //进行搜索算法
        print();                       //打印结果
    }
    return 0;
}