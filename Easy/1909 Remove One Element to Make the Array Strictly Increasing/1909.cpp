//  Topic   : 1909. Remove One Element to Make the Array Strictly Increasing
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> groups;
        groups.push_back({nums[0]});
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                groups[groups.size() - 1].push_back(nums[i]);
            else
                groups.push_back({nums[i]});
        }
        if (groups.size() > 2)
            return false;
        else if (groups.size() == 1)
            return true;
        else
        {
            int a = groups[0].size(), b = groups[1].size();
            if (a == 1 || b == 1)
                return true;
            else
            {
                if (groups[0][a - 2] < groups[1][0] || groups[0][a - 1] < groups[1][1])
                    return true;
                else
                    return false;
            }
        }
    }
};
