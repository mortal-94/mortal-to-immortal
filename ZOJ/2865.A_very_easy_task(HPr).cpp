/*
\Sigma_1^n i^k (1 <= i <= n).
Sample Input:
2 3
3 2
Sample Output:
9
14
*/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int k;
// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
struct HPN
{
    short arr[5100];
    int len;
    bool operator<=(const HPN &a) const
    {
        if (len < a.len)
            return true;
        else if (len > a.len)
            return false;
        else
        {
            for (int i = len - 1; i >= 0; i--)
            {
                if (arr[i] > a.arr[i])
                    return false;
            }
            return true;
        }
    }
    HPN operator*(int c) //高精度数*常数
    {
        HPN res;
        int carry = 0; //进位
        for (int i = 0; i < len; i++)
        {
            res.arr[i] = (arr[i] * c + carry) % 10;
            carry = (arr[i] * c + carry) / 10;
        }
        res.len = len;
        while (carry > 0)
        {
            res.arr[len] = carry % 10;
            carry = carry / 10;
            res.len++;
        }

        return res;
    }
    HPN operator*(HPN a) //高精度数相乘
    {
        HPN res;
        int maxn = len > a.len ? len : a.len;
        for (int i = 0; i < 2 * maxn; i++)
            res.arr[i] = 0; //初始化
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < a.len; j++)
            {
                res.arr[i + j] = res.arr[i + j] + arr[i] * a.arr[j];
                res.arr[i + j + 1] = res.arr[i + j + 1] + res.arr[i + j] / 10;
                res.arr[i + j] = res.arr[i + j] % 10;
            }
        }
        res.len = 2 * maxn;
        while (res.arr[res.len - 1] == 0)
            res.len--;

        return res;
    }
    HPN pow(int k) // k次方
    {
        //初始化一个最终答案
        HPN fin;
        fin.len = len * k;
        // copy一份arr
        HPN temp;
        memcpy(temp.arr, arr, sizeof(arr));
        // k次方
        while (--k) // k-1次循环
        {
            memset(fin.arr, 0, sizeof(fin.arr)); //每次都初始化

            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len; j++)
                {
                    fin.arr[i + j] = temp.arr[i] * arr[j] + fin.arr[i + j];        //两数相乘加进位
                    fin.arr[i + j + 1] = fin.arr[i + j + 1] + fin.arr[i + j] / 10; //新的进位
                    fin.arr[i + j] = fin.arr[i + j] % 10;                          //变回个位数
                }
            }

            memcpy(temp.arr, fin.arr, sizeof(arr)); // temp改变
        }
        //实际长度
        while (fin.arr[fin.len - 1] == 0)
            fin.len--;
        //返回最终答案
        return fin;
    }
    HPN operator+(int c) //加一个常数
    {
        HPN res;
        res.len = len;
        int i = 0;
        res.arr[i] += c;
        int carry = 0;
        while (arr[i] >= 10) //加1了之后大于等于10
        {
            if (i == res.len)
            {
                res.len++;
                res.arr[i] = 0;
            }
            res.arr[i] += carry;
            carry = res.arr[i] / 10; //进位
            res.arr[i] %= 10;
            i++;
        }
        return res;
    }
    void add(HPN a) //加一个高精度数
    {
        int maxn = len >= a.len ? len : a.len;
        for (int i = 0; i < maxn; i++)
        {
            arr[i] = arr[i] + a.arr[i];
            arr[i + 1] = arr[i + 1] + arr[i] / 10;
            arr[i] = arr[i] % 10;
        }
        while (arr[maxn] != 0)
            maxn++;
        len = maxn;
    }
    HPN operator/(int c) //除一个常数
    {
        HPN res;
        int mod = 0; //余数
        for (int i = len - 1; i >= 0; i--)
        {
            res.arr[i] = (mod * 10 + arr[i]) / c;
            mod = (mod * 10 + arr[i]) % c;
        }
        res.len = len;
        while (res.arr[res.len - 1] == 0)
            res.len--;
        return res;
    }
    void sub(HPN a) //减掉一个高精度数
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i] < a.arr[i])
            {
                arr[i + 1]--;
                arr[i] = arr[i] + 10;
            }
            arr[i] = arr[i] - a.arr[i];
        }
        while (arr[len - 1] == 0)
            len--;
    }
} n, res, temp;

HPN S(HPN n, int i) //递归求和
{
    if (i == 1)
        return n * (n + 1) / 2;
    temp.add(S(n * nCr(k + 1, k - i + 2), i - 1));
    return temp;
}
int main()
{
    string s;
    while (cin >> s)
    {
        //输入处理
        cin >> k;
        n.len = s.size();
        int i = 0;
        while (s[n.len - i - 1] != '\0')
        {
            n.arr[i] = s[n.len - i - 1] - '0';
            i++;
        }
        //计算
        //初始化
        res.len = 0;
        memset(res.arr, 0, sizeof(res.arr));
        memset(temp.arr, 0, sizeof(temp.arr));
        res.add((n + 1).pow(k + 1));
        res.sub(S(n, k));
        res = res / (k + 1);

        for (int i = res.len - 1; i >= 0; i--)
            cout << res.arr[i];
        cout << endl;
    }
    return 0;
}