/*
Sample Input
2
7 AGTGATG
5 GTTAG
7 AGCTATT
9 AGCTTTAAA

Output for the Sample Input
14
21
*/

#include <iostream>
#include <map>
#include <string.h>
#define maxn 105
using namespace std;
int T, l1, l2;
char s1[maxn], s2[maxn];
map<char, int> m;    // DNA字母对于数字
int Score[5][5];     //存积分表
int ans[maxn][maxn]; //为递归记忆化
void init()          //制表
{
    m['A'] = 0, m['C'] = 1, m['G'] = 2, m['T'] = 3, m['-'] = 4;

    Score[m['A']][m['A']] = 5, Score[m['A']][m['C']] = -1,
    Score[m['A']][m['G']] = -2, Score[m['A']][m['T']] = -1, Score[m['A']][m['-']] = -3;

    Score[m['C']][m['A']] = -1, Score[m['C']][m['C']] = 5,
    Score[m['C']][m['G']] = -3, Score[m['C']][m['T']] = -2, Score[m['C']][m['-']] = -4;

    Score[m['G']][m['A']] = -2, Score[m['G']][m['C']] = -3,
    Score[m['G']][m['G']] = 5, Score[m['G']][m['T']] = -2, Score[m['G']][m['-']] = -2;

    Score[m['T']][m['A']] = -1, Score[m['T']][m['C']] = -2,
    Score[m['T']][m['G']] = -2, Score[m['T']][m['T']] = 5, Score[m['T']][m['-']] = -1;

    Score[m['-']][m['A']] = -3, Score[m['-']][m['C']] = -4,
    Score[m['-']][m['G']] = -2, Score[m['-']][m['T']] = -1, Score[m['-']][m['-']] = 0;
}
int f(int i, int j)
{
    if (ans[i][j] < 520) //记录过
        return ans[i][j];
    if (i == 0 && j == 0)
        return 0;
    if (j == 0)
    {
        ans[i][j] = f(i - 1, 0) + Score[m[s1[i - 1]]][4]; //记录
        return ans[i][j];
    }
    if (i == 0)
    {
        ans[i][j] = f(0, j - 1) + Score[4][m[s2[j - 1]]]; //记录
        return ans[i][j];
    }

    int sco1 = f(i - 1, j) + Score[m[s1[i - 1]]][4];                //消除s1[i-1]字母会得分数
    int sco2 = f(i, j - 1) + Score[4][m[s2[j - 1]]];                //消除s2[j-1]字母会得分数
    int sco3 = f(i - 1, j - 1) + Score[m[s1[i - 1]]][m[s2[j - 1]]]; //消除s1[i-1]和s2[j-1字母会得分数

    ans[i][j] = max(max(sco1, sco2), sco3); //记录最大分数
    return ans[i][j];                       //返回最大分数
}
int main()
{
    init(); //制表
    while (cin >> T)
    {
        for (int i = 0; i < T; i++)
        {
            //重置，赋予很大的值，超过了520（这里f返回值顶多就是500
            memset(ans, 1, sizeof(ans));
            //输入
            cin >> l1;
            for (int j = 0; j < l1; j++)
                cin >> s1[j];
            cin >> l2;
            for (int j = 0; j < l2; j++)
                cin >> s2[j];
            //输出
            cout << f(l1, l2) << endl;
        }
    }
}