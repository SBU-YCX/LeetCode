// Topic     : 2035. Partition Array Into Two Arrays to Minimize Sum Difference (https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2035%20Partition%20Array%20Into%20Two%20Arrays%20to%20Minimize%20Sum%20Difference)
// Time      : O(2^Nlog(2^N))
// Space     : O(2^N)


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        vector<int> l(nums.begin(), nums.begin() + m), r(nums.begin() + m, nums.end());
        vector<vector<int>> val(m + 1);
        for (int i = 0; i < (1 << m); i++)
        {
            int d = 0, k = __builtin_popcount(i);
            for (int j = 0; j < m; j++)
                d += (i & (1 << j)) ? l[j] : -l[j];
            val[k].push_back(d);
        }
        for (auto& v : val)
            sort(v.begin(), v.end());
        int ans = INT_MAX;
        for (int i = 0; i < (1 << m); i++)
        {
            int d = 0, k = m - __builtin_popcount(i);
            for (int j = 0; j < m; j++)
                d += (i & (1 << j)) ? r[j] : -r[j];
            auto iter = lower_bound(val[k].begin(), val[k].end(), -d);
            if (iter != val[k].begin())
                ans = min<int>(ans, abs(d + *prev(iter)));
            if (iter != val[k].end())
                ans = min<int>(ans, abs(d + *iter));
        }
        return ans;
    }
};
