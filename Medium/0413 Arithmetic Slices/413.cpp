//  Topic   ：413. Arithmetic Slices (https://leetcode.com/problems/arithmetic-slices/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size(), len = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                len += 1;
                ans += len;
            }
            else
                len = 0;
        }
        return ans;
    }
};
