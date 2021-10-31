# [2059. Minimum Operations to Convert Number](https://leetcode.com/problems/minimum-operations-to-convert-number/)


## Description:

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> containing <strong>distinct</strong> numbers, an integer <code>start</code>, and an integer <code>goal</code>. There is an integer <code>x</code> that is initially set to <code>start</code>, and you want to perform operations on <code>x</code> such that it is converted to <code>goal</code>. You can perform the following operation repeatedly on the number <code>x</code>:</p>
<p>If <code>0 &lt;= x &lt;= 1000</code>, then for any index <code>i</code> in the array (<code>0 &lt;= i &lt; nums.length</code>), you can set <code>x</code> to any of the following:
<ul>
    <li><code>x + nums[i]</code></li>
    <li><code>x - nums[i]</code></li>
    <li><code>x ^ nums[i]</code> (bitwise-XOR)</li>
</ul>
<p>Note that you can use each <code>nums[i]</code> any number of times in any order. Operations that set <code>x</code> to be out of the range <code>0 &lt;= x &lt;= 1000</code> are valid, but no more operations can be done afterward.</p>
<p>Return <em>the <strong>minimum</strong> number of operations needed to convert <code>x = start</code> into <code>goal</code>, and <code>-1</code> if it is not possible.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,3], start = 6, goal = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
We can go from 6 → 7 → 4 with the following 2 operations.
- 6 ^ 1 = 7
- 7 ^ 3 = 4
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,4,12], start = 2, goal = 12
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can go from 2 → 14 → 12 with the following 2 operations.
- 2 + 12 = 14
- 14 - 2 = 12
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [3,5,7], start = 0, goal = -4
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can go from 0 → 3 → -4 with the following 2 operations. 
- 0 + 3 = 3
- 3 - 7 = -4
Note that the last operation sets x out of the range 0 <= x <= 1000, which is valid.
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> nums = [2,8,16], start = 0, goal = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong>
There is no way to convert 0 into 1.
</pre>

<strong>Example 5:</strong>
<pre>
<strong>Input:</strong> nums = [1], start = 0, goal = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong>
We can go from 0 → 1 → 2 → 3 with the following 3 operations. 
- 0 + 1 = 1 
- 1 + 1 = 2
- 2 + 1 = 3
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
  <li><code>-10<sup>9</sup> &lt;= nums[i], goal &lt;= 10<sup>9</sup></code></li>
  <li><code>0 &lt;= start &lt;= 1000</code></li>
  <li><code>start != goal</code></li>
  <li>All the integers in <code>nums</code> are distinct.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can use <strong>Breadth-First Search</strong> to solve this problem. First, since the value of <code>x</code> is limited to <code>[0, 1000]</code>, we can use a vector <code>nums</code> to store the minimum number of operations from <code>start</code> to <code>i</code>, so it becomes the <strong>shortest path problem</strong> and we can use BFS to update them. Since <code>goal</code> may be out of the limited interval, we need another variable <code>ans</code> to record the minimum number of operations to <code>goal</code> during the iteration.</p>

 
<strong>C++</strong>

```
//  Topic   ：2059. Minimum Operations to Convert Number (https://leetcode.com/problems/minimum-operations-to-convert-number/)
//  Author  : YCX
//  Time    : O(1000 * N)
//  Space   : O(1000)


class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int ans = INT_MAX;
        vector<int> num_x(1001, INT_MAX);
        num_x[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int x = q.front(), m = num_x[x];
            q.pop();
            for (auto i : nums)
            {
                int a = x + i;
                if (a <= 1000 && a >= 0 && num_x[a] > m + 1)
                {
                    num_x[a] = m + 1;
                    q.push(a);
                }
                else if (a == goal)
                    ans = min<int>(ans, m + 1);
                a = x - i;
                if (a <= 1000 && a >= 0 && num_x[a] > m + 1)
                {
                    num_x[a] = m + 1;
                    q.push(a);
                }
                else if (a == goal)
                    ans = min<int>(ans, m + 1);
                a = x ^ i;
                if (a <= 1000 && a >= 0 && num_x[a] > m + 1)
                {
                    num_x[a] = m + 1;
                    q.push(a);
                }
                else if (a == goal)
                    ans = min<int>(ans, m + 1);
            }
        }
        if (goal <= 1000 && goal >= 0)
            ans = min<int>(ans, num_x[goal]);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
```
