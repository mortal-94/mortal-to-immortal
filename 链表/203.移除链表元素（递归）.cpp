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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
//读递归代码：从后读起。

//例如示例：
//输入：head = [1,2,6,3,4,5,6], val = 6
//输出：[1,2,3,4,5]

//会调用该函数8次，每次的head按顺序对应一个元素，最后一次head等于空返回

//7.从最后元素6的函数读起，它接受的返回值便是空，即6的nest是空；它由于与val相等，所以返回的值是6的nest，即空。！！！

//6.倒数第二个元素5的函数中，它接受的返回值为最后元素6的函数返回值，即空，即5的next为空；它的返回值是自身。
//5.倒数第三个元素4的函数中，它接受的返回值为上个元素5的函数返回值，即5，即4的next为5；它的返回值是自身。
//4.倒数第四个元素3的函数中，它接受的返回值为上个元素4的函数返回值，即4，即3的next为4；它的返回值是自身。

//3.倒数第五个元素6的函数中，它接受的返回值为上个元素3的函数返回值，即3，即6的next为3；它由于与val相等，所以返回的值是6的nest，即3。！！！

//2.倒数第六个元素2的函数中，它接受的返回值为上个元素6的函数返回值，即3，即2的next为3；它的返回值是自身。
//1.倒数第七个元素1的函数中，它接受的返回值为上个元素2的函数返回值，即2，即1的next为2；它的返回值是自身。

//如此便得到答案链表，时间复杂度与迭代相同，不过空间复杂度不如迭代。