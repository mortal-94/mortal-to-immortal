/*
Sample Input
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

Sample Output
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA
*/

//链表的递归方法使用，注意POJ无法识别nullptr
#include <iostream>
using namespace std;
int n, m; //全局变量
struct node
{
    char DNA[50];
    int num; //记录排序度，该数越小，说明排序性越高
    node *next;
};

//链表创建要用的函数
int solve(char dna[]) //求解排序度
{
    int A = 0, C = 0, G = 0, T = 0;
    int num = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dna[i] == 'A')
        {
            A++;
        }
        else if (dna[i] == 'C')
        {
            C++;
            num += A;
        }
        else if (dna[i] == 'G')
        {
            G++;
            num += A + C;
        }
        else if (dna[i] == 'T')
        {
            T++;
            num += A + C + G;
        }
    }
    return num;
}
node *CreateList(int m) //链表的建立递归函数
{
    if (m == 0)
        return NULL;
    node *p = new node;
    cin >> p->DNA;
    p->num = solve(p->DNA);

    p->next = CreateList(m - 1);
    return p;
}

//排序要用的函数
node *middleNode(node *head) //  找到链表中间节点函数
{
    if (head == NULL || head->next == NULL) //不足两个
        return head;

    //用快慢指针实现，两倍速
    node *slow = head;
    node *fast = head->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
node *mergeTwoLists(node *l1, node *l2) // 合并两个有序链表函数，同时保持排序
{
    node *sentry = new node; //虚拟头
    node *curr = sentry;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->num < l2->num) //数小在前
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    curr->next = l1 != NULL ? l1 : l2; //接上剩余一堆大的部分
    return sentry->next;
}
node *sortList(node *head) //链表的排序递归函数
{
    // 1、递归结束条件，不足两个
    if (head == NULL || head->next == NULL)
        return head;

    // 2、找到链表中间节点并断开链表  递归调用
    node *midNode = middleNode(head); //中间节点
    node *rightHead = midNode->next;  //中间节点的下一个
    midNode->next = NULL;             //断开

    node *left = sortList(head);       //递归，排左边
    node *right = sortList(rightHead); //递归，排右边

    // 3、当前层操作（合并有序链表）
    return mergeTwoLists(left, right); //合并且排序
}

//链表输出要用的函数
void PrintList(node *head)
{
    if (head == NULL)
        return;
    cout << head->DNA << endl;
    PrintList(head->next);
}

//主函数
int main()
{
    cin >> n >> m; //接受参数输入

    node *head = CreateList(m); //创建链表

    head = sortList(head); //排序链表

    PrintList(head); //输出链表

    return 0;
}