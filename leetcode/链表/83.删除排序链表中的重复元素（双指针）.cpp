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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr)
        {
            // 相等则删掉
            if (cur->val == cur->next->val)
            {
                ListNode *junk = cur->next;
                cur->next = cur->next->next;
                delete junk;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};