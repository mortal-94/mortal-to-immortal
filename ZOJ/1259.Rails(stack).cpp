/*
Sample Input
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0

Sample Output
Yes
No

Yes
*/

#include <iostream>
#include <stack>
using namespace std;
int N; //要出的车厢个数
int arr[1000];
int main()
{
    while (cin >> N && N != 0)
    {
        while (cin >> arr[0] && arr[0] != 0)
        {
            for (int i = 1; i < N; i++)
                cin >> arr[i];
            stack<int> stk;
            int cur = 1; //从1开始
            int i = 0;   //数组的索引
            while (i < N)
            {
                if (arr[i] == cur) //不用进栈，车厢刚进直接出去
                {
                    cur++; //下一个来的车厢
                    i++;   //下一个要出的车厢
                }
                else //来的不是想要出的车厢
                {
                    if (arr[i] < cur) //但想要出的车厢已经在车站里面了，那来的先别管
                    {
                        if (!stk.empty() && stk.top() == arr[i]) //看一下车站最外面的是否为要出的车厢
                        {
                            stk.pop(); //出去
                            i++;       //下一个要出的车厢
                        }
                        else //要出的车厢塞在了里面，出不来
                            break;
                    }
                    else //想要出的车厢还没来过
                    {
                        stk.push(cur); //当前的车厢留在车站
                        cur++;         //下一个车厢来
                    }
                }
            }
            if (i == N) //全部出去了
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}