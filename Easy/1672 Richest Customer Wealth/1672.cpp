//  Topic   : 1672. Richest Customer Wealth
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(1)


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        int wealth;
        for (int i = 0; i < accounts.size(); i++)
        {
            wealth = 0;
            for (int j = 0; j < accounts[i].size(); j++)
                wealth += accounts[i][j];
            ans = max<int>(ans, wealth);
        }
        return ans;
    }
};
