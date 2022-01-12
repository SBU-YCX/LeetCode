# [1837. Sum of Digits in Base K](https://leetcode.com/problems/sum-of-digits-in-base-k/)


## Description:

<p>Given an integer <code>n</code> (in base <code>10</code>) and a base <code>k</code>, return <em>the <strong>sum</strong> of the digits of <code>n</code> <strong>after</strong> converting <code>n</code> from base <code>10</code> to base <code>k</code>.</em></p>

<p>After converting, each digit should be interpreted as a base <code>10</code> number, and the sum should be returned in base <code>10</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 34, k = 6
<strong>Output:</strong> 9
<strong>Explanation:</strong> 34 (base 10) expressed in base 6 is 54. 5 + 4 = 9.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 10, k = 10
<strong>Output:</strong> 1
<strong>Explanation:</strong> n is already in base 10. 1 + 0 = 1.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= n &lt;= 100</code></li>
    <li><code>2 &lt;= k &lt;= 10</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the modulation process.</p>


<strong>C++</strong>

```
//  Topic   : 1837. Sum of Digits in Base K
//  Author  : YCX
//  Time    : O(logN)
//  Space   : O(1)


class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        while (n != 0)
        {
            ans += (n % k);
            n /= k;
        }
        return ans;
    }
};
```