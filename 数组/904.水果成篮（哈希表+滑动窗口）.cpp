class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;//无序的对组
        int res = 0;

        //left指向第一种水果，right不断向后找。
        for (int left = 0, right = 0; right < fruits.size(); right++)
        {
            basket[fruits[right]]++;//哈希表制作，一个篮子装同一种水果，哈斯表一直记录着这种水果的个数
            while (basket.size() > 2)//一旦需要第三个篮子则进入循环，目的为了改变left，让其与right-1之间只有1种水果，满足这样的最小left
            {
                //这时left到right-1之间只有两种水果
                basket[fruits[left]]--;//left不断向后走，不断地丢弃对应的水果
                if(basket[fruits[left]] == 0)//一旦发现某种水果刚好被丢完，则此后就剩下一种水果，后面直到right就只剩下一种水果了
                    basket.erase(fruits[left]);
                left++;
            }
            //res不断迭代
            res = max(res, right - left - 1);
        }

        return res;
    }
};