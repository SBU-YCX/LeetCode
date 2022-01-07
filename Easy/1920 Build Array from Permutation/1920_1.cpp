//  Topic   : 1920. Build Array from Permutation
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == i)
                ans.push_back(i);
            else
                ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};
