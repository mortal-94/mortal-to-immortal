class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        //变量声明
        int len1 = s1.size();
        int len2 = s2.size();

        //特殊处理
        if (len1 > len2)
            return false;

        // sliding window 大小
        int WindowSize = len1;

        // hash table 制作，运用字母对应下标，值对应次数。
        vector<int> Hash_Table1(26, 0);
        vector<int> Hash_Table2(26, 0);
        for (int i = 0; i < len1; i++)
        {
            Hash_Table1[s1[i] - 'a']++;
            Hash_Table2[s2[i] - 'a']++;
        }

        //初次判断
        //窗口内的用哈斯表判断是否符号题意
        if (Hash_Table1 == Hash_Table2)
            return true;

        // sliding
        for (int i = WindowSize; i < len2; i++)
        {
            // sliding
            Hash_Table2[s2[i] - 'a']++;              //右边进来
            Hash_Table2[s2[i - WindowSize] - 'a']--; //左边出去

            //窗口内的用哈斯表判断是否符号题意
            if (Hash_Table1 == Hash_Table2)
                return true;
        }

        //最终判断
        return false;
    }
};