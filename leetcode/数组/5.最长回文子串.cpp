class Solution
{
public:
    // 在 s 中寻找 以 s[l]和s[r] 为中心的最长回文串
    string palindrome(string s, int l, int r)
    {
        // 回文匹配
        while (l >= 0 && r < s.size() && s[l] == s[r])
            l--, r++;
        // 返回s中以l+1位置开始，r-l-1个字符
        return s.substr(l + 1, r - l - 1);
    }
    static bool cmp(const string &a, const string &b)
    {
        return a.size() < b.size();
    }
    string longestPalindrome(string s)
    {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            // 以 s[i] 为中心
            string s1 = palindrome(s, i, i);
            // 以 s[i] 和 s[i+1] 为中心
            string s2 = palindrome(s, i, i + 1);
            // 记录最长的字符串
            res = max(max(s1, s2, cmp), res, cmp);
        }
        return res;
    }
};

// reference
// https://labuladong.github.io/algo/2/18/21/