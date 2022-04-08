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
    ListNode *removeElements(ListNode *head, int val) //要删除的数为val
    {
        //定义一个虚拟的头节点，因为原链头可能也会被删除
        ListNode *dummyNode = new ListNode(0);  //虚拟表头要用new创建
        dummyNode->next = head;

        ListNode *temp = dummyNode; // temp指向虚拟头节点,此时temp->next为链表的第一个元素
        while (temp->next != nullptr)
        {
            if (temp->next->val == val)
            {
                ListNode *dele = temp->next;
                temp->next = temp->next->next; //删除节点操作
                delete dele;                   //清除被删除节点
            }
            else //不需要删除时才执行，若进行了删除操作就不必执行，所以有else前提
                temp = temp->next;
        }

        head = dummyNode->next; //让链头回来
        delete dummyNode;       //清除虚拟头节点
        return head;
    }
};