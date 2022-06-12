/*
Sample Input
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))

Sample Output
0
0
0
error
10000
error
3500
15000
40500
47500
15125
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int n; //矩阵个数
struct mat
{
    int row; //行
    int col; //列
} mats[26];
int func(string s) //进一个矩阵或者运算完进一个*，遇到)删掉多余的一个*再进行运算
{
    stack<mat> stk;
    stack<char> op;
    int i = 0;
    int res = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(') //左括号直接进栈
            op.push(s[i]);
        else //读到右括号和矩阵开始计算
        {
            //确定后者
            mat latter;
            if (s[i] == ')') //右括号：后者在栈里面，并且前面还有一个多余的*
            {
                op.pop(); //删掉*
                latter = stk.top();
                stk.pop();
            }
            else //矩阵：后者就是当前读到的矩阵
                latter = mats[s[i] - 'A'];
            //运算
            while (!op.empty() && !stk.empty()) //运算符不为空，矩阵也不为空(因为会有只有一个矩阵的计算式)
            {
                if (op.top() == '(') //操作符是左括号，寻找匹配
                {
                    if (s[i] == ')') //匹配
                    {
                        op.pop();   //删掉左括号
                        s[i] = '#'; //防止二次匹配
                    }
                    else //无法匹配跳出while循环
                        break;
                }
                else //操作符是*号
                {
                    mat former = stk.top();
                    stk.pop();
                    if (former.col != latter.row) //不可运算
                        return -1;
                    else
                    {
                        op.pop();                                    //删掉一个*号
                        res += former.row * latter.col * latter.row; //基本乘法数
                        latter.row = former.row;                     //运算后矩阵变化
                    }
                }
            }
            //进栈，进一个矩阵，进一个*
            stk.push(latter);
            op.push('*');
        }
        i++;
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mat temp;
        char name;
        cin >> name >> temp.row >> temp.col;
        mats[name - 'A'] = temp;
    }
    cin.get(); //吃掉换行符
    string s;
    while (getline(cin, s) && !s.empty())
    {
        int res = func(s);
        if (res == -1)
            cout << "error" << endl;
        else
            cout << res << endl;
    }
    return 0;
}