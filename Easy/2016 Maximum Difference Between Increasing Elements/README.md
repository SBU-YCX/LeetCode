# [2016. Maximum Difference Between Increasing Elementsy](https://leetcode.com/problems/maximum-difference-between-increasing-elements/)


## Description:

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code>, find the <strong>maximum difference</strong> between <code>nums[i]</code> and <code>nums[j]</code> (i.e., <code>nums[j] - nums[i]</code>), such that <code>0 &lt;= i &lt; j &lt; n</code> and <code>nums[i] &lt; nums[j]</code>.</p>

<p>Return <em>the <strong>maximum difference</strong>.</em> If no such <code>i</code> and <code>j</code> exists, return <em><code>-1</code></em>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [7,<strong>1</strong>,<strong>5</strong>,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [9,4,3,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
There is no i and j such that i < j and nums[i] < nums[j].
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [<strong>1</strong>,5,2,<strong>10</strong>]
<strong>Output:</strong> 9
<strong>Explanation:</strong> 
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.
</pre>


## Constraints:

<ul>
    <li><code>n == nums.length</code></li>
    <li><code>2 &lt;= n &lt;= 1000</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Go through the whole array from left to right, using a variable <code>minv</code> to store the minimum value, for each element <code>i</code>, update the maximum difference <code>ans = max(ans, nums[i] - minv)</code> as well as the minimum value <code>minv = min(minv, nums[i])</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2016. Maximum Difference Between Increasing Elements (https://leetcode.com/problems/maximum-difference-between-increasing-elements/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int m = nums.size(), minv = nums[0], ans = 0;
        for (int i = 1; i < m; i++)
        {
            ans = max<int>(ans, nums[i] - minv);
            minv = min<int>(minv, nums[i]);
        }
        if (ans == 0)
            return -1;
        return ans;
    }
};
```
