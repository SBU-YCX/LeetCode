//  Topic   : 2089. Find Target Indices After Sorting Array (https://leetcode.com/problems/find-target-indices-after-sorting-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size(), lt = 0, eq = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
                eq++;
            else if (nums[i] < target)
                lt++;
        }
        for (int j = lt; j < lt + eq; j++)
            ans.push_back(j);
        return ans;
    }
};
