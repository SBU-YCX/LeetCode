# [1848. Minimum Distance to the Target Element](https://leetcode.com/problems/minimum-distance-to-the-target-element/)


## Description:

<p>Given an integer array <code>nums</code> (<strong>0-indexed</strong>) and two integers <code>target</code> and <code>start</code>, find an index <code>i</code> such that <code>nums[i] == target</code> and <code>abs(i - start)</code> is <strong>minimized</strong>. Note that <code>abs(x)</code> is the absolute value of <code>x</code>.</p>

<p>Return <em><code>abs(i - start)</code>.</em></p>

<p>It is <strong>guaranteed</strong> that <code>target</code> exists in <code>nums</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3,4,5], target = 5, start = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1], target = 1, start = 0
<strong>Output:</strong> 0
<strong>Explanation:</strong> nums[0] = 1 is the only value equal to target, so the answer is abs(0 - 0) = 0.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
<strong>Output:</strong> 0
<strong>Explanation:</strong> Every value of nums is 1, but nums[0] minimizes abs(i - start), which is abs(0 - 0) = 0.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
    <li><code>0 &lt;= start &lt; nums.length</code></li>
    <li><code>target</code> is in <code>nums</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Iterate along both directions from <code>start</code>, whenever we first time meet <code>target</code>, we find the answer.</p>


<strong>C++</strong>

```
//  Topic   : 1848. Minimum Distance to the Target Element
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int m = nums.size();
        for (int i = 0; i <= max<int>(start, m - start); i++)
        {
            if (start + i < m && nums[start + i] == target)
                return i;
            if (start - i >= 0 && nums[start - i] == target)
                return i;
        }
        return 0;
    }
};
```