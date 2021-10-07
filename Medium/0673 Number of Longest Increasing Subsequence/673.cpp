// Topic     : 673. Number of Longest Increasing Subsequence (https://leetcode.com/problems/number-of-longest-increasing-subsequence/)
// Author    : YCX
// Time      : O(N ^ 2)
// Space     : O(N)


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<vector<int>> ans(n, vector<int>(2, 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
                if (nums[j] < nums[i])
                {
                    if (ans[j][0] + 1 > ans[i][0])
                    {
                        ans[i][0] = ans[j][0] + 1;
                        ans[i][1] = ans[j][1];
                    }
                    else if (ans[j][0] + 1 == ans[i][0])
                        ans[i][1] += ans[j][1];
                }
            res = max<int>(res, ans[i][0]);
        }
        int ans_n = 0;
        for (int i = 0; i < n; i++)
            if (ans[i][0] == res)
                ans_n += ans[i][1];
        return ans_n;
    }
};
