//  Topic   ：442. Find All Duplicates in an Array (https://leetcode.com/problems/find-all-duplicates-in-an-array/)
//  Author  : YCX
//  Time    : O(N * logN)
//  Space   : O(N)


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for (int i = 1; i < n; i++)
            if (nums[i] == nums[i - 1])
                ans.push_back(nums[i]);
        return ans;
    }
};
