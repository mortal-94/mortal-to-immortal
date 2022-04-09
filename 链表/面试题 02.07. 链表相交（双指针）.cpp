//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *A = headA, *B = headB;
        //指针A在A链表中走，走完就从B链表中走；指针B同理；遇上相等就结束。

        //因为两链表节点个数之和一定、重合部分节点个数也一定。
        //那么这两者相减也一定；
        //即指针A走完A链表，再从链表B开始走，走到第一个相交节点处时，指针B也在此。

        //当然，若链表长度一样，则未相交节点数也相等了，不必走完即可找到相交节点处。
        while (A != B)
        {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};

// 作者：jyd
// 链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/solution/mian-shi-ti-0207-lian-biao-xiang-jiao-sh-b8hn/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。