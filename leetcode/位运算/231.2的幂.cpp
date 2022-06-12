class Solution
{
public:
    // 2的幂用二进制表示必定只有一个1
    // n&(n-1)表示去掉n的二进制最后一个1
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
};