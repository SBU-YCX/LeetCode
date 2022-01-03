// Topic     : 2025. Maximum Number of Ways to Partition an Array (https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2025%20Maximum%20Number%20of%20Ways%20to%20Partition%20an%20Array)
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        long m = accumulate(nums.begin(), nums.end(), 0L), l = 0, r = 0, d = 0;
        unordered_map<long, int> L, R;
        for (int i = 0; i < n - 1; i++)
        {
            l += nums[i];
            r = m - l;
            R[l - r]++;
        }
        ans = R[0];
        l = 0;
        for (int i = 0; i < n; i++)
        {
            l += nums[i];
            r = m - l;
            d = k - nums[i];
            ans = max<int>(ans, L[d] + R[-d]);
            L[l - r]++;
            R[l - r]--;
        }
        return ans;
    }
};
