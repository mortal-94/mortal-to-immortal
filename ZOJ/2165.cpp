/*
Sample Input
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0

Sample Output
45
59
6
13
*/

#include <iostream>
#include <string.h>
using namespace std;
int x_step[] = {0, 1, 0, -1};
int y_step[] = {1, 0, -1, 0}; //四个方向
char room[20][20];
int W, H; //列、行
int counts = 0;
bool vis[20][20]; //记录是否走过

void DFS(int si, int sj)
{
    //越界、不能走、走过
    if (si < 0 || si >= H || sj < 0 || sj >= W || room[si][sj] == '#' || vis[si][sj])
        return;

    vis[si][sj] = true; //改为访问过
    counts++;           //块数加一

    //四个方向搜索
    for (int i = 0; i < 4; i++)
        DFS(si + x_step[i], sj + y_step[i]);
}
int main()
{
    while (cin >> W >> H && W != 0 && H != 0)
    {
        //数据输入
        int si, sj; //开始位置
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> room[i][j];
                if (room[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        //初始化
        memset(vis, false, sizeof(vis));
        counts = 0;
        //搜索
        DFS(si, sj);
        //输出
        cout << counts << endl;
    }
    return 0;
}