// Topic     : 2088. Count Fertile Pyramids in a Land (https://leetcode.com/problems/count-fertile-pyramids-in-a-land/)
// Author    : YCX
// Time      : O(M * N)
// Space     : O(M * N)


class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int ans = 0;
        ans += count(grid);
        reverse(grid.begin(), grid.end());
        ans += count(grid);
        return ans;
    }
    
private: 
    int count(vector<vector<int>> grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = m - 2; i >= 0; i--)
            for (int j = 1; j < n - 1; j++)
                if (grid[i][j])
                {
                    grid[i][j] = min<int>(grid[i + 1][j], min<int>(grid[i + 1][j - 1], grid[i + 1][j + 1])) + 1;
                    ans += (grid[i][j] - 1);
                }
        return ans;
    }
};
