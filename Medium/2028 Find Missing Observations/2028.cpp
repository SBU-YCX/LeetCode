//  Topic   ：2028. Find Missing Observations (https://leetcode.com/problems/find-missing-observations/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), t = mean * (m + n);
        for (int i = 0; i < m; i++)
            t -= rolls[i];
        if (t > n * 6 || t < n)
            return {};
        vector<int> ans (n, 0);
        int d = t / n, r = t % n;
        for (int i = 0; i < n; i++)
        {
            ans[i] = d;
            if (i < r)
                ans[i] += 1;
        }
        return ans;
    }
};
