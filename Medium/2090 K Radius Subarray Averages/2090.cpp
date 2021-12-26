//  Topic   : 2090. K Radius Subarray Averages (https://leetcode.com/problems/k-radius-subarray-averages/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        vector<int> ans(n, -1);
        for (int i = k + 1; i <= n - k; i++)
            ans[i - 1] = (prefix[i + k] - prefix[i - k - 1]) / (2 * k + 1);
        return ans;
    }
};
