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
    map<string, int> memo; //哈斯表映射 序列化的树 --> 出现次数
    vector<TreeNode *> res;
    // 这里采用后续遍历
    string traverse(TreeNode *root)
    {
        // 用 # 代替 空指针
        if (root == nullptr)
            return "#";
        // 后续遍历
        string left = traverse(root->left);
        string right = traverse(root->right);
        // 子二叉树序列化
        string subTree = left + "," + right + "," + to_string(root->val);
        // 查看该二叉树是否出现过，多次重复也只会被加入结果集一次
        if (memo[subTree] == 1)
            res.push_back(root);
        // 哈斯表映射记录
        memo[subTree]++;
        // 返回当层函数的序列化树
        return subTree;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        // 重置数据
        memo.clear();
        res.clear();
        // 遍历找出答案
        traverse(root);
        return res;
    }
};

// reference
// https://mp.weixin.qq.com/s/LJbpo49qppIeRs-FbgjsSQ