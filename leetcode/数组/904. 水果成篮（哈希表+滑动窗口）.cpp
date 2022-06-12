
// 暴力求解
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int temp = 1, sub1 = 0, sub2 = 0, result = INT_MIN, k, h;
        // temp临时储存的可行解值,从1起步
        // 两个sub是两种水果
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

// 哈希表 + 滑动窗口
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> basket; //无序的对组
        int res = 0;

        // left指向第一种水果，right不断向后找。
        for (int left = 0, right = 0; right < fruits.size(); right++)
        {
            basket[fruits[right]]++;  //哈希表制作，一个篮子装同一种水果，哈斯表一直记录着这种水果的个数
            while (basket.size() > 2) //一旦需要第三个篮子则进入循环，目的为了改变left，让其与right-1之间只有1种水果，满足这样的最小left
            {
                //这时left到right-1之间只有两种水果
                basket[fruits[left]]--;        // left不断向后走，不断地丢弃对应的水果
                if (basket[fruits[left]] == 0) //一旦发现某种水果刚好被丢完，则此后就剩下一种水果，后面直到right就只剩下一种水果了
                    basket.erase(fruits[left]);
                left++;
            }
            // res不断迭代
            res = max(res, right - left - 1);
        }

        return res;
    }
};