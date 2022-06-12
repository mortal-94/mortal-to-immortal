/*
Sample Input
5
2
3
5
7
12
5
2
16
64
256
1024
0

Output for Sample Input
12
no solution
*/

#include <iostream>
#include <algorithm>
using namespace std;
int amount[1005];
int n;
bool find(int num) //应用二分查找
{
    int L = 0, R = n - 1;
    while (L <= R)
    {
        int mid = L + ((R - L) >> 1); //求中点
        if (num == amount[mid])       //找到
            return true;
        else if (num < amount[mid]) //找左边
            R = mid - 1;
        else //找右边
            L = mid + 1;
    }
    return false; //没找到
}
int main()
{
    while (cin >> n && n != 0)
    {
        bool flag = false; //找到的标志
        for (int i = 0; i < n; i++)
            cin >> amount[i];
        sort(amount, amount + n); //升序排序

        for (int i = n - 1; i >= 0; i--) //从后开始
        {
            for (int j = n - 1; j >= 0; j--) //注意因为有负数，所以还是要遍历所有
            {
                if (i == j) //避免同一个
                    continue;

                int sub = amount[i] - amount[j]; //记录差值
                for (int k = n - 1; k >= 0; k--)
                {
                    if (i == k || j == k) //避免同一个
                        continue;

                    int num = sub - amount[k]; //再记录差值

                    if (num == amount[i] || num == amount[j] || num == amount[k]) //题目已说明无重复金额
                        continue;
                    if (find(num))
                    {
                        cout << amount[i] << endl;
                        flag = true; //找到了
                        break;
                    }
                }
                if (flag) //查看是否找到
                    break;
            }
            if (flag) //查看是否找到
                break;
        }
        if (!flag) //没找到
            cout << "no solution" << endl;
    }
}
