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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //因为有可能要删掉头，所以要引入虚拟头指针
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        //用两个指针，它们一直相隔n，前面到头，后面指向的便是要删除的前一个
        ListNode *slow, *fast;
        slow = fast = dummyHead;
        while (n--)
            fast = fast->next; // 相隔n
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        //要删掉slow的下一个。
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        return dummyHead->next;
    }
};