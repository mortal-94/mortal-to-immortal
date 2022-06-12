class Solution
{
public:
    // 利用 n^n=0 和 n^0=n 的性质
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int n : nums)
            res = res ^ n;
        return res;
    }
};