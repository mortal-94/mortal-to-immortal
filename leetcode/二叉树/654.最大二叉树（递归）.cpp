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
    //
    TreeNode *build(vector<int> nums, int l, int r)
    {
        // 终止条件
        if (r < l)
            return nullptr;
        // 找出最大值和最大值索引
        int index, maxVal = INT_MIN;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                index = i;
            }
        }
        // 构造当前节点
        TreeNode *root = new TreeNode(maxVal);
        // 递归求出当前节点的左右孩子
        root->left = buid(nums, l, index - 1);
        root->right = buid(nums, index + 1, r);
        // 返回当前节点
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};

// reference
// https://labuladong.github.io/algo/2/19/35/#构造最大二叉树