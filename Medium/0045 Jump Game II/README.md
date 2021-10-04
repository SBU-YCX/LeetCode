# [45. Jump Game II](https://leetcode.com/problems/jump-game-ii/)


## Description:

<p>Given an array of non-negative integers <code>nums</code>, you are initially positioned at the first index of the array.</p>
<p>Each element in the array represents your maximum jump length at that position.</p>
<p>Your goal is to reach the last index in the minimum number of jumps.</p>
<p>You can assume that you can always reach the last index.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,3,0,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Traverse the whole array backward, for each index <code>i</code>, check whether the last index is reachable through one jump from it, if not, find the index within its jump length with the minimum number jumps to the last index and plus one.</p>


<strong>C++</strong>

```
//  Topic   ：45. Jump Game II (https://leetcode.com/problems/jump-game-ii/)
//  Author  : YCX
//  Time    : O(N * N)
//  Space   : O(N)


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> num(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] >= n - 1 - i)
                num[i] = 1;
            else if (nums[i] == 0)
                num[i] = 1e5;
            else
            {
                int min_num = 1e5;
                for (int j = 1; j <= nums[i]; j++)
                    min_num = min<int>(min_num, num[i + j]);
                num[i] = min_num + 1;
            }
        }
        return num[0];
    }
};
```