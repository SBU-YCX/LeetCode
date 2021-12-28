//  Topic   : 2016. Maximum Difference Between Increasing Elements (https://leetcode.com/problems/maximum-difference-between-increasing-elements/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int m = nums.size(), minv = nums[0], ans = 0;
        for (int i = 1; i < m; i++)
        {
            ans = max<int>(ans, nums[i] - minv);
            minv = min<int>(minv, nums[i]);
        }
        if (ans == 0)
            return -1;
        return ans;
    }
};
