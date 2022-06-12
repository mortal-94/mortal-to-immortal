class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            // 找到答案
            if (numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};
            // 偏小，加大
            while (numbers[left] + numbers[right] < target && left < right)
                left++;
            // 偏大，减小
            while (numbers[left] + numbers[right] > target && left < right)
                right--;
        }
        return {};
    }
};