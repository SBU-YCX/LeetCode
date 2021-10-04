//  Topic   ：64. Minimum Path Sum (https://leetcode.com/problems/minimum-path-sum/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(M * N)


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    ans[i][j] = grid[i][j];
                else if (i == 0)
                    ans[i][j] = ans[i][j - 1] + grid[i][j];
                else if (j == 0)
                    ans[i][j] = ans[i - 1][j] + grid[i][j];
                else
                    ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]) + grid[i][j];
            }
        return ans[m - 1][n - 1];
    }
};
