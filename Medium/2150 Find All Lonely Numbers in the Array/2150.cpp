//  Topic   : 2150. Find All Lonely Numbers in the Array
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && (nums[i] == nums[i - 1] || nums[i] == nums[i - 1] + 1))
                continue;
            if (i < n - 1 && (nums[i] == nums[i + 1] || nums[i] == nums[i + 1] - 1))
                continue;
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
