/*
Sample Input
1 1 2 2
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

0 0 0 0

Sample Output
3
*/

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int checkerboard[8][8]; //棋盘
int si, sj, ei, ej;     //起始单元格和目标单元格的行号和列号
int x_step[] = {0, 1, 0, -1};
int y_step[] = {1, 0, -1, 0}; //四个方向
int mini[8][8][4];            //记录每个位置以每个状态到达的的最小成本
int mincost;
struct node
{
    int x, y, state, cost; //行、列、状态、！！总成本
};
int BFS()
{
    node p = {si, sj, 1, 0}; //机器人的初始状态是 1
    queue<node> qu;          //成本小的节点在前
    qu.push(p);

    while (!qu.empty())
    {
        p = qu.front();
        qu.pop();

        if (p.x == ei && p.y == ej && p.cost < mincost) //终点
            mincost = p.cost;

        for (int i = 0; i < 4; i++) //向4个方向搜索
        {
            int nx = p.x + x_step[i];
            int ny = p.y + y_step[i]; //移动的成本是 新单元格中的整数 与 其原始状态的乘积;  然后机器人的状态变为（成本 MOD 4 + 1）
            int nstate = (checkerboard[nx][ny] * p.state) % 4 + 1;
            int ncost = p.cost + checkerboard[nx][ny] * p.state;

            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || (mini[nx][ny][nstate - 1] && ncost >= mini[nx][ny][nstate - 1])) //越界 或者 大于之前记录的最小花费
                continue;
            else
            {
                mini[nx][ny][nstate - 1] = ncost; //更新最小花费
                qu.push(node{nx, ny, nstate, ncost});
            }
        }
    }
    return mincost;
}
int main()
{
    while (cin >> si >> sj >> ei >> ej && si != 0 && sj != 0 && ei != 0 && ej != 0)
    {
        --si, --sj, --ei, --ej; //输入减1
        memset(checkerboard, 0, sizeof(checkerboard));
        memset(mini, 0, sizeof(mini));
        mincost = 999999999;
        //数据输入
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                cin >> checkerboard[i][j];
        }
        cout << BFS() << endl;
        cin.get(); //吃掉一个换行，等待一组数据
    }
    return 0;
}