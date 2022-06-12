/*
input
4
5 3
BBWBW
5 5
BBWBW
5 1
BBWBW
1 1
W

output
1
2
0
1
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int count_W = 0; //记录窗口内 W 的个数
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'W')
                count_W++;
        }
        // 滑动窗口 k  [leftIndex, rightIndex)
        int res = count_W;
        int leftIndex = 0;
        int rightIndex = k - leftIndex;
        // Out 代表出去的字母， s[rightIndex - 1] 代表进来的字母
        char Out = s[leftIndex];
        leftIndex++, rightIndex++;
        for (; rightIndex <= n; rightIndex++, leftIndex++)
        {
            if (Out != s[rightIndex - 1])
            {
                if (Out == 'W')
                    count_W--;
                else
                    count_W++;
            }
            // 更新出去的字母 以及 答案
            Out = s[leftIndex];
            res = res < count_W ? res : count_W;
        }
        cout << res << endl;
    }
}