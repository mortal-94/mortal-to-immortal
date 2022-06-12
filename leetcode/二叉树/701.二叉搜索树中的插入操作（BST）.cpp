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
    // 该题无需讨论值相等情况
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 找空位置插入
        if (root == nullptr)
            return new TreeNode(val);

        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else if (root->val > val)
            root->left = insertIntoBST(root->left, val);

        return root;
    }
};
// reference
// https://labuladong.github.io/algo/2/19/40/#在-bst-中插入一个数