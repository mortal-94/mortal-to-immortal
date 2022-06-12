/*
Sample Input
4
3
1 2 3
3 2 1
3
1 2 3
1 2 3
3
1 2 1
1 2 1
3
1 2 3
2 3 1

Sample Output
stack
queue
both
neither
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    int T;
    while (cin >> T)
    {
        for (int j = 0; j < T; j++)
        {
            int N;
            cin >> N;
            stack<int> stk;
            queue<int> qu;
            int val;
            bool s = true;
            bool q = true;

            for (int i = 0; i < N; i++)
            {
                cin >> val;
                stk.push(val);
                qu.push(val);
            }
            for (int i = 0; i < N; i++)
            {
                cin >> val;
                if (val != stk.top())
                    s = false;
                if (val != qu.front())
                    q = false;
                stk.pop();
                qu.pop();
            }

            if (s && q)
                cout << "both" << endl;
            else if (s)
                cout << "stack" << endl;
            else if (q)
                cout << "queue" << endl;
            else
                cout << "neither" << endl;
        }
    }
    return 0;
}