class Solution
{
public:
    vector<vector<int>> res; //记录最终答案
    vector<bool> vis;        //记录是否访问过，可否选择这条路径
    //回溯函数
    void backtrack(vector<int> nums, vector<int> &track)
    {
        // 终止条件      路径走到了尽头
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        // 遍历节点
        for (int i = 0; i < nums.size(); i++)
        {
            // 访问过，不可选择这条路径
            if (vis[i])
                continue;
            //修改访问状态
            vis[i] = true;
            //走这条路径下去
            track.push_back(nums[i]);
            backtrack(nums, track);
            //恢复原始状态
            track.pop_back();
            vis[i] = false;
        }
    }
    // 主函数，输入一组不重复的数字，返回它们的全排列
    vector<vector<int>> permute(vector<int> &nums)
    {
        // 重置数组
        vis.resize(nums.size(), false);
        res.clear();
        // 回溯
        vector<int> track;
        backtrack(nums, track);
        
        return res;
    }
};

// referance
// https://labuladong.github.io/algo/1/6/#一全排列问题