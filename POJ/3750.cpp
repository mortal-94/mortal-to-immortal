#include <iostream>
using namespace std;
struct ListNode
{
    char name[15];
    struct ListNode *next;
};
ListNode *Create_List(int n) //制作链表
{
    ListNode *head, *tail, *p;
    head = tail = new ListNode;
    tail->next = 0;
    for (int i = 0; i < n; i++)
    {
        p = new ListNode;
        cin >> p->name;
        p->next = 0;

        tail->next = p;
        tail = p;
    }
    tail->next = head->next;
    return tail;
}
int main()
{
    int N;
    cin >> N;
    ListNode *ptr = Create_List(N);
    ListNode *p = ptr->next; // p指向了第一个数据

    int W, S;
    cin >> W;
    if (cin.get() == ',') //输入W,S (W < N)，用逗号","间隔
        cin >> S;

    for (int i = 1; i < W; i++) //搜索到起始号，从1开始循环
    {
        ptr = p;     // ptr在p之前一个
        p = p->next; // p指向了起始号
    }
    while (ptr != p)
    {
        for (int i = 1; i < S; i++) //从1开始循环
        {
            ptr = p;
            p = p->next; // p指向了要删除的号
        }
        cout << p->name << endl;
        ptr->next = p->next;
        delete p;
        p = ptr->next;
    }
    cout << p->name << endl;

    return 0;
}