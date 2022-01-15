# [1800. Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum/)


## Description:

<p>Given an array of positive integers <code>nums</code>, return <em>the maximum possible sum of an <strong>ascending</strong> subarray in <code>nums</code>.</em></p>

<p>A subarray is defined as a contiguous sequence of numbers in an array.</p>

<p>A subarray <code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code> is <strong>ascending</strong> if for all <code>i</code> where <code>l &lt;= i &lt; r</code>, <code>nums<sub>i</sub> &lt; nums<sub>i+1</sub></code>. Note that a subarray of size <code>1</code> is <strong>ascending</strong>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [10,20,30,5,10,50]
<strong>Output:</strong> 65
<strong>Explanation:</strong> [5,10,50] is the ascending subarray with the maximum sum of 65.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [10,20,30,40,50]
<strong>Output:</strong> 150
<strong>Explanation:</strong> [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [12,17,15,13,10,11,12]
<strong>Output:</strong> 33
<strong>Explanation:</strong> [10,11,12] is the ascending subarray with the maximum sum of 33.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 100</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since all elements are positive, the maximum sum of an ascending subarray will be the sum of the whole subarray, so we can go through the whole array and compare the sums of all ascending subarrays.</p>


<strong>C++</strong>

```
//  Topic   : 1800. Maximum Ascending Subarray Sum
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                sum += nums[i];
            else
            {
                ans = max<int>(ans, sum);
                sum = nums[i];
            }
        }
        ans = max<int>(ans, sum);
        return ans;
    }
};
```