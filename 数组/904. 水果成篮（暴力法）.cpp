class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int temp = 1, sub1 = 0, sub2 = 0, result = INT_MIN, k, h;
        // temp临时储存的可行解值,从1起步
        //两个sub是两种水果
        // result 最后的结果
        for (int i = 0; i < fruits.size(); i++)
        {
            sub1 = fruits[i]; //记录第一种水果
            for (k = i; k < fruits.size(); k++)
            {
                if (fruits[k] != sub1)
                {
                    sub2 = fruits[k]; //记录第二种水果
                    break;
                }
                else if (k == fruits.size() - 1) //找不到第二种水果
                {
                    temp = k - i + 1;
                }
            }
            for (h = k; h < fruits.size(); h++) //找第三种水果
            {
                if (fruits[h] != sub1 && fruits[h] != sub2) //找到第三种水果
                {
                    temp = h - i; // h索引的值不在要返回的子序列内
                    break;
                }
                else if (h == fruits.size() - 1) //没找到第三种水果
                {
                    temp = h - i + 1; // h索引的值在要返回的子序列内
                    break;
                }
            }
            result = temp > result ? temp : result;
            if (result == fruits.size()) //当前值等于最大长度直接返回就行
                break;
        }
        return result;
    }
};