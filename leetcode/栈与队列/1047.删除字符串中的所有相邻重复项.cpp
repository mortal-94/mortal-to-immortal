class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            // s[i]为 准备打算 后插入res的字符

            //进行判断
            if (res.empty() || s[i] != res.back()) // res为空，或者res最后一个字符与s[i]不等，就可以把是s[i]后插进入
                res.push_back(s[i]);
            else // res不为空且s[i]与res最后一个字符相等，则把res的最后一个字符弹出。
                res.pop_back();
        }
        return res;
    }
};