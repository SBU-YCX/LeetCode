# [2040. Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)


## Description:

<p>Given two <strong>sorted 0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code> as well as an integer <code>k</code>, return <em>the <code>k<sup>th</sup></code> (<strong>1-based</strong>) smallest product of <code>nums1[i] * nums2[j]</code> where <code>0 &lt;= i &lt; nums1.length</code> and <code>0 &lt;= j &lt; nums2.length</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums1 = [2,5], nums2 = [3,4], k = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
<strong>Output:</strong> 0
<strong>Explanation:</strong> The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
<strong>Output:</strong> -6
<strong>Explanation:</strong> The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums1.length, nums2.length &lt;= 5 * 10<sup>4</sup></code></li>
    <li><code>-10<sup>5</sup> &lt;= nums1[i], nums2[j] &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= k &lt;= nums1.length * nums2.length</code></li>
    <li><code>nums1</code> and <code>nums2</code> are sorted.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since there are positive and negative numbers in both arrays, we can first divide both arrays into positive ones and negative ones. Then, using <strong>binary search</strong> to find the answer.</p>


<strong>C++</strong>

```
// Topic     : 2040. Kth Smallest Product of Two Sorted Arrays (https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)
// Author    : YCX 
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
```
