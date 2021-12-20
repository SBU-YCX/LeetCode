//  Topic   ：2110. Number of Smooth Descent Periods of a Stock (https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return n;
        long long ans = 0;
        for (int i = 1, j = 0; i <= n; i++)
        {
            if (i == n || prices[i] != prices[i - 1] - 1)
            {
                ans += (long long)(i - j) * (i - j  + 1) / 2;
                j = i;
            }
        }
        return ans;
    }
};
