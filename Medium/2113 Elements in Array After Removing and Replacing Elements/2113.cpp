//  Topic   ：2113. Elements in Array After Removing and Replacing Elements (https://leetcode.com/problems/elements-in-array-after-removing-and-replacing-elements/)
//  Author  : YCX
//  Time    : O(M)
//  Space   : O(1)


class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int t = queries[i][0] % (2 * n);
            if (t <= n)
            {
                int j = queries[i][1] + t;
                if (j >= n)
                    ans.push_back(-1);
                else
                    ans.push_back(nums[j]);
            }
            else
            {
                int j = queries[i][1], k = t - n - 1;
                if (j > k)
                    ans.push_back(-1);
                else
                    ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};
