//  Topic   ：2055. Plates Between Candles (https://leetcode.com/problems/plates-between-candles/)
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(N + M)


class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = 0, idx = -1;
        vector<int> prefix(n, 0), suffix(n, 0), num(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '|')
            {
                idx = i;
                m++;
            }
            prefix[i] = idx;
            num[i] = m;
        }
        idx = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '|')
                idx = i;
            suffix[i] = idx;
        }
        vector<int> ans;
        for (auto q : queries)
        {
            int l = q[0], r = q[1], j = prefix[r], i = suffix[l];
            if (i == -1 || j == -1 || j - i <= 1)
                ans.push_back(0);
            else
            {
                int n_c = num[j] - num[i] + 1;
                ans.push_back(j - i + 1 - n_c);
            }
        }
        return ans;
    }
};
