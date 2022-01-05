//  Topic   : 1984. Minimum Difference Between Highest and Lowest of K Scores
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(1)


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 100000;
        for (int i = n - 1; i >= k - 1; i--)
            ans = min<int>(ans, nums[i] - nums[i - k + 1]);
        return ans;
    }
};
