# [1827. Minimum Operations to Make the Array Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/)


## Description:

<p>You are given an integer array <code>nums</code> (<strong>0-indexed</strong>). In one operation, you can choose an element of the array and increment it by <code>1</code>.</p>

<ul>
    <li>For example, if <code>nums = [1,2,3]</code>, you can choose to increment <code>nums[1]</code> to make <code>nums = [1,3,3]</code>.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> number of operations needed to make <code>nums</code> <strong>strictly increasing</strong>.</em></p>

<p>An array <code>nums</code> is <strong>strictly increasing</strong> if <code>nums[i] &lt; nums[i+1]</code> for all <code>0 &lt;= i &lt; nums.length - 1</code>. An array of length <code>1</code> is trivially strictly increasing.</p>

## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,5,2,4,1]
<strong>Output:</strong> 14
<strong>Explanation:</strong>
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [8]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 5000</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the operations only include increment, we can do this in a <strong>greedy</strong> way such that check the elements one-by-one, and increment <code>nums[i]</code> to be <code>nums[i - 1] + 1</code> if <code>nums[i] &lt;= nums[i - 1]</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1827. Minimum Operations to Make the Array Increasing
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] <= nums[i - 1])
            {
                ans += (nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }
        return ans;
    }
};
```