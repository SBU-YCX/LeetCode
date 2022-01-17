//  Topic   : 2140. Solving Questions With Brainpower
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; i--)
            dp[i] = max<long long>(dp[i + 1], questions[i][0] + ((questions[i][1] + i + 1 < n) ? dp[questions[i][1] + i + 1] : 0));
        return dp[0];
    }
};
