//  Topic   : 2098. Subsequence of Size K With the Largest Even Sum (https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum/)
//  Author  : YCX
//  Time    : O(NlogN + N)
//  Space   : O(N)


class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        vector<long long> odd, even;
        for (auto& i : nums)
        {
            if (i % 2)
                odd.push_back(i);
            else
                even.push_back(i);
        }
        int m = odd.size(), n = even.size();
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());
        for (int i = 1; i < m; i++)
            odd[i] += odd[i - 1];
        for (int i = 1; i < n; i++)
            even[i] += even[i - 1];
        long long ans = -1;
        if (n >= k)
            ans = even[k - 1];
        if (m >= k && !(k % 2))
            ans = max<long long>(ans, odd[k - 1]);
        for (int i = 1; i < m; i += 2)
            if (i > k - 2 - n && i <= k - 2)
                ans = max<long long>(ans, even[k - i - 2] + odd[i]);
        return ans;
    }
};
