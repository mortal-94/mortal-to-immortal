class Solution
{
public:
    // 依题，对应的所有索引的值异或，再多异或边界即可
    int missingNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            res = res ^ i ^ nums[i];
        return res ^ nums.size();
    }
};