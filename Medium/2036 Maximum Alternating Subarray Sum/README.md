# [2036. Maximum Alternating Subarray Sum](https://leetcode.com/problems/maximum-alternating-subarray-sum/)


## Description:

<p>A <strong>subarray</strong> of a <strong>0-indexed</strong> integer array is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>
<p>The <strong>alternating subarray sum</strong> of a subarray that ranges from index <code>i</code> to <code>j</code> (<strong>inclusive</strong>, <code>0 &lt;= i &lt;= j &lt; nums.length</code>) is <code>nums[i] - nums[i+1] + nums[i+2] - ... +/- nums[j]</code>.</p>
<p>Given a <strong>0-indexed</strong> integer array nums, return <em>the <strong>maximum alternating subarray sum</strong> of any subarray of <code>nums</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [3,-1,1,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
The subarray [3,-1,1] has the largest alternating subarray sum.
The alternating subarray sum is 3 - (-1) + 1 = 5.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,2,2,2,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The subarrays [2], [2,2,2], and [2,2,2,2,2] have the largest alternating subarray sum.
The alternating subarray sum of [2] is 2.
The alternating subarray sum of [2,2,2] is 2 - 2 + 2 = 2.
The alternating subarray sum of [2,2,2,2,2] is 2 - 2 + 2 - 2 + 2 = 2.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
There is only one non-empty subarray, which is [1].
The alternating subarray sum is 1.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
  <li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can divide this problem into two <strong>dynamic programming</strong> sub-problems: Firstly, if we negate the elements with odd indices, then the problem becomes to find the maximum subarray sum from <code>0</code> to <code>n</code>; Secondly, if we negate the elements with even indices, the problem becomes to find the maximum subarray sum from <code>1</code> to <code>n</code>. For each sub-problem, we can use <strong>Kadane's Algorithm</strong> to solve it, and the answer is the maximum of two sub-optimum.</p>

 
<strong>C++</strong>

```
//  Topic   ：2036. Maximum Alternating Subarray Sum (https://leetcode.com/problems/maximum-alternating-subarray-sum/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        long long ans = nums[0], sum1 = nums[0], sum2 = 0, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (sum1 + nums[i] > nums[i])
                    sum1 += nums[i];
                else
                    sum1 = nums[i];
                sum2 -= nums[i];
            }
            else
            {
                sum1 -= nums[i];
                if (sum2 + nums[i] > nums[i])
                    sum2 += nums[i];
                else
                    sum2 = nums[i];
            }
            ans = max<long long>(ans, sum1);
            ans = max<long long>(ans, sum2);
        }
        return ans;
    }
};
```
