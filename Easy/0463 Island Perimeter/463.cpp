//  Topic   : 463. Island Perimeter (https://leetcode.com/problems/island-perimeter/)
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(1)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j]  == 1)
                {
                    if (i == 0 || i > 0 && grid[i - 1][j] == 0)
                        ans += 1;
                    if (i == grid.size() - 1 || i < grid.size() - 1 && grid[i + 1][j] == 0)
                        ans += 1;
                    if (j == 0 || j > 0 && grid[i][j - 1] == 0)
                        ans += 1;
                    if (j == grid[0].size() - 1 || j < grid[0].size() - 1 && grid[i][j + 1] == 0)
                        ans += 1;
                }
            }
        return ans;
    }
};
