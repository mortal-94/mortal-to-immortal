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
    map<int, int> ValToIndex; //哈希映射，方便查找对应值索引
    TreeNode *build(vector<int> preorder, int pl, int pr, vector<int> inorder, int il, int ir)
    {
        // 终止条件
        if (pr < pl || ir < il)
            return nullptr;
        // 找出当前根节点的索引，当前根节点应为前序遍历的第一个
        int Index = ValToIndex[preorder[pl]];
        // 算出左边后辈的个数  根据中序遍历的规律，其等于 当前节点索引-中序遍历的起始位置
        int leftSize = Index - il;
        // 制作当前节点
        TreeNode *root = new TreeNode(preorder[pl]);
        //  当前节点的左边后边对应前序遍历的区域为 [pl+1, pl+leftSize]
        //  当前节点的左边后边对应中序遍历的区域为 [il+1, index-1]
        root->left = build(preorder, pl + 1, pl + leftSize, inorder, il, Index - 1);
        //  当前节点的右边后边对应前序遍历的区域为 [pl+leftSize, pr]
        //  当前节点的右边后边对应中序遍历的区域为 [index+1, ir]
        root->right = build(preorder, pl + leftSize + 1, pr, inorder, Index + 1, ir);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            ValToIndex[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

// reference
// https://labuladong.github.io/algo/2/19/35/#通过前序和中序遍历结果构造二叉树