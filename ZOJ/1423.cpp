/*
Sample Input
3
(A-B + C) - (A+(B - C)) - (C-(D- E) )
((A)-( (B)))
A-(B+C)

Sample Output
A-B+C-(A+B-C)-(C-(D-E))
A-B
A-(B+C)
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;
void simplify(string s)
{

    stack<char> op;
    stack<char> val;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(') //左括号
        {
            //找与之匹配的右括号，计算它们之间的非括号个数
            int cnt = 0, j = i + 1;
            stack<char> temp;
            temp.push(s[i]);
            while (!temp.empty())
            {
                if (cnt > 1) //非括号个数大于1，不用继续了
                    break;

                if (s[j] == ')')
                    temp.pop();
                else if (s[j] == '(')
                    temp.push(s[j]);
                else if (s[j] != ' ') //非括号个数
                    cnt++;

                j++;
            }

            if (!op.empty() && op.top() == '-' && cnt > 1) //前面有 - 号，并且里面非仅有变量
            {
                cout << s[i]; //左括号要输出
                op.push('#'); //先进一个特殊符号
            }

            op.push(s[i]); //左括号直接进栈
        }
        else if (s[i] == '+' || s[i] == '-') //+ - 直接输出 并 进栈
        {
            cout << s[i];
            op.push(s[i]);
        }
        else if (s[i] == ')') //右括号
        {
            while (!op.empty()) //查看前面的，并把运算删掉
            {
                if (op.top() != '(') //非左括号运算符，直接删掉
                    op.pop();
                else //等于 ( 左括号了
                {
                    op.pop();                           //先删掉 ( 左括号
                    if (!op.empty() && op.top() == '#') //判断该左括号是否是之前输出的
                    {
                        cout << s[i]; //输出匹配的 ) 右括号
                        op.pop();     //删掉 # 特殊符号
                        op.pop();     //删掉 - 减号
                    }
                    break; //可以跳出循环了
                }
            }
        }
        else if (s[i] != ' ') //字母直接输出
            cout << s[i];
    }
    
    cout << endl;
}
int main()
{
    int M;
    while (cin >> M)
    {
        cin.get(); //吃掉一个换行
        string s;
        for (int i = 0; i < M; i++)
        {
            getline(cin, s);
            simplify(s);
        }
    }
    return 0;
}
