//  Topic   ：562. Longest Line of Consecutive One in Matrix (https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(M * N)


class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<vector<vector<int>>> ans(m + 2, vector<vector<int>>(n + 2, vector<int>(4, 0)));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (mat[i - 1][j - 1] == 1)
                {
                    res = max<int>(res, ans[i][j][0] = 1 + ans[i][j - 1][0]);
                    res = max<int>(res, ans[i][j][1] = 1 + ans[i - 1][j][1]);
                    res = max<int>(res, ans[i][j][2] = 1 + ans[i - 1][j - 1][2]);
                    res = max<int>(res, ans[i][j][3] = 1 + ans[i - 1][j + 1][3]);
                }
        return res;
    }
};
