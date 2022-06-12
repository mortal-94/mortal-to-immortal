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
    //后序遍历  左右中
    void Postorder_Traversal(TreeNode *cur, vector<int> &n)
    {
        if (cur == nullptr)
            return;
        Postorder_Traversal(cur->left, n);  //左
        Postorder_Traversal(cur->right, n); //右
        n.push_back(cur->val);              //中
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        Postorder_Traversal(root, res);
        return res;
    }

    //后序遍历  中左右
    void preorder_traversal(TreeNode *cur, vector<int> &n)
    {
        if (cur == nullptr)
            return;
        n.push_back(cur->val);             //中
        preorder_traversal(cur->left, n);  //左
        preorder_traversal(cur->right, n); //右
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        preorder_traversal(root, res);
        return res;
    }

    //中序遍历  左中右
    void Inorder_traversal(TreeNode *cur, vector<int> &n)
    {
        if (cur == nullptr)
            return;
        Inorder_traversal(cur->left, n);  //左
        n.push_back(cur->val);            //中
        Inorder_traversal(cur->right, n); //右
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        Inorder_traversal(root, res);
        return res;
    }
};