# [1784. Check if Binary String Has at Most One Segment of Ones](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)


## Description:

<p>Given a binary string <code>s</code> <strong>without leading zeros</strong>, return <em><code>true</code> if <code>s</code> contains <strong>at most one contiguous segment of ones</strong>.</em> Otherwise, return <em><code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "1001"
<strong>Output:</strong> false
<strong>Explanation:</strong> The ones do not form a contiguous segment.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "110"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code></li>
    <li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
    <li><code>s[0]</code> is <code>'1'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Find the first <code>'0'</code> in <code>s</code>, then check if there are any <code>'1'</code>s after the first <code>'0'</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1784. Check if Binary String Has at Most One Segment of Ones
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool checkOnesSegment(string s) {
        int r = s.length(), l = s.find('0');
        if (l == -1)
            return true;
        int p = s.find('1', l);
        return (p == -1);
    }
};
```
