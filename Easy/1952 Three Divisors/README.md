# [1952. Three Divisors](https://leetcode.com/problems/three-divisors/)


## Description:

<p>Given an integer <code>n</code>, return <em><code>true</code> if <code>n</code> has <strong>exactly three positive divisors</strong>. Otherwise, return <code>false</code>.</em></p>

<p>An integer <code>m</code> is a <strong>divisor</strong> of <code>n</code> if there exists an integer <code>k</code> such that <code>n = k * m</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> false
<strong>Explanation:</strong> 2 has only two divisors: 1 and 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> true
<strong>Explanation:</strong> 4 has three divisors: 1, 2, and 4.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>If <code>n</code> has only three divisors, they must be <code>1</code>, <code>n</code> and <code>sqrt(n)</code>. If <code>n</code> has other divisors, return <code>false</code>. So, check all the numbers in <code>[sqrt(n) + 1, n)</code> one by one.</p>


<strong>C++</strong>

```
//  Topic   : 1952. Three Divisors
//  Author  : YCX
//  Time    : O(sqrt(N))
//  Space   : O(1)


class Solution {
public:
    bool isThree(int n) {
        if (n == 1)
            return false;
        int num = 2;
        for (int i = int(sqrt(n)) + 1; i < n; i++)
            if (n % i == 0)
                return false;
        if (int(sqrt(n)) * int(sqrt(n)) == n)
            return true;
        return false;
    }
};
```