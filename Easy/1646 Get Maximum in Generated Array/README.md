# [1646. Get Maximum in Generated Array](https://leetcode.com/problems/get-maximum-in-generated-array/)


## Description:

<p>You are given an integer <code>n</code>. A <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n + 1</code> is generated in the following way:</p>

<ul>
    <li><code>nums[0] = 0</code></li>
    <li><code>nums[1] = 1</code></li>
    <li><code>nums[2 * i] = nums[i]</code> when <code>2 &lt;= 2 * i &lt;= n</code></li>
    <li><code>nums[2 * i + 1] = nums[i] + nums[i + 1]</code> when <code>2 &lt;= 2 * i + 1 &lt;= n</code></li>
</ul>

<p>Return <em>the <strong>maximum</strong> integer in the array <code>nums</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 7
<strong>Output:</strong> 3
<strong>Explanation:</strong> According to the given rules:
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is max(0,1,1,2,1,3,2,3) = 3.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> According to the given rules, nums = [0,1,1]. The maximum is max(0,1,1) = 1.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> According to the given rules, nums = [0,1,1,2]. The maximum is max(0,1,1,2) = 2.
</pre>


## Constraints:

<ul>
    <li><code>0 &lt;= n &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the generating process.</p>


<strong>C++</strong>

```
//  Topic   : 1646. Get Maximum in Generated Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int getMaximumGenerated(int n) {
        int ans = 0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> nums(n + 1, 0);
        nums[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
                nums[i] = nums[i / 2];
            else
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            ans = max<int>(ans, nums[i]);
        }
        return ans;
    }
};
```