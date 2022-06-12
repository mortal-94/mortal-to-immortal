class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slowindex = 0;
        for (int fastindex = 0; fastindex < nums.size(); fastindex++)
        {
            if (nums[fastindex] != nums[slowindex])
                nums[++slowindex] = nums[fastindex];
        }
        return slowindex + 1;
    }
};