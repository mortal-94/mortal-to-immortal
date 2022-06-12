#include <iostream>
#include <queue>
using namespace std;
struct message
{
    char msg[10];
    int parm;
    int prio;
};
bool operator<(const message &a, const message &b) //自定义数据的优先队列排序方式
{
    return a.prio > b.prio;
}
int main()
{
    priority_queue<message> q; //默认升序
    char str[30];
    while (cin.getline(str, 30))
    {
        if (str[0] == 'P')
        {
            message m;
            int i = 4;
            for (; str[i] != ' '; i++)
                m.msg[i - 4] = str[i];
            m.msg[i - 4] = '\0';

            i++;
            int num = 0; //读出字符串转数字
            for (; str[i] != ' '; i++)
            {
                num *= 10;
                num += str[i] - '0';
            }
            m.parm = num;

            i++;
            num = 0; //读出字符串转数字
            for (; str[i] != '\0'; i++)
            {
                num *= 10;
                num += str[i] - '0';
            }
            m.prio = num;

            q.push(m);
        }
        else if (str[0] == 'G')
        {
            if (q.empty())
                cout << "EMPTY QUEUE!" << endl;
            else
            {
                message m = q.top();
                q.pop();
                cout << m.msg << " " << m.parm << endl;
            }
        }
    }
    return 0;
}
