/*
Sample Input
100

Sample Output
354224848179261915075
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
void print(int a[], int la)
{
    for (int i = la - 1; i >= 0; i--)
        cout << a[i];
    cout << endl;
}
const int maxsize = 5000;
int f[maxsize][1000]; //存储整个Fibonacci数列
int len[maxsize];     //对应每项的数字长度
int n, maxn = 2;      // maxn表示着当前已知的最大项数
int main()
{
    memset(f, 0, sizeof(f));     //数组置零
    memset(len, 0, sizeof(len)); //数组置零
    f[1][0] = f[2][0] = 1;
    len[1] = len[2] = 1; //定义起初两项

    while (cin >> n)
    {
        if (n > maxn) //超出了之前存储的最大项数
        {
            for (int i = maxn + 1; i <= n; i++)                                //算下去
                add(f[i - 2], len[i - 2], f[i - 1], len[i - 1], f[i], len[i]); // f_i=f_i-2 + f_i-1

            maxn = n; //记录当前存储的最大项数
        }

        print(f[n], len[n]); //打印结果
    }
    return 0;
}