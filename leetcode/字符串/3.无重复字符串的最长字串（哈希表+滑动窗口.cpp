class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> appear;

        int left = 0, right = 0;
        int maxlong = 0;
        for (; right < s.size(); right++)
        {
            while (appear.find(s[right]) != appear.end()) // 发现之前有，前功尽弃。
            {                                             //把和它相同的那个数 之前的全删掉
                appear.erase(s[left]);
                left++;
            }
            appear.insert(s[right]);
            maxlong = maxlong > right - left + 1 ? maxlong : right - left + 1;
        }
        return maxlong;
    }
};
