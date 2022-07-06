// 计算多项式
#include <iostream>
#include <ctime>
#include <cmath>
#define MAX 100  //项数-1
#define MAXX 1e6 //次数
using namespace std;
// 计算函数父类
class Function
{
public:
    double a[MAX + 1]; //系数
    double m_val;

    virtual void noname(int n, double x) = 0;
    virtual void print123() = 0;
    // 构造系数
    Function()
    {
        a[0] = 1;
        for (int i = 1; i <= MAX; i++)
            a[i] = 1.0 / double(i);
    }
};

// 计算方法一
class Function1 : public Function
{
public:
    void noname(int n, double x)
    {
        int i;
        double p = a[0];
        for (i = 1; i <= n; i++)
        {
            p += a[i] * pow(x, i);
        }
        m_val = p;
    }
    void print123()
    {
        cout << "Function1-val = " << m_val << endl;
    }
};
// 计算方法二
class Function2 : public Function
{
public:
    void noname(int n, double x)
    {
        int i;
        double p = a[n];
        for (i = n; i > 0; i--)
        {
            p = a[i - 1] + x * p;
        }
        m_val = p;
    }
    void print123()
    {
        cout << "Function2-val = " << m_val << endl;
    }
};

// 计时函数
void timeCalculate(Function *f, int n, double x)
{
    clock_t start, stop;
    double duration;
    start = clock();
    for (int i = 0; i < MAXX; i++)
        f->noname(n, x);
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    cout << "duration: " << duration << endl;
    f->print123();
}


int main()
{
    Function *f1 = new Function1;
    Function *f2 = new Function2;
    double x = 1.1;
    timeCalculate(f1, MAX, x);
    cout << "------------------------" << endl;
    timeCalculate(f2, MAX, x);
    delete f1;
    delete f2;
    return 0;
}