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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummyhead = new ListNode(-1); //虚拟头节点
        dummyhead->next = head;
        // 记录反转区域的前一个节点 pre  自身不会变，它的下一个会持续变化
        ListNode *pre = dummyhead;
        for (int i = 0; i < left - 1; i++)
            pre = pre->next;
        // 进行反转操作
        ListNode *primeLeft = pre->next; // 记录着最初的left位置节点，自身不会变，它的前一个会变化一次，后一个会持续变化
        ListNode *next;                  // 待转节点
        for (int i = 0; i < right - left; i++)
        {
            next = primeLeft->next;       //待转节点为最初的left位置节点 的 下一个
            primeLeft->next = next->next; //最初的left位置节点 下一个发生变化 变为 下下个
            next->next = pre->next;       //待转节点开始反转，它的下一个变成 原本pre的下一个
            pre->next = next;             // pre的 下一个发生变化 变为 待转节点，即，待转节点的上一个变为了pre，至此该节点反转结束
        }
        return dummyhead->next;
    }
};