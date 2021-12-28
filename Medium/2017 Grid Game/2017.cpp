//  Topic   ：2017. Grid Game (https://leetcode.com/problems/grid-game/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> presum(2, vector<long long>(n + 1, 0));
        for (int j = 1; j <= n; j++)
        {
            presum[0][j] = presum[0][j - 1] + grid[0][j - 1];
            presum[1][j] = presum[1][j - 1] + grid[1][j - 1];
        }
        long long ans = 2e18;
        for (int i = 1; i <= n; i++)
            ans = min<long long>(ans, max<long long>(presum[0][n] - presum[0][i], presum[1][i - 1]));
        return ans;
    }
};
