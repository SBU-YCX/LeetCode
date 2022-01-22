# [2147. Number of Ways to Divide a Long Corridor](https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/)


## Description:

<p>Along a long library corridor, there is a line of seats and decorative plants. You are given a <strong>0-indexed</strong> string <code>corridor</code> of length <code>n</code> consisting of letters <code>'S'</code> and <code>'P'</code> where each <code>'S'</code> represents a seat and each <code>'P'</code> represents a plant.</p>

<p>One room divider has <strong>already</strong> been installed to the left of index <code>0</code>, and <strong>another</strong> to the right of index <code>n - 1</code>. Additional room dividers can be installed. For each position between indices <code>i - 1</code> and <code>i</code> (<code>1 &lt;= i &lt;= n - 1</code>), at most one divider can be installed.</p>

<p>Divide the corridor into non-overlapping sections, where each section has <strong>exactly two seats</strong> with any number of plants. There may be multiple ways to perform the division. Two ways are <strong>different</strong> if there is a position with a room divider installed in the first way but not in the second way.</p>

<p>Return <em>the number of ways to divide the corridor.</em> Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>. If there is no way, return <em><code>0</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/12/04/1.png)
<pre>
<strong>Input:</strong> corridor = "SSPPSPS"
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already installed.
Note that in each of the ways, each section has exactly two seats.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/12/04/2.png)
<pre>
<strong>Input:</strong> corridor = "PPSPSP"
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only 1 way to divide the corridor, by not installing any additional dividers.
Installing any would create some section that does not have exactly two seats.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/12/12/3.png)
<pre>
<strong>Input:</strong> corridor = "S"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no way to divide the corridor because there will always be a section that does not have exactly two seats.
</pre>


## Constraints:

<ul>
    <li><code>n == corridor.length</code></li>
    <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>corridor[i]</code> is either <code>'S'</code> or <code>'P'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since each section should contain two seats, we need to find the number of possible positions to do the division between each <code>(2 * i)<sup>th</sup></code> and <code>(2 * i + 1)<sup>th</sup></code> seat (1-indexed, <code>i &gt;= 1</code>), i.e. the number of plants between them plus <code>1</code>. The answer is the product of all these numbers. However, if there is no seat at all or the total number of seats is odd, there is no way to do the division to satisfy the condition.</p> 


<strong>C++</strong>

```
// Topic     : 2147. Number of Ways to Divide a Long Corridor
// Author    : YCX 
// Time      : O(N) 
// Space     : O(1)


class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        long long ns = 0, np = 0, ans = 1, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
            {
                ns++;
                if (!(ns % 2))
                {
                    if (ns != 2)
                        ans = (ans * (np + 1)) % mod;
                    np = 0;
                }
            }
            else if (!(ns % 2))
                np++;
        }
        if (ns % 2 || ns == 0)
            return 0;
        return ans;
    }
};
```
