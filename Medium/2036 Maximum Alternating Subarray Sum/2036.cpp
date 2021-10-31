//  Topic   ：2036. Maximum Alternating Subarray Sum (https://leetcode.com/problems/maximum-alternating-subarray-sum/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        long long ans = nums[0], sum1 = nums[0], sum2 = 0, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (sum1 + nums[i] > nums[i])
                    sum1 += nums[i];
                else
                    sum1 = nums[i];
                sum2 -= nums[i];
            }
            else
            {
                sum1 -= nums[i];
                if (sum2 + nums[i] > nums[i])
                    sum2 += nums[i];
                else
                    sum2 = nums[i];
            }
            ans = max<long long>(ans, sum1);
            ans = max<long long>(ans, sum2);
        }
        return ans;
    }
};
