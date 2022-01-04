//  Topic   : 2006. Count Number of Pairs With Absolute Difference K
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> f;
        for (int i = 0; i < n; i++)
        {
            ans += (f[nums[i] - k] + f[nums[i] + k]);
            f[nums[i]]++;
        }
        return ans;
    }
};
