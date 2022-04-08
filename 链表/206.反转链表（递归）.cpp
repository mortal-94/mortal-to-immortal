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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //边缘判断。
        if (!head || !head->next) {
            return head;
        }
        //递归调用
        ListNode* newHead = reverseList(head->next);
        //反转操作
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
//读递归代码：从后读起。

//例如示例：
//假设链表为 1→2→3→∅ ，我们想要把它改成 ∅←1←2←3。

//会调用该函数3次，每次的head按顺序对应一个元素。

//3.从最后元素3的函数读起，因为3的下一个是空，所以它直接返回了3。！！！
//2.倒数第二个元素2的函数中，它接受的返回值为最后元素3的函数返回值，即3，反转操作让3指向了2，未涉及newHead，所以它的返回值也是3。
//1.倒数第一个元素1的函数中，它接受的返回值为上个元素2的函数返回值，即3，反转操作让2指向了1，未涉及newHead，所以它的返回值也是3。

//如此便得到答案链表，时间复杂度与迭代相同，不过空间复杂度不如迭代。