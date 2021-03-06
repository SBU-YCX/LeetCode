//  Topic   ：2070. Most Beautiful Item for Each Query (https://leetcode.com/problems/most-beautiful-item-for-each-query/)
//  Author  : YCX
//  Time    : O(NlogN + MlogM + M + N)
//  Space   : O(M)


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size(), m = items.size(), k = 0, maxv = 0;
        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < n; i++)
            idx[queries[i]].push_back(i);
        sort(items.begin(), items.end());
        sort(queries.begin(), queries.end());
        vector<int> ans(n, 0);
        for (auto lim : queries)
        {
            while (k < m && items[k][0] <= lim)
            {
                maxv = max<int>(maxv, items[k][1]);
                k++;
            }
            for (auto j : idx[lim])
                ans[j] = maxv;
        }
        return ans;
    }
};
