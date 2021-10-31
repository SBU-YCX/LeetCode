//  Topic   ：2033. Minimum Operations to Make a Uni-Value Grid (https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(N * M)


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> element(m * n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                element[i * n + j] = grid[i][j];
        sort(element.begin(), element.end());
        for (int i = 1; i < m * n; i++)
        {
            element[i] -= element[0];
            if (element[i] % x != 0)
                return -1;
        }
        element[0] = 0;
        int p = (m * n) / 2, ans = 0;
        for (int i = 0; i < m * n; i++)
            ans += (abs(element[i] - element[p]) / x);
        return ans;
    }
};
