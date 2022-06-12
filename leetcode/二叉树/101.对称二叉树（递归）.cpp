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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode *left, TreeNode *right)
    {
        // 有一个是空了，都是空返回值，否则返回假
        if (left == nullptr || right == nullptr)
            return right == left;
        // 判断是否对称
        if (left->val != right->val)
            return false;
        // 继续检查     左边的右 和 右边的左   以及   左边的左 和 右边的右
        return check(left->right, right->left) && check(left->left, right->right);
    }
};