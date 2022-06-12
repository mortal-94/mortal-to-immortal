class NumArray
{
public:
    vector<int> preSum;//前缀和数组

    NumArray(vector<int> &nums)
    {
        // 重置前缀和数组，大小为num.size()+1，值全为0；空出一个元素是为了for循环逻辑统一
        preSum.resize(nums.size() + 1, 0);
        // 制作前缀和数组
        for (int i = 1; i < preSum.size(); i++)
            preSum[i] = preSum[i - 1] + nums[i - 1];
    }
    // 返回部分和
    int sumRange(int left, int right)
    {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */