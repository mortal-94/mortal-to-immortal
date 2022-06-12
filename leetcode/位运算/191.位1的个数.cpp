class Solution
{
public:
    // n&(n-1)去掉n的二进制最后一个1
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};