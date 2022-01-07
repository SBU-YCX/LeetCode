# [1925. Count Square Sum Triples](https://leetcode.com/problems/count-square-sum-triples/)


## Description:

<p>A <strong>square triple</strong> <code>(a,b,c)</code> is a triple where <code>a</code>, <code>b</code>, and <code>c</code> are <strong>integers</strong> and <code>a<sup>2</sup> + b<sup>2</sup> = c<sup>2</sup></code>.</p>

<p>Given an integer <code>n</code>, return <em>the number of <strong>square triples</strong> such that <code>1 &lt;= a, b, c &lt;= n</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> The square triples are (3,4,5) and (4,3,5).
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 4
<strong>Explanation:</strong> The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= n &lt;= 250</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Enumerate</strong> all the combinations of <code>a</code> and <code>b</code>, then check whether <code>c = a<sup>2</sup> + b<sup>2</sup></code> is in the range of <code>[1, n<sup>2</sup>]</code> and is a square number, i.e., <code>c == (int)sqrt(c) * (int)sqrt(c)</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1925. Count Square Sum Triples
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(1)


class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 1; i < n; i++)
            for (int j = i; i * i + j * j <= n * n; j++)
            {
                int k = i * i + j * j;
                if (k == int(sqrt(k)) * int(sqrt(k)))
                    ans += 2;
            }
        return ans;
    }
};
```