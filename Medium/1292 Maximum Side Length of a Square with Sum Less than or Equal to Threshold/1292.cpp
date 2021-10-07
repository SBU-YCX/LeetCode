// Topic     : 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold (https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)
// Author    : YCX
// Time      : O(M * N + min(M, N))
// Space     : O(M * N)


class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<vector<int>> presum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + mat[i - 1][j - 1];
                int l = min<int>(i, j), p = ans + 1;
                while (p <= l && squaresum(presum, i - p, j - p, i, j) <= threshold)
                {
                    ans = p;
                    p++;
                }
            }
        return ans;
    }
    
private: 
    int squaresum(vector<vector<int>>& presum, int x1, int y1, int x2, int y2)
    {
        return presum[x2][y2] - presum[x2][y1] - presum[x1][y2] + presum[x1][y1];
    }
};
