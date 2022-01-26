//  Topic   : 1588. Sum of All Odd Length Subarrays
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(N)


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), m = (n - 1) / 2, ans = 0;
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + arr[i - 1];
        for (int k = 0; k <= m; k++)
        {
            int l = 2 * k + 1;
            int r = n - l;
            for (int j = 0; j <= r; j++)
                ans += (pre[j + l] - pre[j]);
        }
        return ans;
    }
};
