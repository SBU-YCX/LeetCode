//  Topic   : 1800. Maximum Ascending Subarray Sum
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                sum += nums[i];
            else
            {
                ans = max<int>(ans, sum);
                sum = nums[i];
            }
        }
        ans = max<int>(ans, sum);
        return ans;
    }
};
