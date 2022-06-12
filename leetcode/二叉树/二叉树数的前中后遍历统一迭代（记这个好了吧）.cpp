// leetcode 95(中序遍历) 144(前序遍历) 145(后序遍历)
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
    //后序遍历   左右中
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stk;
        vector<int> res;
        if (root != nullptr)
            stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            if (node != nullptr) //放 中、右、左
            {
                stk.pop(); //防止重复进栈

                stk.push(node);    //中
                stk.push(nullptr); //需要辅助的空节点提供 中间节点是否出栈 的判断条件

                if (node->right != nullptr)
                    stk.push(node->right); //右

                if (node->left != nullptr)
                    stk.push(node->left); //左
            }
            else //空节点进来
            {
                stk.pop(); //弹出一个空节点
                // 拿出节点
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }

    //前序遍历   中左右
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stk;
        vector<int> res;
        if (root != nullptr)
            stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            if (node != nullptr) //放 右、左、中
            {
                stk.pop(); //防止重复进栈

                if (node->right != nullptr)
                    stk.push(node->right); //右

                if (node->left != nullptr)
                    stk.push(node->left); //左

                stk.push(node); //中
                stk.push(nullptr); //需要辅助的空节点提供 中间节点是否出栈 的判断条件
            }
            else //空节点进来
            {
                stk.pop();//弹出空节点
                // 拿出节点
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }

    //中序遍历    左中右
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stk;
        vector<int> res;
        if (root != nullptr)
            stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            if (node != nullptr) //放 右、中、左
            {
                stk.pop(); //防止重复进栈

                if (node->right != nullptr)
                    stk.push(node->right); //右

                stk.push(node);    //中
                stk.push(nullptr); //需要辅助的空节点提供 中间节点是否出栈 的判断条件

                if (node->left != nullptr)
                    stk.push(node->left); //左
            }
            else //空节点进来
            {
                stk.pop(); //弹出一个空节点
                // 拿出节点
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};