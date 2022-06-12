/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // 找到最小的
    TreeNode *getMin(TreeNode *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == key)
        {
            // 如果不足两个孩子，直接让剩下那个孩子或者空指针接上来就行
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            
            // 如果两边都有孩子
            TreeNode *minNode = getMin(root->right);             //找出右孩子最小的那个节点并记录
            root->right = deleteNode(root->right, minNode->val); //删掉右孩子的最小节点
            // 用记录好那个右孩子最小节点与当前节点交换
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;
        }
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        // 最后返回当前节点进行拼接
        return root;
    }
};

// reference
// https://labuladong.github.io/algo/2/19/40/#三在-bst-中删除一个数