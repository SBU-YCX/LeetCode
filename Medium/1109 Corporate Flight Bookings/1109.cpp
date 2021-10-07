// Topic     : 1109. Corporate Flight Bookings (https://leetcode.com/problems/corporate-flight-bookings/)
// Author    : YCX
// Time      : O(M + N)
// Space     : O(N)


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m = bookings.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < m; i++)
        {
            ans[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < n)
                ans[bookings[i][1]] -= bookings[i][2];
        }
        for (int i = 1; i < n; i++)
            ans[i] += ans[i - 1];
        return ans;
    }
};
