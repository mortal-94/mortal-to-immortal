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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        // 先翻转下面的
        TreeNode *left = invertTree(root->left);   //翻左边
        TreeNode *right = invertTree(root->right); //翻右边
        // 当层逻辑是交换两个孩子节点
        root->left = right; //左孩子变成翻转好的右子树根节点
        root->right = left; //有孩子变成翻转好的左子树根节点
        // 返回根节点
        return root;
    }
};