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
class Solution
{
public:
    // 翻转 [a, b)
    ListNode *reverse(ListNode *a, ListNode *b)
    {
        ListNode *pre, *cur, *nxt;
        pre = nullptr;
        cur = nxt = a;
        while (cur != b)
        {
            nxt = cur->next; //记住后一个
            cur->next = pre; //反转
            pre = cur;       //记住前一个
            cur = nxt;       //cur流动
        }
        return pre;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 制作一组待反转链表
        ListNode *a, *b;
        a = b = head;
        for (int i = 0; i < k; i++)
        { // 注意这个for循环让b与a之间隔了k步，！！！并且最后一步可以走向nullptr
            if (b == nullptr)
                return head;
            b = b->next;
        }
        // 反转一组
        ListNode *newHead = reverse(a, b);
        //  拼接
        a->next = reverseKGroup(b, k);
        return newHead;
    }
};

// reference
// https://labuladong.github.io/algo/2/17/18/