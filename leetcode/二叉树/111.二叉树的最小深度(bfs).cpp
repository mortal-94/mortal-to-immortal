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
    int minDepth(TreeNode *root)
    {
        // 特殊判断
        if (root == nullptr)
            return 0;
        // 依赖队列数据结构
        queue<TreeNode *> q;
        q.push(root); //先放根节点进去
        // 根节点本身就是一层
        int depth = 1;
        // 广度优先搜索
        while (!q.empty())
        {
            // 队列存着一层节点的所有节点，循环一层一层看下去
            // 将当前队列即当前层中的所有节点的孩子放进队列，看完一个再看一个
            int sz = q.size();
            for (int i = 0; i < sz; i++) //走完一层
            {
                TreeNode *cur = q.front();
                q.pop();
                // 结束条件 终点
                if (cur->left == nullptr && cur->right == nullptr)
                    return depth;
                // 该节点的孩子进队列
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            // 下一层
            depth++;
        }
        return depth;
    }
};

// reference
// https://labuladong.github.io/algo/1/7/#二二叉树的最小高度