// Topic     : 2065. Maximum Path Quality of a Graph (https://leetcode.com/problems/maximum-path-quality-of-a-graph/)
// Author    : YCX
// Time      : O(max<int>(M + N, T / minE))
// Space     : O(M + N)


class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        unordered_map<int, vector<pair<int, int>>> connect;
        for (auto e : edges)
        {
            connect[e[0]].push_back({e[1], e[2]});
            connect[e[1]].push_back({e[0], e[2]});
        }
        int n = values.size(), ans = 0;
        vector<int> cal(n, 0);
        cal[0] = 1;
        dfs(0, connect, cal, values, values[0], maxTime, 0, ans);
        return ans;
    }
    
private: 
    void dfs(int start, unordered_map<int, vector<pair<int, int>>>& connect, vector<int>& cal, vector<int>& values, int curQuality, int maxTime, int curTime, int& ans)
    {
        if (curTime > maxTime)
            return;
        if (start == 0)
            ans = max<int>(ans, curQuality);
        for (auto i : connect[start])
        {
            if (cal[i.first] == 0)
            {
                cal[i.first] = 1;
                dfs(i.first, connect, cal, values, curQuality + values[i.first], maxTime, curTime + i.second, ans);
                cal[i.first] = 0;
            }
            else
                dfs(i.first, connect, cal, values, curQuality, maxTime, curTime + i.second, ans);
        }
    }
};
