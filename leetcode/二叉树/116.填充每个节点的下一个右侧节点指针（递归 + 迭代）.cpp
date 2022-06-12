/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// 递归
class Solution
{
public:
    Node *connect(Node *root)
    {
        // 在遍历节点时完成填充
        traverse(root);
        return root;
    }
    // 遍历函数
    void traverse(Node *root)
    {
        if (root == nullptr || root->left == nullptr || root->right == nullptr)
            return;
        // 左孩子的next指向右孩子
        root->left->next = root->right;
        // 右孩子的next指向：若父节点没有兄弟节点则指向nullptr，否则指向父节点其兄弟节点的左孩子
        root->right->next = root->next == nullptr ? nullptr : root->next->left;
        // 递归遍历下去
        traverse(root->left);
        traverse(root->right);
    }
};
// 时间、空间复杂度均为 O(N) N为节点个数
// 每个节点需遍历一次、每个节点需调用递归栈一个


// 迭代，层序遍历思想     reference
// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/solution/tian-chong-mei-ge-jie-dian-de-xia-yi-ge-you-ce-2-4/
class Solution
{
public:
    Node *connect(Node *root)
    {
        // 从根节点开始
        Node *leftmost = root;
        // 层序遍历
        while (leftmost->left != nullptr)
        {
            // 遍历这一层节点组织成的链表，为 下一层 的节点更新 next 指针
            Node *head = leftmost;
            while (head != nullptr)
            {
                // 左孩子节点的next
                head->left->next = head->right;
                // 右孩子节点的next
                if (head->next != nullptr)
                {
                    head->right->next = head->next->left;
                }
                // 父节点向右移动
                head = head->next;
            }
            // 去下一层的最左的节点
            leftmost = leftmost->left;
        }
        return root;
    }
}; 
// 时间复杂度为 O(N)  N为节点个数   每个节点需遍历一遍
// 空间复杂度为 O(1)  只需用到有限空间