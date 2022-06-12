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
    // 注意二叉搜索树的定义： root 的整个左子树都要小于 root->val，整个右子树都要大于 root->val
    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        if (root == nullptr)
            return true;

        if (min != nullptr && root->val <= min->val)
            return false;
        if (max != nullptr && root->val >= max->val)
            return false;

        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, nullptr, nullptr);
    }
};
// reference
// https://labuladong.github.io/algo/2/19/40/#一判断-bst-的合法性