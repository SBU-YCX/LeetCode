# [343. Integer Break](https://leetcode.com/problems/integer-break/)


## Description:

<p>Given an integer <code>n</code>, break it into the sum of <code>k</code> <strong>positive integers</strong>, where <code>k &gt;= 2</code>, and maximize the product of those integers.</p>
<p>Return <em>the maximum product you can get.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> 2 = 1 + 1, 1 × 1 = 1.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 36
<strong>Explanation:</strong> 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
</pre>


## Constraints:

<ul>
  <li><code>2 &lt;= n &lt;= 58</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>It is a dynamic programming problem, since we need <code>k &gt;= 2</code>, we can use two nested loops, i.e. for each <code>i</code>, divide it to two parts: <code>j</code> and <code>i - j</code> and choose the maximum among the products of them <code>j * prod[i - j]</code>. Since <code>prod[i - j]</code> only includes the maximum after splitting <code>i - j</code>, which may be smaller than <code>i - j</code> itself, so we need also compare <code>max(j * prod[i - j])</code> with <code>j * (i - j)</code>.</p>


<strong>C++</strong>

```
//  Topic   ：343. Integer Break (https://leetcode.com/problems/integer-break/)
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(N)


class Solution {
public:
    int integerBreak(int n) {
        vector<int> prod(n + 1, 0);
        prod[2] = 1;
        for (int i = 3; i <= n; i++)
            for (int j = 1; j < i; j++)
                prod[i] = max<int>(prod[i], j * max<int>(prod[i - j], i - j));
        return prod[n];
    }
};
```