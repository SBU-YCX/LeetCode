# [1844. Replace All Digits with Characters](https://leetcode.com/problems/replace-all-digits-with-characters/)


## Description:

<p>You are given a <strong>0-indexed</strong> string <code>s</code> that has lowercase English letters in its <strong>even</strong> indices and digits in its <strong>odd</strong> indices.</p>

<p>There is a function <code>shift(c, x)</code>, where <code>c</code> is a character and <code>x</code> is a digit, that returns the <code>x<sup>th</sup></code> character after <code>c</code>.</p>

<ul>
    <li>For example, <code>shift('a', 5) = 'f'</code> and <code>shift('x', 0) = 'x'</code>.</li>
</ul>

<p>For every <strong>odd</strong> index <code>i</code>, you want to replace the digit <code>s[i]</code> with <code>shift(s[i-1], s[i])</code>.</p> 

<p>Return <em><code>s</code> after replacing all digits. It is <strong>guaranteed</strong> that <code>shift(s[i-1], s[i])</code> will never exceed <code>'z'</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "a1c1e1"
<strong>Output:</strong> "abcdef"
<strong>Explanation:</strong> The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('c',1) = 'd'
- s[5] -> shift('e',1) = 'f'
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "a1b2c3d4e"
<strong>Output:</strong> "abbdcfdhe"
<strong>Explanation:</strong> The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('b',2) = 'd'
- s[5] -> shift('c',3) = 'f'
- s[7] -> shift('d',4) = 'h'
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code></li>
    <li><code>s</code> consists only of lowercase English letters and digits.</li>
    <li><code>shift(s[i-1], s[i]) &lt;= 'z'</code> for all <strong>odd</strong> indices <code>i</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the shift process.</p>


<strong>C++</strong>

```
//  Topic   : 1844. Replace All Digits with Characters
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.length(); i += 2)
            s[i] = (s[i - 1] + (s[i] - '0'));
        return s;
    }
};
```