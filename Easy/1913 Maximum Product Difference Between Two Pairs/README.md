# [1913. Maximum Product Difference Between Two Pairs](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/)


## Description:

<p>The <strong>product difference</strong> between two pairs <code>(a, b)</code> and <code>(c, d)</code> is defined as <code>(a * b) - (c * d)</code>.</p>

<ul>
    <li>For example, the product difference between <code>(5, 6)</code> and <code>(2, 7)</code> is <code>(5 * 6) - (2 * 7) = 16</code>.</li>
</ul>

<p>Given an integer array <code>nums</code>, choose four <strong>distinct</strong> indices <code>w</code>, <code>x</code>, <code>y</code>, and <code>z</code> such that the <strong>product difference</strong> between pairs <code>(nums[w], nums[x])</code> and <code>(nums[y], nums[z])</code> is <strong>maximized</strong>.</p>

<p>Return <em>the <strong>maximum</strong> such product difference.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [5,6,2,7,4]
<strong>Output:</strong> 34
<strong>Explanation:</strong> We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [4,2,5,9,7,4,8]
<strong>Output:</strong> 64
<strong>Explanation:</strong> We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.
</pre>


## Constraints:

<ul>
    <li><code>4 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
    <li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>To make the difference be maximum, clearly we need the first product be maximized and the second product minimized. Since all the elements are positive, the former one should be the product of the maximum two elements while the latter one should be the product of the minimum two elements. So, we can <strong>sort</strong> the array and directly calculate the product difference.</p>


<strong>C++</strong>

```
//  Topic   : 1920. Build Array from Permutation
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(1)


class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        return (nums[m - 1] * nums[m - 2]) - (nums[0] * nums[1]);
    }
};
```