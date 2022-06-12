/*
Sample Input
abcfbc abfcab
programming contest
abcd mnp

Sample Output
4
2
0
*/
#include <iostream>
#include <string>
#include <string.h>
#define maxn 300 // 200发现WA，300才AC
using namespace std;
string X, Y;
int counts[maxn][maxn];
int Count(int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (counts[n][m] != -1) //计算过
        return counts[n][m];
    if (X[n - 1] == Y[m - 1])
    {
        counts[n - 1][m - 1] = Count(n - 1, m - 1); //记忆
        return counts[n - 1][m - 1] + 1;
    }
    else
    {
        counts[n - 1][m] = Count(n - 1, m); //记忆
        counts[n][m - 1] = Count(n, m - 1); //记忆
        return counts[n - 1][m] > counts[n][m - 1] ? counts[n - 1][m] : counts[n][m - 1];
    }
}
int main()
{
    while (cin >> X >> Y)
    {
        memset(counts, -1, sizeof(counts)); //初始化
        cout << Count(X.size(), Y.size()) << endl;
    }
    return 0;
}