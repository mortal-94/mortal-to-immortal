#include <iostream>
#include <string.h>
#include <string>
#define maxn 5050
using namespace std;
class HPN
{
public:
    short arr[maxn];
    int len;
    HPN() //初始化
    {
        memset(arr, 0, sizeof(arr));
        len = 0;
    }
    HPN add(const HPN h) const //高精度数 + 高精度数
    {
        HPN res;
        res.len = len >= h.len ? len : h.len;

        int carry = 0; //进位
        for (int i = 0; i < res.len; i++)
        {
            res.arr[i] = arr[i] + h.arr[i] + carry;
            carry = res.arr[i] / 10;
            res.arr[i] %= 10;
        }
        while (carry != 0)
        {
            res.arr[res.len] = carry;
            carry = res.arr[res.len] / 10;
            res.len++;
        }
        return res;
    }

    HPN add(const int c) const //高精度数 + 正常数
    {
        HPN res;
        res.len = len >= 1 ? len : 1;

        res.arr[0] = arr[0] + c;
        int carry = res.arr[0] / 10; //进位
        res.arr[0] %= 10;
        for (int i = 1; i < res.len; i++)
        {
            res.arr[i] = arr[i] + carry;
            carry = res.arr[i] / 10;
            res.arr[i] %= 10;
        }
        while (carry != 0)
        {
            res.arr[res.len] = carry;
            carry = res.arr[res.len] / 10;
            res.len++;
        }
        return res;
    }

    HPN multiply(const HPN h) const //高精度数 * 高精度数
    {
        HPN res;
        res.len = len >= h.len ? 2 * len : 2 * h.len;
        //自己存进位
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < h.len; j++)
            {
                res.arr[i + j] = res.arr[i + j] + arr[i] * h.arr[j];           //逐位计算
                res.arr[i + j + 1] = res.arr[i + j + 1] + res.arr[i + j] / 10; //进位处理
                res.arr[i + j] %= 10;
            }
        }
        while (res.arr[res.len - 1] == 0 && res.len > 1)
            res.len--;
        return res;
    }

    HPN divide(const int c) const //高精度数 / 正常数
    {
        HPN res;
        res.len = len;
        int m = 0; //余数零
        for (int i = len - 1; i >= 0; i--)
        {
            res.arr[i] = arr[i] + m * 10;
            m = res.arr[i] % c;
            res.arr[i] /= c;
        }
        while (res.arr[res.len - 1] == 0 && res.len > 1)
            res.len--;
        return res;
    }

    HPN sub(const HPN h) const //高精度数 - 高精度数（注意不能处理负数）
    {
        HPN res;
        res.len = len;
        short temp[maxn];
        memcpy(temp, arr, sizeof(arr));
        for (int i = 0; i < res.len; i++)
        {
            if (temp[i] < h.arr[i]) //借位
            {
                temp[i + 1]--;
                temp[i] = temp[i] + 10;
            }
            res.arr[i] = temp[i] - h.arr[i];
        }
        while (res.arr[res.len - 1] == 0 && res.len > 1)
            res.len--;
        return res;
    }
} C[105][105], ans[105];
void createC() //制作组合数
{
    for (int i = 0; i < 102; i++)
    {
        C[i][0].arr[0] = C[i][i].arr[0] = 1;
        C[i][0].len = C[i][i].len = 1;

        if (i == 0)
            continue;

        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j].add(C[i - 1][j - 1]); //利用组合数递推公式
    }
}

HPN solve(HPN n, int k)
{
    if (ans[k].len != 0) //之前计算过
        return ans[k];
    if (k == 1) //递归结束
    {
        ans[k] = (n.add(1).multiply(n).divide(2));
        return ans[k];
        // return (n.add(1).multiply(n).divide(2));
    }

    HPN temp;
    temp = temp.add(1);
    for (int i = 0; i < k + 1; i++) //(n+1)^{k+1}
        temp = temp.multiply(n.add(1));
    temp = temp.sub(n.add(1)); //(n+1)^{k+1} - (n+1)

    HPN sum;
    for (int i = 1; i < k; i++)
    {
        HPN t = C[k + 1][i].multiply(solve(n, k - i)); //递归
        sum = sum.add(t);
    }
    ans[k] = (temp.sub(sum).divide(k + 1));
    return ans[k];
    // return (temp.sub(sum).divide(k + 1));
}

int main()
{
    createC(); //制作组合数
    string s;
    while (cin >> s)
    {
        memset(ans, 0, sizeof(ans)); //重置

        //输入处理
        int k;
        cin >> k;
        if (s[0] == '0') //特殊判断
        {
            cout << 0 << endl;
            continue;
        }

        HPN n;
        n.len = s.size();
        int i = 0;
        while (s[n.len - i - 1] != '\0') //倒序存储
        {
            n.arr[i] = s[n.len - i - 1] - '0';
            i++;
        }
        //计算
        HPN res = solve(n, k);
        for (int i = res.len - 1; i >= 0; i--)
            cout << res.arr[i];
        cout << endl;
    }
    return 0;
}