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
    int maxDepth(TreeNode *root)
    {
        //空就返回0
        //不空就计算从左孩子走下去和从右孩子走下去的最大深度
        //返回两者间最大的那个，再加上当前一个1
        return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};