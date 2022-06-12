/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    string StringBuilder;
    // 通过前序遍历来进行序列化 间隔符位 ,  空指针为 #
    void preordercoding(TreeNode *root)
    {
        if (root == nullptr)
        {
            StringBuilder.append("#");
            StringBuilder.append(",");
            return;
        }
        StringBuilder.append(to_string(root->val));
        StringBuilder.append(",");
        preordercoding(root->left);
        preordercoding(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        StringBuilder.clear();
        preordercoding(root);
        return StringBuilder;
    }
    
    // 反序列化
    TreeNode *preorderdecoding(string &data)
    {
        // 字符串已经空了，返回空指针
        if (data.empty())
            return nullptr;
        // 发现是 , 删掉
        if (data[0] == ',')
            data.erase(data.begin());
        // 发现是 # 删掉 并 返回空指针
        if (data[0] == '#')
        {
            data.erase(data.begin());
            return nullptr;
        }
        // 数值获取 以及 删掉字符串中的数值
        size_t sz;
        TreeNode *root = new TreeNode(stoi(data, &sz));
        data.erase(0, sz);
        // 递归
        root->left = preorderdecoding(data);
        root->right = preorderdecoding(data);
        // 返回该层完成的树
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        return preorderdecoding(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// reference
// https://labuladong.github.io/algo/2/19/36/#%E4%BA%8C%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86%E8%A7%A3%E6%B3%95