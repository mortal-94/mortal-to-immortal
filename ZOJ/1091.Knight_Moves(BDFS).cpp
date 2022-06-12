/*国际象棋中knight的行走规则是走对角线
Sample Input
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
Sample Output
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
*/

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int x_step[] = {1, 1, 2, 2, -1, -1, -2, -2}; //骑士是对角线行走
int y_step[] = {2, -2, 1, -1, 2, -2, 1, -1}; //注意对应

struct point //定义点结构体
{
    int x;
    int y;
    int step;
};
point path[8][8]; // 每个位置记着前一个位置

int min_step[8][8]; //棋盘分布数组，记录每个位置的最小步数（确定了起始位置
void DFS(int si, int sj, int moves, int prex, int prey)
{
    //边界越界以及非最小步数终止
    if (si < 0 || sj < 0 || si >= 8 || sj >= 8 || moves >= min_step[si][sj])
        return;

    min_step[si][sj] = moves; //用一个数组记录每一位置走的最少步数

    path[si][sj].x = prex;
    path[si][sj].y = prey; //记录前一个位置

    //分别向这8个方向搜索，步数+1
    for (int i = 0; i < 8; i++)
        DFS(si + x_step[i], sj + y_step[i], moves + 1, si, sj);
}

int BFS(int si, int sj, int ei, int ej)
{

    bool vis[8][8];                  //记录该位置是否访问过
    memset(vis, false, sizeof(vis)); //刚开始都没有访问过，整体赋值false
    queue<point> qu;
    point p = {si, sj, 0}; //结构体赋值小技巧

    qu.push(p);
    while (!qu.empty())
    {
        p = qu.front();
        qu.pop();

        if (p.x == ei && p.y == ej) //找到终点，注意广度优先找到即为最小步数
            return p.step;

        for (int i = 0; i < 8; i++)
        {
            int next_x = p.x + x_step[i];
            int next_y = p.y + y_step[i];
            // 判断是否是越界 是否访问过
            if (next_x >= 0 && next_y >= 0 && next_x < 8 && next_y < 8 && !vis[next_x][next_y])
            {
                vis[next_x][next_y] = true;                //修改访问状态
                point next = {next_x, next_y, p.step + 1}; //结构体赋值小技巧
                qu.push(next);

                path[next_x][next.y].x = p.x;
                path[next_x][next.y].y = p.y; //记录前一个位置
            }
        }
    }
    return -1; //无法找到返回-1
}

void PrintPath(int x, int y) //打印路径的函数
{
    if (x == -1 && y == -1)
        return;

    PrintPath(path[x][y].x, path[x][y].y);
    cout << "(" << char(x + 'a') << "," << y + 1 << ") ";
}

int main()
{
    char s[10];
    char start[5], end[5];
    while (cin.getline(s, 10))
    {
        for (int i = 0; i < 2; i++) //输入数据处理
        {
            start[i] = s[i];
            end[i] = s[i + 3];
        }
        start[2] = end[2] = '\0';

        // memset(min_step, 100, sizeof(min_step));        //重置数组，还不清楚这个函数的使用，反正这句实现了数组整体赋值，一个较大的值，却不是100
        // DFS(start[0] - 'a', start[1] - '1', 0, -1, -1); //深度搜索
        // cout << "To get from " << start << " to " << end << " takes "
        //      << min_step[end[0] - 'a'][end[1] - '1'] << " knight moves." << endl;

        cout << "To get from " << start << " to " << end << " takes "
             << BFS(start[0] - 'a', start[1] - '1', end[0] - 'a', end[1] - '1')
             << " knight moves." << endl;

        //打印路径
        // path[start[0] - 'a'][start[1] - '1'].x = -1;
        // path[start[0] - 'a'][start[1] - '1'].y = -1; //开始位置记录着特殊值-1，-1
        // cout << "Thr Path is: ";
        // PrintPath(end[0] - 'a', end[1] - '1'); //打印路径
        // cout << endl;
    }
}