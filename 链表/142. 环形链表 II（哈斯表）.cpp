//找环形入口。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> m;
        while (head != NULL)
        {
            m[head]++;
            if (m[head] == 2)
                return head;
            head = head->next;
        }
        return NULL;
    }
};
//自己的

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> visited;
        while (head != nullptr)
        {
            if (visited.count(head))
            {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。