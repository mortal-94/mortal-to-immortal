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

// 递归
class Solution
{
public:
    // 前序遍历，向右下方拉平
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        // 两边拉平向右下方拉平
        flatten(root->left);
        flatten(root->right);
        // 递归单层逻辑
        TreeNode *right = root->right; //记住右孩子
        root->right = root->left;      //让右孩子变成左孩子（题意为前序遍历，所以拉平后是左孩子先
        root->left = nullptr;          //左侧置空
        //   拼接前面记好的右孩子
        TreeNode *cur = root;
        while (cur->right != nullptr) //走到最后
            cur = cur->right;
        cur->right = right; //拼接
    }
};
// 时间和空间复杂度均为 O(N)    N为节点个数

// 迭代
// reference    https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr != nullptr)
        {
            if (curr->left != nullptr)
            {
                // 在左孩子末尾拼接右孩子
                TreeNode *cur = curr->left;
                while (cur->right != nullptr)
                    cur = cur->right;
                cur->right = curr->right; //拼接
                // 让右孩子变成左孩子
                curr->right = curr->left;
                // 左边置空
                curr->left = nullptr;
            }
            // 看下一个
            curr = curr->right;
        }
    }
};
// 时间还是 O(N)
// 但空间复杂度降为了 O(1)