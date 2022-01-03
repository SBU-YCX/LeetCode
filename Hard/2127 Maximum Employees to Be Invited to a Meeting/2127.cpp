// Topic     : 2127. Maximum Employees to Be Invited to a Meeting (https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2127%20Maximum%20Employees%20to%20Be%20Invited%20to%20a%20Meeting)
// Time      : O(N) 
// Space     : O(N)


class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size(), ans1 = 0, ans2 = 0;
        vector<bool> visited(n, false), inpath(n, false);
        vector<int> num(n, 0);
        unordered_map<int, vector<int>> nxt;
        for (int i = 0; i < n; i++)
            nxt[favorite[i]].push_back(i);
        for (int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            int k = 1;
            dfs1(nxt, favorite, i, k, n, num, visited, inpath, ans1);
        }
        for (int i = 0; i < n; i++)
            if (i == favorite[favorite[i]] && i < favorite[i])
                ans2 += dfs2(nxt, favorite, i) + dfs2(nxt, favorite, favorite[i]);
        return max<int>(ans1, ans2);
    }
    
private:
    void dfs1(unordered_map<int, vector<int>>& nxt, vector<int>& favorite, int i, int& k, int& n, vector<int>& num, vector<bool>& visited, vector<bool>& inpath, int& ans)
    {
        visited[i] = inpath[i] = true;
        num[i] = k++;
        int j = favorite[i];
        if (!visited[j])
            dfs1(nxt, favorite, j, k, n, num, visited, inpath, ans);
        if (inpath[j])
            ans = max<int>(ans, num[i] - num[j] + 1);
        inpath[i] = false;
    }
    
    int dfs2(unordered_map<int, vector<int>>& nxt, vector<int>& favorite, int i)
    {
        int ans = 1;
        for (auto& j : nxt[i])
            if (j != favorite[i])
                ans = max<int>(ans, dfs2(nxt, favorite, j) + 1);
        return ans;
    }
};
