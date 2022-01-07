# [1929. Concatenation of Array](https://leetcode.com/problems/concatenation-of-array/)


## Description:

<p>Given an integer array <code>nums</code> of length <code>n</code>, you want to create an array <code>ans</code> of length <code>2n</code> where <code>ans[i] == nums[i]</code> and <code>ans[i + n] == nums[i]</code> for <code>0 &lt;= i &lt; n</code> (<strong>0-indexed</strong>).</p>

<p>Specifically, <code>ans</code> is the <strong>concatenation</strong> of two <code>nums</code> arrays.</p>

<p>Return <em>the array <code>ans</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,1]
<strong>Output:</strong> [1,2,1,1,2,1]
<strong>Explanation:</strong> The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,3,2,1]
<strong>Output:</strong> [1,3,2,1,1,3,2,1]
<strong>Explanation:</strong> The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
</pre>


## Constraints:

<ul>
    <li><code>n == nums.length</code></li>
    <li><code>1 &lt;= n &lt;= 1000</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Append each element of <code>nums</code> to the end of <code>nums</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1929. Concatenation of Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);
        return nums;
    }
};
```