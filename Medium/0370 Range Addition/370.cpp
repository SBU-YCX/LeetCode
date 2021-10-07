// Topic     : 370. Range Addition (https://leetcode.com/problems/range-addition/)
// Author    : YCX
// Time      : O(M + N)
// Space     : O(N)


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = updates.size();
        vector<int> ans(length, 0);
        for (int i = 0; i < n; i++)
        {
            ans[updates[i][0]] += updates[i][2];
            if (updates[i][1] + 1 < length)
                ans[updates[i][1] + 1] -= updates[i][2];
        }
        for (int i = 1; i < length; i++)
            ans[i] += ans[i - 1];
        return ans;
    }
};
