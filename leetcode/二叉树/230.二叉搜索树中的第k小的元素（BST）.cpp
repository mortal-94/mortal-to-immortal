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
    int res;
    // 利用二叉搜索树(BST)的性质，采用中序遍历，注意k是引用传递
    void traverse(TreeNode *root, int &k)
    {
        if (root == nullptr)
            return;

        traverse(root->left, k);
        // 于该题 中序遍历的单层函数逻辑
        k--;        // 每当可以 访问当前节点，即出现一个小的数
        if (k <= 0) //一旦超过我们要搜索的个数
        {
            // 判断是否小之前记录的答案（其实第一次进入这里时已然得到答案
            res = root->val < res ? root->val : res;
            // 无论如何，当层函数结束（避免全树遍历
            return;
        }

        traverse(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        res = INT_MAX;
        traverse(root, k);
        return res;
    }
};


// 好理解的版本
// reference    https://labuladong.github.io/algo/2/19/39/#寻找第-k-小的元素
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        // 利用 BST 的中序遍历特性
        traverse(root, k);
        return res;
    }

    // 记录结果
    int res = 0;
    // 记录当前元素的排名
    int rank = 0;
    void traverse(TreeNode* root, int k)
    {
        if (root == nullptr)
        {
            return;
        }
        traverse(root->left, k);
        /* 中序遍历代码位置 */
        rank++;
        if (k == rank)
        {
            // 找到第 k 小的元素
            res = root->val;
            return;
        }
        /*****************/
        traverse(root->right, k);
    }
};
