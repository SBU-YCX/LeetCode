# [1758. Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)


## Description:

<p>You are given a string <code>s</code> consisting only of the characters <code>'0'</code> and <code>'1'</code>. In one operation, you can change any <code>'0'</code> to <code>'1'</code> or vice versa.</p>

<p>The string is called alternating if no two adjacent characters are equal. For example, the string <code>"010"</code> is alternating, while the string <code>"0100"</code> is not.</p>

<p>Return <em>the <strong>minimum</strong> number of operations needed to make <code>s</code> alternating.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "0100"
<strong>Output:</strong> 1
<strong>Explanation:</strong> If you change the last character to '1', s will be "0101", which is alternating.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "10"
<strong>Output:</strong> 0
<strong>Explanation:</strong> s is already alternating.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "1111"
<strong>Output:</strong> 2
<strong>Explanation:</strong> You need two operations to reach "0101" or "1010".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
    <li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>There are only two possible alternating ways, <code>"0101..."</code> or <code>"1010..."</code>, compare the number of operations needed in these two cases.</p>


<strong>C++</strong>

```
//  Topic   : 1758. Minimum Changes To Make Alternating Binary String
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minOperations(string s) {
        int op_0 = 0, op_1 = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            if ((i % 2) != (s[i] - '0'))
                op_0 += 1;
            if (((i + 1) % 2) != (s[i] - '0'))
                op_1 += 1;
        }
        return min<int>(op_0, op_1);
    }
};
```