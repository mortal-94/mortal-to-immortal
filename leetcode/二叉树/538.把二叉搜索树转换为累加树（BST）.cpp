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
    int sum;
    // 利用 反序中序遍历（右、中、左）
    void traverse(TreeNode *root)
    {
        if (root == nullptr)
            return;

        traverse(root->right);
        
        sum += root->val;
        root->val = sum;

        traverse(root->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        sum = 0;
        traverse(root);
        return root;
    }
};

// 该题目与 1038: https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/  相同