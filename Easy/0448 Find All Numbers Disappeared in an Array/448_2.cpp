//  Topic   ：448. Find All Numbers Disappeared in an Array (https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
//  Author  : YCX
//  Time    : O(N * logN)
//  Space   : O(N)


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == n || j < nums[i])
                ans.push_back(j);
            else
                while (i < n && j == nums[i])
                    i++;
        }
        return ans;
    }
};
