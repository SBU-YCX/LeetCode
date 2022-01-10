// Topic     : 2132. Stamping the Grid
// Author    : YCX 
// Time      : O(M * N) 
// Space     : O(M * N)


class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> blocks(m + 1, vector<int>(n + 1, 0)), stamps(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                blocks[i][j] = blocks[i - 1][j] + blocks[i][j - 1] - blocks[i - 1][j - 1] + grid[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 0 && i >= stampHeight && j >= stampWidth)
                {
                    int k = blocks[i][j] - blocks[i - stampHeight][j] - blocks[i][j - stampWidth] + blocks[i - stampHeight][j - stampWidth];
                    if (k == 0)
                        stamps[i - 1][j - 1] = 1;
                }
            }
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                stamps[i][j] += (stamps[i + 1][j] + stamps[i][j + 1] - stamps[i + 1][j + 1]);
                int x = min<int>(m, i + stampHeight), y = min<int>(n, j + stampWidth);
                int k = stamps[i][j] - stamps[x][j] - stamps[i][y] + stamps[x][y];
                if (grid[i][j] == 0 && k == 0)
                    return false;
            }
        return true;
    }
};
