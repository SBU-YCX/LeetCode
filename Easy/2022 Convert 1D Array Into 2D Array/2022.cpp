//  Topic   : 2022. Convert 1D Array Into 2D Array (https://leetcode.com/problems/convert-1d-array-into-2d-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int k = m * n, j = original.size();
        if (k != j)
            return {};
        for (int i = 0; i < k; i++)
            ans[i / n][i % n] = original[i];
        return ans;
    }
};
