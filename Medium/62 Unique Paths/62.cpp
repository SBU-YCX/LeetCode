//  Topic   ：62. Unique Paths (https://leetcode.com/problems/unique-paths/)
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(N)


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> num(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                num[j] += num[j - 1];
        return num[n - 1];
    }
};
