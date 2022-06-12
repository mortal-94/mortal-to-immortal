
// 迭代法，自下而上
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int Max = amount + 1;
        // 初始化一个大小位amount+1，值全为 Max的数组
        vector<int> dp(amount + 1, Max);
        // 令其第一个元素值为零，因为自下而上
        dp[0] = 0;

        // 自下而上一直计算到 找出凑出金额amount的最少硬币数 dp[amount]
        for (int i = 1; i <= amount; ++i)
        {
            // 遍历所有硬币；找出最小的、凑出金额 i 的最少硬币数 dp[i]
            for (int j = 0; j < coins.size(); ++j)
            {
                // 只有硬币面值比要凑的值下才可以凑
                if (coins[j] <= i)
                {
                    // 最少硬币数  dp[金额 - 去这枚硬币的面值] 即为另一个要凑的金额的最少硬币数，加上当前的 一个
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        // 是否已找到凑出金额amount的最少硬币数
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// 递归，自上而下
class Solution
{
    vector<int> count; //记忆
    // 返回要 凑成 金额 rem 的最少硬币数
    int dp(vector<int> &coins, int rem)
    {
        if (rem < 0) //凑不成
            return -1;
        if (rem == 0) //凑成了
            return 0;
        if (count[rem - 1] != 0) //算过
            return count[rem - 1];

        // 找出凑出金额amount的最少硬币数 count[amount]
        int Min = INT_MAX;
        for (int coin : coins)
        {
            // 最少硬币数  dp 一下 （金额 - 去这枚硬币的面值) 即为另一个要凑的金额的最少硬币数，加上当前的 一个
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < Min)
            {
                Min = res + 1;
            }
        }
        // 记录，凑不成就是-1，凑成就记录
        count[rem - 1] = Min == INT_MAX ? -1 : Min;

        return count[rem - 1];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount < 1)
            return 0;
        // count初始化大小为 amount，值为 0
        count.resize(amount, 0);

        return dp(coins, amount);
    }
};

// reference
// https://leetcode.cn/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/
