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
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *dummyhead = new ListNode(-1);                //虚拟头节点
        ListNode *cur = dummyhead;                             //流动节点  被虚拟头节点连接着
        priority_queue<ListNode *, vector<ListNode *>, cmp> q; //优先级队列，小根堆

        for (int i = 0; i < lists.size(); i++) // 将 k 个链表的头节点压入小根堆
        {
            if (lists[i])
                q.push(lists[i]);
        }

        while (!q.empty()) // 遍历所有节点
        {
            cur->next = q.top(); //取除最小节点，拼上虚拟头节点的链表
            q.pop();             //删掉

            if (cur->next->next)         //该节点后面还有
                q.push(cur->next->next); //继续压进小根堆

            cur = cur->next; //流动节点流动
        }
        return dummyhead->next;
    }
};