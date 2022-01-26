# [1588. Sum of All Odd Length Subarrays](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)


## Description:

<p>Given an array of positive integers <code>arr</code>, calculate the sum of all possible odd-length subarrays.</p>

<p>A subarray is a contiguous subsequence of the array.</p>

<p>Return <em>the sum of all odd-length subarrays of <code>arr</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> arr = [1,4,2,5,3]
<strong>Output:</strong> 58
<strong>Explanation:</strong> The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> arr = [1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> arr = [10,11,12]
<strong>Output:</strong> 66
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= arr.length &lt;= 100</code></li>
    <li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Calculate the <strong>prefix sum</strong> of the array, then add all the subarray sums with odd lengths with <strong>brute-force</strong>.</p>


<strong>C++</strong>

```
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
```