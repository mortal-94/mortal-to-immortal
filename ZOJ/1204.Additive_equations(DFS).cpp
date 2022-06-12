/*
Sample Input
3
3 1 2 3
3 1 2 5
6 1 2 3 5 4 6
Output for the Sample Input
1+2=3

Can't find any equations.

1+2=3
1+3=4
1+4=5
1+5=6
2+3=5
2+4=6
1+2+3=6
*/
// -----------一个集合能组成多少个等式-----
// DFS
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int N, M, nums[30];
bool vis[30];   //记录访问状态
struct equation //加法方程结构体
{
    string a[30]; //加法方程
    int len;      //方程长度，用数字个数表示

    bool operator<(const equation &eq) const //自定义比较
    {
        if (len != eq.len) //长度不同时，长度小的在前
            return len > eq.len;
        else //长度相同时，数字小的在前
        {
            for (int i = 0; i < 30; i = i + 2) //数字从0开始隔一个符号，数字 符号 数字 符号...
            {
                if (a[i] != eq.a[i]) //不是相同数字就进行比较
                    return stoi(a[i]) > stoi(eq.a[i]);
            }
        }
    }
};
priority_queue<equation> qu;   //存储加法方程的优先队列
bool judge(int sum, int index) //判断sum是否在index索引之后的nums数组中
{
    for (int i = index + 1; i < M; i++)
    {
        if (nums[i] == sum)
            return true;
    }
    return false;
}
void DFS(int sum, int index, int depth)
{
    if (judge(sum, index)) //加法方程成立，存方程
    {
        equation eq;
        int j = 0;
        for (int i = 0; i < index; i++)
        {
            if (vis[i]) //把访问过的存起来
            {
                eq.a[j] = to_string(nums[i]);
                eq.a[++j] = "+";
                j++;
            }
        }
        eq.a[j] = to_string(nums[index]);
        eq.a[++j] = "=";
        eq.a[++j] = to_string(sum);
        eq.len = depth;
        qu.push(eq);
    }
    //遍历
    for (int i = index + 1; i < M; i++)
    {
        int ssum = sum + nums[i];
        if (!vis[i] && ssum <= nums[M - 1]) //没访问过且相加没有超出最大值
        {
            vis[i] = true; //修改访问状态
            DFS(ssum, i, depth + 1);
            vis[i] = false; //修改访问状态
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        for (int j = 0; j < M; j++)
            cin >> nums[j];

        memset(vis, false, sizeof(vis)); //重置访问数组
        sort(nums, nums + M);            //从小到大排序
        for (int i = 0; i < M - 1; i++)  //以每个数做起点进行DFS
        {
            vis[i] = true;
            DFS(nums[i], i, 1);
            vis[i] = false;
        }
        if (qu.empty()) //没有加法方程
            cout << "Can't find any equations." << endl;
        while (!qu.empty()) //输出加法方程
        {
            equation temp = qu.top();
            qu.pop();
            for (int i = 0; i < temp.len * 2 + 1; i++) //数字个数*2+1即为a的长度
                cout << temp.a[i];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}