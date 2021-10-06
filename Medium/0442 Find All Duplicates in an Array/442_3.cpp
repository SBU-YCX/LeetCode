//  Topic   ：442. Find All Duplicates in an Array (https://leetcode.com/problems/find-all-duplicates-in-an-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            nums[abs(nums[i]) - 1] *= -1;
            if (nums[abs(nums[i]) - 1] > 0)
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};
