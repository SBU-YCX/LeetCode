//  Topic   : 1827. Minimum Operations to Make the Array Increasing
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] <= nums[i - 1])
            {
                ans += (nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }
        return ans;
    }
};
