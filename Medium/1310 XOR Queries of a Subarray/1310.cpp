// Topic     : 1310. XOR Queries of a Subarray (https://leetcode.com/problems/xor-queries-of-a-subarray/)
// Author    : YCX
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        vector<int> prexor(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prexor[i] = prexor[i - 1] ^ arr[i - 1];
        vector<int> ans;
        for (int i = 0; i < m; i++)
            ans.push_back(prexor[queries[i][1] + 1] ^ prexor[queries[i][0]]);
        return ans;
    }
};
