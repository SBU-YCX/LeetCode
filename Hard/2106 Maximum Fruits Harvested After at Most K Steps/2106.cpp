// Topic     : 2106. Maximum Fruits Harvested After at Most K Steps (https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/)
// Author    : YCX
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size(), ans = 0, p = n + 1;
        vector<vector<int>> prefix(n + 1, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            if (fruits[i][0] >= startPos)
                p = min<int>(p, i + 1);
            prefix[i + 1][1] = prefix[i][1] + fruits[i][1];
            prefix[i + 1][0] = abs(startPos - fruits[i][0]);
        }
        int j = p - 1, l = p;
        for (int i = n; i >= p; i--)
        {
            int d = prefix[i][0], r = k - 2 * d, m = 0;
            if (d > k)
                continue;
            while (j > 0 && prefix[j][0] <= r)
                j--;
            m = prefix[i][1] - prefix[j][1];
            ans = max<int>(ans, m);
        }
        for (int i = 1; i < p; i++)
        {
            int d = prefix[i][0], r = k - 2 * d, m = 0;
            if (d > k)
                continue;
            while (l <= n && prefix[l][0] <= r)
                l++;
            m = prefix[l - 1][1] - prefix[i - 1][1];
            ans = max<int>(ans, m);
        }
        return ans;
    }
};
