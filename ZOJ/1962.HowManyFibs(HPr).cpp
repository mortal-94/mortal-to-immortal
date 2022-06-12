/*
Sample Input
10 100
1234567890 9876543210
0 0

Sample Output
5
4
*/

//高精度问题 High Precision
#include <iostream>
#include <string.h>
using namespace std;
void add(int a[], int la, int b[], int lb, int c[], int &lc) // c=a+b
{
    int carry = 0;               //进位数
    for (int i = 0; i < lb; i++) //先得出对应位数相加再 + 进位数 的和、再计算下一个进位数、再把当前格改回一位数
    {
        c[i] = b[i] + a[i] + carry; //当前格 是两数当前格的 和 + 进位数
        carry = c[i] / 10;          //得到下一个进位
        c[i] %= 10;                 //当前格取个位数
    }
    lc = lb; //记录当前长度
    //两数相加，进位数最大是1，if即可
    if (carry > 0) //还有在进位时
    {
        c[lc] = 1;
        lc++;
    }
}
int Greater(int a[], int la, int b[], int lb) // a>b返回1，a<b返回0，a=b返回2
{
    if (la > lb)
        return 1;
    else if (la < lb)
        return 0;

    for (int i = la - 1; i >= 0; i--)
    {
        if (a[i] < b[i])
            return 0;
        else if (a[i] > b[i])
            return 1;
    }
    //相等返回2
    return 2;
}

const int maxsize = 5000;
int f[maxsize][1000]; //存储整个Fibonacci数列
int len[maxsize];     //对应每项的数字长度
int n;
int main()
{
    memset(f, 0, sizeof(f));     //数组置零
    memset(len, 0, sizeof(len)); //数组置零
    f[1][0] = f[2][0] = 1;
    len[1] = len[2] = 1; //定义起初两项
    //算好前500项
    for (int i = 3; i < 500; i++)
        add(f[i - 2], len[i - 2], f[i - 1], len[i - 1], f[i], len[i]); // f_i=f_i-2 + f_i-1

    char stra[101]; //接受输入的数组
    char strb[101]; //接受输入的数组
    int a[101];     //存存入的数组
    int b[101];     //存存入的数组
    while (cin >> stra >> strb && strb[0] != '0')
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b)); //重置a，b
        int la = strlen(stra);
        int lb = strlen(strb); //取出长度
        //逆置存储
        for (int i = 0; i < la; i++)
            a[la - i - 1] = stra[i] - '0';
        for (int i = 0; i < lb; i++)
            b[lb - i - 1] = strb[i] - '0';

        //遍历数列
        int nums = 0;
        for (int i = 2; i < 500; i++)
        {
            if (Greater(f[i], len[i], a, la)) // f[i]>=a
                nums++;
            if (Greater(f[i], len[i], b, lb) == 1) // f[i]>b
            {
                nums--;
                break;
            }
            if (Greater(f[i], len[i], b, lb) == 2) // f[i]=b
                break;
        }
        cout << nums << endl;
    }
    return 0;
}
