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

// 递归的
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return nullptr;
        // 利用二叉搜索树的特性 左小右大
        if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

// 迭代的
class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root) {
            if (val == root->val) {
                return root;
            }
            root = val < root->val ? root->left : root->right;
        }
        return nullptr;
    }
};