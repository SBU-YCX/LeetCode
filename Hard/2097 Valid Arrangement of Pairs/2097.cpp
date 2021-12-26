//  Topic   : 2097. Valid Arrangement of Pairs (https://leetcode.com/problems/valid-arrangement-of-pairs/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> startIdx, endIdx;
        for (int i = 0; i < n; i++)
        {
            startIdx[pairs[i][0]].push_back(i);
            endIdx[pairs[i][1]].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto& p : startIdx)
            if (endIdx.count(p.first) == 0 || p.second.size() > endIdx[p.first].size())
            {
                int start = p.first;
                dfs(start, startIdx, pairs, ans);
                reverse(ans.begin(), ans.end());
                return ans;
            }
        dfs(pairs[0][0], startIdx, pairs, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
private: 
    void dfs(int start, unordered_map<int, vector<int>>& startIdx, vector<vector<int>>& pairs, vector<vector<int>>& ans)
    {
        while (startIdx[start].size() > 0)
        {
            int end = pairs[startIdx[start].back()][1];
            startIdx[start].pop_back();
            dfs(end, startIdx, pairs, ans);
            ans.push_back({start, end});
        }
    }
};
