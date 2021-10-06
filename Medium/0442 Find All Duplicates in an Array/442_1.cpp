//  Topic   ：442. Find All Duplicates in an Array (https://leetcode.com/problems/find-all-duplicates-in-an-array/)
//  Author  : YCX
//  Time    : O(N) average, O(N^2) worst
//  Space   : O(N)


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (freq[nums[i]] == 1)
                ans.push_back(nums[i]);
            else
                freq[nums[i]] = 1;
        }
        return ans;
    }
};
