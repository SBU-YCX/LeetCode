//  Topic   : 1716. Calculate Money in Leetcode Bank
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    int totalMoney(int n) {
        vector<int> week_sum(7, 0);
        week_sum[0] = 1;
        for (int i = 1; i < 7; i++)
            week_sum[i] = week_sum[i - 1] + i + 1;
        int m = n / 7;
        int r = n % 7;
        int ans = m * week_sum[6] + 7 * (m - 1) * m / 2;
        if (r != 0)
            ans += (week_sum[r - 1] + r * m);
        return ans;
    }
};
