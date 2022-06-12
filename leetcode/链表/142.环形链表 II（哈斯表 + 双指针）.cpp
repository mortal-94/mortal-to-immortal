//找环形入口。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//哈斯表
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> m;
        while (head != nullptr)
        {
            m[head]++;
            if (m[head] == 2)
                return head;
            head = head->next;
        }
        return nullptr;
    }
};


//双指针
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow, *fast; //快慢指针
        slow = fast = head;
        while (fast != nullptr && fast->next != nullptr) //确保快指针走下去不会出错。
        {
            fast = fast->next->next; //快指针走每次两步
            slow = slow->next;       //慢指针每次走一步
            if (slow == fast)
                fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
        return nullptr;
    }
};

//具体看 https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/