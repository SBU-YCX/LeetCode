//  Topic   ：1182. Shortest Distance to Target Color (https://leetcode.com/problems/shortest-distance-to-target-color/)
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(N)


class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size(), m = queries.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        vector<int> pos(3, -1);
        for (int i = 0; i < n; i++)
        {
            pos[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++)
                if (pos[j] != -1)
                    dp[i][j] = i - pos[j];
        }
        pos[0] = pos[1] = pos[2] = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            pos[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++)
                if (pos[j] != -1 && (dp[i][j] == -1 || dp[i][j] > pos[j] - i))
                    dp[i][j] = pos[j] - i;
        }  
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int p = queries[i][0], q = queries[i][1] - 1;
            ans.push_back(dp[p][q]);
        }
        return ans;
    }
};
