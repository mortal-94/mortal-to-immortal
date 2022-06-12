class Solution
{
public:
    string plusOne(string s, int j)
    {
        if (s[j] == '9')
            s[j] = '0';
        else
            s[j] += 1;
        return s;
    }
    string minusOne(string s, int j)
    {
        if (s[j] == '0')
            s[j] = '9';
        else
            s[j] -= 1;
        return s;
    }

    int openLock(vector<string> &deadends, string target)
    {
        // 需要跳过的死亡密码
        set<string> deads;
        for (string s : deadends)
            deads.insert(s);
        // 记录走过的密码
        set<string> vis;
        // 队列数据结构
        queue<string> q;
        // 起点
        int step = 0;
        q.push("0000");
        vis.insert("0000");
        // 层序遍历（广度优先搜索
        while (!q.empty())
        {
            // 先获取出该层节点数
            int sz = q.size();
            // 整层遍历（遍历该层所有节点
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                // 遇到死亡节点，别转下去了，看另一个节点continue
                if (deads.find(cur) != deads.end())
                    continue;
                // 到达终点，返回当前层数
                if (cur == target)
                    return step;
                // 四个转盘锁
                for (int j = 0; j < 4; j++)
                {
                    // 向上拨
                    string up = plusOne(cur, j);
                    //  是没走过的节点
                    if (vis.find(up) == vis.end())
                    {
                        q.push(up);
                        vis.insert(up);
                    }
                    // 向下拨
                    string down = minusOne(cur, j);
                    //  是没走过的节点
                    if (vis.find(down) == vis.end())
                    {
                        q.push(down);
                        vis.insert(down);
                    }
                }
            }
            // 层数+1
            step++;
        }
        return -1;
    }
};

// reference
// https://labuladong.github.io/algo/1/7/#三解开密码锁的最少次数