/*
Sample Input
5
0 0
0 1
0.5 0.5
1 1
1 0
4
0 0
0 1
1 0
1 1
0

Output for the Sample Input
Figure 1: 0.75
Figure 2: Impossible
*/

#include <iostream>
#include <iomanip> //保留两位小数
using namespace std;
struct point
{
    float x;
    float y;
} v[1002];
int n;

double slove()
{
}

int main()
{
    int cnt = 0;
    while (cin >> n && n != 0)
    {
        cnt++;
        //特殊判断
        if (n < 3)
            cout << "Figure " << cnt << ": Impossible" << endl;
        //存储数据
        for (int i = 0; i < n; i++)
            cin >> v[i].x >> v[i].y;
        
        // cout<<setiosflags(ios::fixed)<<
    }
    return 0;
}