/*
Sample Input
7 8
#.#####.
#.a#..r.
#..#x...
..#..#.#
#...##..
.#......
........
7 8
#.#####.
#a.#xr..
#.x#xx..
..xxxx.#
#.......
.#......
........

Sample Output
13
12
*/

//------广度优先搜索+优先队列数据结构-----
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int x_step[] = {0, 1, 0, -1};
int y_step[] = {1, 0, -1, 0}; //四个方向
int N, M;                     //行列边界
char prison[200][200];        //监狱地图

struct point //定义结构体
{
    int x, y, step;
    bool operator<(const point p) const // step小的在前面
    {
        return step > p.step;
    }
};
int BFS(int si, int sj)
{
    priority_queue<point> qu; //优先队列，step小的在前
    point p = {si, sj, 0};
    prison[si][sj] = '#'; //修改访问状态
    qu.push(p);

    while (!qu.empty())
    {
        p = qu.top();
        qu.pop();

        for (int i = 0; i < 4; i++) //四个方向搜索
        {
            int next_x = p.x + x_step[i];
            int next_y = p.y + y_step[i];

            if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M || prison[next_x][next_y] == '#') //越界、访问过、墙
                continue;
            else if (prison[next_x][next_y] == 'x') //守卫
                qu.push(point{next_x, next_y, p.step + 2});
            else if (prison[next_x][next_y] == '.') //道路
                qu.push(point{next_x, next_y, p.step + 1});
            else //天使
                return ++p.step;

            prison[next_x][next_y] = '#'; //修改访问状态
        }
    }
    return -1;
}
int main()
{
    while (cin >> N >> M)
    {
        //输入数据存储
        int si, sj;
        memset(prison, '0', sizeof(prison)); //重置监狱
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> prison[i][j];
                if (prison[i][j] == 'r') //记录起始位置
                {
                    si = i;
                    sj = j;
                }
            }
        }
        int minstep = BFS(si, sj);
        if (minstep == -1)
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        else
            cout << minstep << endl;
    }

    return 0;
}