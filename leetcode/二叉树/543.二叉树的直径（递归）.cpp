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
//两结点之间的路径长度是以它们之间边的数目表示。故
//最大直径即为 根节点左边的最大深度 + 根节点右边的最大深度
class Solution
{
public:
    int res = 0;
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftmax = maxDepth(root->left); //根节点左边的最大深度
        int rightmax = maxDepth(root->right); //根节点右边的最大深度
        //记录最大直径
        res = max(res, leftmax + rightmax);
        //继续求最大深度的操作
        return max(leftmax, rightmax) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        //调用求最大深度的函数，利用其来算出res
        maxDepth(root);
        return res;
    }
};