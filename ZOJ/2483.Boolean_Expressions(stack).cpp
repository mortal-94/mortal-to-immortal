//苦苦思索一大半天才做出来。。。

//首先要确定读到什么符号时进行计算，这里采用读到 V F ) 符号时进行计算，其他直接进栈
//需注意的是，一旦确定运算，就要算了无法再算，若非如此，尽管后续把运算值栈和操作符栈再操作一遍也会出错
//因为布尔表达式的运算顺序是从左到右，若前面有所保留，则后续会因栈的结构导致从右往左算，结果错误
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string s;               //存输入字符串
    int count = 1;          //记录次数
    while (getline(cin, s)) //整行读入
    {
        stack<bool> val; //存bool运算值
        stack<char> op;  //存运算操作符

        for (int i = 0; s[i] != '\0'; i++) //对每一个式子进行计算
        {
            if (s[i] == '(' || s[i] == '|' || s[i] == '&' || s[i] == '!') //读到 ( | & ! 直接进栈
                op.push(s[i]);
            else if (s[i] == 'V' || s[i] == 'F' || s[i] == ')') // 读到 V F ) 进行操作，注意此时只是字符串读到这些字符，栈里还没有
            {
                //确定运算值，是用当前读到的，还是用之前存好的
                bool b;
                if (s[i] != ')')                    //用当前读到的
                    b = s[i] == 'V' ? true : false; //转bool值
                else                                //用之前存好的
                {
                    b = val.top();
                    val.pop();
                }

                //运算，注意while循环，运算到不能再运算，即栈顶是 ( 并且当前读到的操作符不是 ) 或者 栈顶为空
                while (!op.empty())
                {
                    if (op.top() == '!')
                    {
                        b = !b;
                        op.pop();
                    }
                    else if (op.top() == '|')
                    {
                        bool pre = val.top();
                        val.pop();

                        b = pre | b;

                        op.pop();
                    }
                    else if (op.top() == '&')
                    {
                        bool pre = val.top();
                        val.pop();

                        b = pre & b;

                        op.pop();
                    }
                    else if (op.top() == '(') //判断是退出还是可以删掉继续，注意此时栈顶是 (，要么无法继续计算，要么就是 ) 匹配上了
                    {
                        if (s[i] == ')') //当前读到的操作符是) ，匹配上了，则可以把存好的(删掉
                        {
                            op.pop();
                            s[i] = '#'; //改掉s[i]，防止括号二次匹配
                        }
                        else
                            break;
                    }
                }

                //结果进栈
                val.push(b);
            }
        }
        // cout << op.size() << " " << val.size() << endl;

        //输出结果
        char ch = val.top() == true ? 'V' : 'F';
        val.pop();
        cout << "Expression " << count << ": " << ch << endl;
        count++;
    }
    return 0;
}

/*
//网上找到的做法，读到 | & ) 开始运算
#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    int kase = 1;
    while (getline(cin, s)) //整行读入
    {
        int x, y, c;
        stack<int> val; // int 类型
        stack<char> op; // 存操作符
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                op.push(s[i]);
                break;
            case '!':                               //注意如：！！！F,一开始没处理好RE了；！优先级高，放前面
                if (!op.empty() && op.top() == '!') // 非空，并且
                {
                    op.pop(); //注意！为单目运算符，一开始没处理好！
                }
                else
                    op.push(s[i]);
                break;
            case '|':
            case '&':
            case ')': // | 和 & 优先级相同 都会进入这里；  要清楚读到这三个其中之一时，它们还没有进栈。
                      // 读到一个操作符了，再确定是否进栈之前，要把前面的操作都做完。
                      // 做完后，栈里在 ( 之后就没有了|和&。
                      // 再判断读到的这个操作符是什么，如果是 ) ，就只需把此时的栈顶 ( 删掉即可
                      // 如果是 另外两个 则进栈。
                while (!op.empty())
                {
                    // 对上一个操作符进行判断，并操作
                    if (op.top() == '!')
                    {
                        x = val.top();
                        val.pop();
                        val.push((!x));
                        op.pop();
                    }
                    else if (op.top() == '|')
                    {
                        x = val.top();
                        val.pop();
                        y = val.top();
                        val.pop();
                        val.push((x | y));
                        op.pop();
                    }
                    else if (op.top() == '&')
                    {
                        x = val.top();
                        val.pop();
                        y = val.top();
                        val.pop();
                        val.push((x & y));
                        op.pop();
                    }
                    else
                        break;
                }
                if (s[i] == ')')
                    op.pop();
                else
                    op.push(s[i]);
                break;
            case 'V':
                val.push(1);
                break;
            case 'F':
                val.push(0);
                break;
            default:
                break;
            }
        }

        int test = 0;
        int test1 = 0;
        while (!op.empty())
        {
            test++;
            if (op.top() == '!')
            {
                test1++;
                x = val.top();
                val.pop();
                val.push((!x));
                op.pop();
            }
            else if (op.top() == '|')
            {
                x = val.top();
                val.pop();
                y = val.top();
                val.pop();
                val.push((x | y));
                op.pop();
            }
            else if (op.top() == '&')
            {
                x = val.top();
                val.pop();
                y = val.top();
                val.pop();
                val.push((x & y));
                op.pop();
            }
        }
        cout << op.size() << " " << val.size() << " " << test << " " << test1 << endl;
        // cout << val.size() << endl;
        // cout << op.size() << endl;
        printf("Expression %d: ", kase++);
        if (val.top() == 1)
            printf("V\n");
        else
            printf("F\n");
    }
    return 0;
}
//新运算符比栈顶元素优先级高，入栈否则栈顶元素出栈运算，
//直至栈顶元素运算符优先级低于要入栈的运算符或栈空；
*/