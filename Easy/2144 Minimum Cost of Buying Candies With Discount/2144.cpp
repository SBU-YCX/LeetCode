//  Topic   : 2144. Minimum Cost of Buying Candies With Discount
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(logN)


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int n = cost.size(), ans = 0;
        for (int i = 0; i < n; i++)
            if (i % 3 != 2)
                ans += cost[i];
        return ans;
    }
};
