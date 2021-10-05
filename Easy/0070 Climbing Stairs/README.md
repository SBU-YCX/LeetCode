# [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)


## Description:

<p>You are climbing a staircase. It takes <code>n</code> steps to reach the top.</p>
<p>Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to the top?</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= n &lt;= 45</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since each time we can only climb <code>1</code> or <code>2</code> steps, for each stair <code>i</code>, the number of distinct ways to the top, noted as <code>ans[i]</code>, is the sum of <code>ans[i + 1]</code> and <code>ans[i + 2]</code>. For simplification, we can use only two variables instead of an array.</p>


<strong>C++</strong>

```
//  Topic   : 70. Climbing Stairs (https://leetcode.com/problems/climbing-stairs/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2, ans;
        if (n == 1)
            return a;
        else if (n == 2)
            return b;
        else
        {
            for (int i = n - 3; i >= 0; i--)
            {
                ans = a + b;
                a = b;
                b = ans;
            }
        }
        return ans;
    }
};
```