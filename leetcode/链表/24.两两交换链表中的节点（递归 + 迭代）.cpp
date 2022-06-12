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

//递归三部曲
//找整个递归的终止条件：递归应该在什么时候结束？
//找返回值：应该给上一级返回什么信息？
//本级递归应该做什么：在这一级递归中，应该完成什么任务？
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        //终止条件就是没得交换的时候，递归就终止了
        //因此当链表只剩一个节点或者没有节点的时候，自然递归就终止了
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        //递归开始，找返回值。
        //下级级该返回已处理好的链表 表头
        ListNode *NEXT = head->next;
        NEXT->next = swapPairs(head->next->next);
        //即 上级 → head → NEXT → 已处理好的链表

        //本级递归该做的：交换操作
        head->next = NEXT->next;
        NEXT->next = head;
        //变成了 上级 → NEXT → head → 已处理好的链表

        //返回已处理好的链表 表头NEXT
        return NEXT;
    }
};
//时间复杂度：$O(n)$  其中 n 是链表的节点数量。需要对每个节点进行更新指针的操作。
//空间复杂度：$O(n)$  其中 n 是链表的节点数量。空间复杂度主要取决于递归调用的栈空间。

// https://lyl0724.github.io/2020/01/25/1/  略有不同，想法一样


//迭代版
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点 //虚拟表头要用new创建
        dummyHead->next = head;                // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp = cur->next;              // 记录临时节点
            ListNode *tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next;  // 步骤一
            cur->next->next = tmp;        // 步骤二
            cur->next->next->next = tmp1; // 步骤三

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        return dummyHead->next;
    }
};

//时间复杂度：$O(n)$   其中 n 是链表的节点数量。需要对每个节点进行更新指针的操作。
//空间复杂度：$O(1)$