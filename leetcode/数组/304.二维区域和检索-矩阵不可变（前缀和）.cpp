class NumMatrix
{
public:
    // 前缀和数组，记录每个点到(0,0)之间的所有元素和
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>> &matrix)
    {
        // 初始化前缀和数组，行 列 均比 matrix大 1，空出一行一列方便for循环逻辑统一
        int m = matrix.size(), n = matrix[0].size();
        preSum.resize(m + 1, vector<int>(n + 1, 0));
        // 制作前缀和数组，画图便可知其中运算逻辑
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] + matrix[i - 1][j - 1] - preSum[i - 1][j - 1];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        // 画图便可知其中运算逻辑
        return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// reference
// https://labuladong.github.io/algo/2/18/22/#二维矩阵中的前缀和