/* S起始位置，#岩石，.空位，E出口
Sample Input  构成地牢的关卡数，构成每个级别的计划的行数和列数。

3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0


Sample Output  可以出、不可以出

Escaped in 11 minute(s).
Trapped!
*/

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int maxn = 30;
int L, R, C;
char dungeon[maxn][maxn][maxn]; //全局变量
int x_step[] = {1, -1, 0, 0, 0, 0};
int y_step[] = {0, 0, 1, -1, 0, 0};
int z_step[] = {0, 0, 0, 0, 1, -1}; //东南西北上下 六个方向

struct point //定义点结构体
{
    int x;
    int y;
    int z;
    int step;
};
bool vis[maxn][maxn][maxn];     //记录访问状态
int BFS(int sx, int sy, int sz) //传进开始位置
{
    memset(vis, false, sizeof(vis)); //重置访问状态数组
    queue<point> qu;
    point p = {sx, sy, sz, 0}; //结构体赋值小技巧
    qu.push(p);

    while (!qu.empty())
    {
        p = qu.front();
        qu.pop();
        // cout << p.x << " " << p.y << " " << p.z << endl;

        if (dungeon[p.x][p.y][p.z] == 'E') //终点，广度优先找到即为最短步数，直接返回即可
            return p.step;

        for (int i = 0; i < 6; i++) //六个方向广度优先搜索
        {
            int next_x = p.x + x_step[i];
            int next_y = p.y + y_step[i];
            int next_z = p.z + z_step[i];

            // 判断 是否是越界 是否访问过 是否可以走
            if (next_x >= 0 && next_y >= 0 && next_z >= 0 && next_x < R && next_y < C && next_z < L && !vis[next_x][next_y][next_z] && dungeon[next_x][next_y][next_z] != '#')
            {
                vis[next_x][next_y][next_z] = true; //修改访问状态
                point next = {next_x, next_y, next_z, p.step + 1};
                qu.push(next);
            }
        }
    }
    return -1; //无法找到返回-1
}

int main()
{
    while (cin >> L >> R >> C) // L R C输入
    {
        if (L == 0 && R == 0 && C == 0)
            break;

        memset(dungeon, '0', sizeof(dungeon)); //重置3D地牢数组
        int x, y, z;
        //接受输入数据，!!!!注意位置匹配
        for (int i = 0; i < L; i++) // z
        {
            for (int j = 0; j < R; j++) // x
            {
                for (int k = 0; k < C; k++) // y
                {
                    cin >> dungeon[j][k][i]; // j、k、i --- x、y、z --- R、C、L
                    if (dungeon[j][k][i] == 'S')
                    {
                        dungeon[j][k][i] = '#'; //修改为不可访问
                        x = j;
                        y = k;
                        z = i;
                    }
                }
            }
            cin.get(); //吃掉一个换行
        }

        int ans = BFS(x, y, z); //广度优先搜索函数调用
        if (ans == -1)          //没找到
            cout << "Trapped!" << endl;
        else //找到
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }

    return 0;
}