//  Topic   : 1572. Matrix Diagonal Sum
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (2 * i == n - 1)
                ans += mat[i][i];
            else
            {
                ans += mat[i][i];
                ans += mat[i][n - 1 - i];
            }
        }
        return ans;
    }
};
