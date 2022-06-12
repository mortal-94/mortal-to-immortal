class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
        {
            // base case
            return n;
        }
        // 分别代表 dp[i - 1] 和 dp[i - 2]
        int dp_i_1 = 1, dp_i_2 = 0;
        for (int i = 2; i <= n; i++)
        {
            // dp[i] = dp[i - 1] + dp[i - 2];
            int dp_i = dp_i_1 + dp_i_2;
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i_1;
    }
};

// reference :
// https://labuladong.github.io/article/fname.html?fname=动态规划详解进阶