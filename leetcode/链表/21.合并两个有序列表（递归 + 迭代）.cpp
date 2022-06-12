/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//递归版
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2)             //有一个到头了
            return list1 ? list1 : list2; //返回剩下的

        //挑出小的节点
        if (list1->val < list2->val) // list1当前节点小
        {
            list1->next = mergeTwoLists(list1->next, list2); //把 list1当前节点后面的 和 list2当前节点 合并 ；并成为list1当前节点的下一个
            return list1;
        }
        else // list2当前节点小
        {
            list2->next = mergeTwoLists(list1, list2->next); //把 list2当前节点后面的 和 list1当前节点 合并 ；并成为list2当前节点的下一个
            return list2;
        }
    }
};

//迭代版
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 虚拟头节点
        ListNode *dummyhead = new ListNode(-1);
        // 流动节点，连接着虚拟头节点
        ListNode *cur = dummyhead;
        // 合并
        while (list1 && list2)
        {
            // 比较 list1 和 list2 两个指针
            // 将值较小的的节点接到 cur 指针
            if (list1->val > list2->val) // list2小
            {
                cur->next = list2;   //接list2
                list2 = list2->next; // list2流动
            }
            else // list1小
            {
                cur->next = list1;   //接list1
                list1 = list1->next; // list1流动
            }
            // cur 指针不断前进
            cur = cur->next;
        }
        //接上剩下的
        cur->next = list1 ? list1 : list2;

        return dummyhead->next;
    }
};