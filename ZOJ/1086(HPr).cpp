/*
SAMPLE INPUT
0.75
0.0001
0.01234567

SAMPLE OUTPUT
0.75 [8] = 0.953125 [10]
0.0001 [8] = 0.000244140625 [10]
0.01234567 [8] = 0.020408093929290771484375 [10]
*/
//相对于计算 Σ 0.125^(?)*val ，只是高精度数的 add 函数要随题改动(因为小数相加不同)
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
struct HPN
{
    short arr[100];
    short len;
    int lack;
    HPN()
    {
        memset(arr, 0, sizeof(arr));
        len = 0;
        lack = 0;
    }
    HPN add(const HPN h) const
    {
        HPN res;
        int carry = 0; //进位
        int j = 0;
        int i;
        if (len + lack >= h.len + h.lack)
        {
            res.len = len + lack;
            i = len + lack - h.len - h.lack;
            for (int k = 0; k < i; k++)
                res.arr[k] = arr[k];

            for (; i < res.len; i++, j++)
            {
                res.arr[i] = arr[i] + h.arr[j] + carry;
                carry = res.arr[i] / 10;
                res.arr[i] %= 10;
            }
        }
        else
        {
            res.len = h.len + h.lack;
            i = h.lack + h.len - len - lack;
            for (int k = 0; k < i; k++)
                res.arr[k] = h.arr[k];

            for (; i < res.len; i++, j++)
            {
                res.arr[i] = arr[j] + h.arr[i] + carry;
                carry = res.arr[i] / 10;
                res.arr[i] %= 10;
            }
        }

        while (carry != 0)
        {
            res.arr[i] = carry;
            carry = res.arr[i] / 10;
            i++;
        }
        return res;
    }
    HPN multiply(const HPN h) const
    {
        HPN res;
        res.len = len >= h.len ? 2 * len : 2 * h.len;
        //自己存进位
        for (int i = 0; i < len; i++) // arr[i]要乘所有的h.arr[j]
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
    HPN multiply(const short c) const
    {
        HPN res;
        res.len = len;
        int l, over = 0;
        for (l = 0; l < len; l++)
        {
            res.arr[l] = (arr[l] * c + over) % 10;
            over = (arr[l] * c + over) / 10;
        }
        while (over > 0)
        {
            res.arr[res.len] = over % 10;
            over = over / 10;
            res.len++;
        }
        return res;
    }
};
HPN convert(HPN h)
{
    HPN temp; // 0.125
    temp.arr[0] = 5;
    temp.arr[1] = 2;
    temp.arr[2] = 1;
    temp.len = 3;
    HPN sum;
    for (int i = 0; i < h.len; i++)
    {
        if (h.arr[i] != 0)
        {
            // 求1/8^(h.len-i)
            // 1/8=0.125
            HPN temp1;
            temp1.arr[0] = 1;
            temp1.len = 1;
            for (int j = 0; j < h.len - i; j++) // 0.125^(h.len-i)
                temp1 = temp1.multiply(temp);
            temp1 = temp1.multiply(h.arr[i]);         //乘当前值
            temp1.lack = (h.len - i) * 3 - temp1.len; //缺多少个0
            sum = sum.add(temp1);                     // add大改动
        }
    }
    return sum;
}
int main()
{
    string s;
    while (cin >> s)
    {
        //数据接受
        HPN cur;
        cur.len = s.size() - 2; //前面的'0.'不需要
        int i = cur.len - 1;
        int j = 2;           //前面的'0.'不需要
        while (s[j] != '\0') //倒序存储
            cur.arr[i--] = s[j++] - '0';
        //转换
        cur = convert(cur);
        //输出
        cout << s << " [8] = 0.";
        for (int i = cur.len - 1; i >= 0; i--)
            cout << cur.arr[i];
        cout << " [10]" << endl;
    }
    return 0;
}