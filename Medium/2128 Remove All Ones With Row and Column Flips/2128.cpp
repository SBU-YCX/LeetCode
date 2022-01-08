//  Topic   : 2128. Remove All Ones With Row and Column Flips
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(1)


class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++)
        {
            int k = grid[0][0] ^ grid[i][0];
            for (int j = 1; j < n; j++)
                if (grid[i][j] ^ grid[0][j] != k)
                    return false;
        }
        return true;
    }
};
