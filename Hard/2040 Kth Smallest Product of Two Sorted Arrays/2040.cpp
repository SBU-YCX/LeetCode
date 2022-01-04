// Topic     : 2040. Kth Smallest Product of Two Sorted Arrays (https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2040%20Kth%20Smallest%20Product%20of%20Two%20Sorted%20Arrays)
// Time      : O((M + N)log(10^10))
// Space     : O(M + N)


class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size(), m = nums2.size();
        vector<long long> n11, n12, n21, n22;
        for (auto& i : nums1)
        {
            if (i >= 0)
                n11.push_back(i);
            else
                n12.push_back(-i);
        }
        for (auto& j : nums2)
        {
            if (j >= 0)
                n21.push_back(j);
            else
                n22.push_back(-j);
        }
        reverse(n12.begin(), n12.end());
        reverse(n22.begin(), n22.end());
        long long nn = n11.size() * n22.size() + n12.size() * n21.size();
        int sign;
        if (k > nn)
        {
            k -= nn;
            sign = 1;
        }
        else
        {
            k = nn - k + 1;
            swap(n21, n22);
            sign = -1;
        }
        long long l = 0, r = 1e10;
        while (l < r)
        {
            long long p = l + (r - l) / 2;
            if (count(n11, n21, p) + count(n12, n22, p) >= k)
                r = p;
            else
                l = p + 1;
        }
        return (l * sign);
    }
    
private: 
    long long count(vector<long long>& a, vector<long long>& b, long long& p)
    {
        long long ans = 0;
        int j = b.size() - 1;
        for (int i = 0; i < a.size(); i++)
        {
            while (j >= 0 && a[i] * b[j] > p)
                j--;
            ans += (j + 1);
        }
        return ans;
    }
};
