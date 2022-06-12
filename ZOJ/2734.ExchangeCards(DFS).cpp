/*
Sample Input
5 2
2 1
3 1
10 5
10 2
7 2
5 3
2 2
1 5
Sample Output
1

7
*/

//无序问题，DFS剪枝
#include <iostream>
using namespace std;
int n, m;   //计划价值、卡片种类个数
struct card //卡片数据结构
{
    int val;
    int num;
} cards[10];
int cnt = 0;
void DFS(int val, int pre) //当前得到的价值，前一张卡片
{
    for (int i = pre; i < m; i++) //从前一张片开始（防止重复
    {
        if (cards[i].num) //该张卡片还有
        {
            int newval = val + cards[i].val; //新的价值
            if (newval > n)                  //超出了计划价值
                continue;
            if (newval == n) //得到目标值
            {
                cnt++;
                continue;
            }
            cards[i].num--; //卡片消耗一张
            DFS(newval, i); //继续搜索
            cards[i].num++; //这条路径搜完恢复消耗的卡片
        }
    }
}
int main()
{
    int flag = 0;
    while (cin >> n >> m)
    {
        //注意格式
        if (flag)
            cout << endl;
        flag = 1;

        for (int i = 0; i < m; i++)
        {
            cin >> cards[i].val; //卡片种类
            cin >> cards[i].num; //该种卡片的数量
        }
        cnt = 0; //重置
        DFS(0, 0);
        cout << cnt << endl;
    }
    return 0;
}