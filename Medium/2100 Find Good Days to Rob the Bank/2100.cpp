//  Topic   : 2100. Find Good Days to Rob the Bank (https://leetcode.com/problems/find-good-days-to-rob-the-bank/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size(), m = n - 1;
        vector<vector<int>> range(n, vector<int>(2, 0));
        for (int i = n - 2; i >= 0; i--)
        {
            if (security[i] <= security[i + 1])
                range[i][0] = m - i;
            else
            {
                m = i;
                range[i][0] = m - i;
            }
        }
        m = 0;
        for (int i = 1; i < n; i++)
        {
            if (security[i] <= security[i - 1])
                range[i][1] = i - m;
            else
            {
                m = i;
                range[i][1] = i - m;
            }
        }
        vector<int> ans;
        for (int i = time; i < n - time; i++)
            if (range[i][0] >= time && range[i][1] >= time)
                ans.push_back(i);
        return ans;
    }
};
