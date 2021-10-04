//  Topic   : 463. Island Perimeter (https://leetcode.com/problems/island-perimeter/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(1)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j]  == 1)
                {
                    if (i == 0 || i > 0 && grid[i - 1][j] == 0)
                        ans += 1;
                    if (i == m || i < m - 1 && grid[i + 1][j] == 0)
                        ans += 1;
                    if (j == 0 || j > 0 && grid[i][j - 1] == 0)
                        ans += 1;
                    if (j == n || j < n && grid[i][j + 1] == 0)
                        ans += 1;
                }
            }
        return ans;
    }
};
