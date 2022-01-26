# [1614. Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)


## Description:

<p>A string is a <strong>valid parentheses string</strong> (denoted <strong>VPS</strong>) if it meets one of the following:</p>

<ul>
    <li>It is an empty string <code>""</code>, or a single character not equal to <code>"("</code> or <code>")"</code>,</li>
    <li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are <strong>VPS</strong>'s, or</li>
    <li>It can be written as <code>(A)</code>, where <code>A</code> is a <strong>VPS</strong>.</li>
</ul>

<p>We can similarly define the <strong>nesting depth</strong> <code>depth(S)</code> of any VPS <code>S</code> as follows:</p>

<ul>
    <li><code>depth("") = 0</code></li>
    <li><code>depth(C) = 0</code>, where <code>C</code> is a string with a single character not equal to <code>"("</code> or <code>")"</code>.</li>
    <li><code>depth(A + B) = max(depth(A), depth(B))</code>, where <code>A</code> and <code>B</code> are <strong>VPS</strong>'s.</li>
    <li><code>depth("(" + A + ")") = 1 + depth(A)</code>, where <code>A</code> is a <strong>VPS</strong>.</li>
</ul>

<p>For example, <code>""</code>, <code>"()()"</code>, and <code>"()(()())"</code> are <strong>VPS</strong>'s (with nesting depths 0, 1, and 2), and <code>")("</code> and <code>"(()"</code> are not <strong>VPS</strong>'s.</p>

<p>Given a <strong>VPS</strong> represented as string <code>s</code>, return <em>the <strong>nesting depth</strong> of <code>s</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "(1+(2*3)+((8)/4))+1"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Digit 8 is inside of 3 nested parentheses in the string.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "(1)+((2))+(((3)))"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code>
    <li><code>s</code> consists of digits <code>0-9</code> and characters <code>'+'</code>, <code>'-'</code>, <code>'*'</code>, <code>'/'</code>, <code>'('</code>, and <code>')'</code>.</li>
    <li>It is guaranteed that parentheses expression <code>s</code> is a <strong>VPS</strong>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the given <code>s</code> is VPS, we only need to count the number of unpaired <code>'('</code> and the maximum number is the answer. We can use a <strong>stack</strong> to store all the incoming <code>'('</code> and pop one <code>'('</code> out when encountering a <code>')'</code>, then the number of unpaired <code>'('</code> is the size of the stack.</p>


<strong>C++</strong>

```
//  Topic   : 1614. Maximum Nesting Depth of the Parentheses
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int maxDepth(string s) {
        int n = s.length(), ans = 0;
        stack<char> pa;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                pa.push('(');
            else if (s[i] == ')')
                pa.pop();
            ans = max<int>(ans, pa.size());
        }
        return ans;
    }
};
```