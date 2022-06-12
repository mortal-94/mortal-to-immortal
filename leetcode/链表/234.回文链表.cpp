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
    // 反转前半部分；再由中间先两边判断即可
    bool isPalindrome(ListNode *head)
    {
        // 利用快慢指针找出前半部分，顺带反转
        ListNode *slow, *fast, *pre = nullptr;
        slow = fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            // 反转操作
            ListNode *nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt;
        }
        // 此时slow的前面以及被反转（不包含slow
        ListNode *left, *right;
        left = pre;
        // 后半部分的起始位置  画图便可得到以下关系
        right = fast == nullptr ? slow : slow->next;
        // 由中间向两边走下去判断即可
        while (right != nullptr)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};