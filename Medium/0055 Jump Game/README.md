# [55. Jump Game](https://leetcode.com/problems/jump-game/)


## Description:

<p>You are given an integer array <code>nums</code>. You are initially positioned at the array's <strong>first index</strong>, and each element in the array represents your maximum jump length at that position.</p>
<p>Return <em><code>true</code> if you can reach the last index, or <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> true
<strong>Explanation:</strong> Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [3,2,1,0,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We only need to keep a record of the maximum index we can arrive. For each index <code>i</code> in the array, we check whether <code>i</code> is reachable from previous jumps and update the maximum length we can get. </p>


<strong>C++</strong>

```
//  Topic   ：55. Jump Game (https://leetcode.com/problems/jump-game/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > max_index)
                return false;
            max_index = max<int>(max_index, i + nums[i]);
        }
        return true;
    }
};
```