//  Topic   ：63. Unique Paths II (https://leetcode.com/problems/unique-paths-ii/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(N)


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long> ans(n, 0);
        if (obstacleGrid[m - 1][n - 1] != 1)
            ans[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--)
            if (obstacleGrid[m - 1][j] != 1)
                ans[j] = ans[j + 1];
        for (int i = m - 2; i >= 0; i--)
        {
            if (obstacleGrid[i][n - 1] == 1)
                ans[n - 1] = 0;
            for (int j = n - 2; j >= 0; j--)
            {
                if (obstacleGrid[i][j] != 1)
                    ans[j] += ans[j + 1];
                else
                    ans[j] = 0;
            }
        }
        return ans[0];
    }
};
