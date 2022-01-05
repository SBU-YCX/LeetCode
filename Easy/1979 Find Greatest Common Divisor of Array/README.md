# [1979. Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)


## Description:

<p>Given an integer array <code>nums</code>, return <em>the <strong>greatest common divisor</strong> of the smallest number and largest number in <code>nums</code>.</em></p>

<p>The <strong>greatest common divisor</strong> of two numbers is the largest positive integer that evenly divides both numbers.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [2,5,6,9,10]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [7,5,6,8,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= nums.length &lt;= 1000</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Just follow the instructions.</p>


<strong>C++</strong>

```
//  Topic   : 1979. Find Greatest Common Divisor of Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [minv, maxv] = minmax_element(nums.begin(), nums.end());
        return __gcd(*minv, *maxv);
    }
};
```