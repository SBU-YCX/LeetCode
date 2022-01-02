# [2124. Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/)


## Description:

<p>Given a string <code>s</code> consisting of <strong>only</strong> the characters <code>'a'</code> and <code>'b'</code>, return <em><code>true</code> if <strong>every</strong> <code>'a'</code> appears before <strong>every</strong> <code>'b'</code> in the string.</em> Otherwise, return <em><code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "aaabbb"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "abab"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "bbb"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code></li>
    <li><code>s[i]</code> is either <code>'a'</code> or <code>'b'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Find the position <code>pa</code> of the left-most <code>'b'</code> and the position <code>pb</code> of the right-most <code>'a'</code>, we need <code>pa &lt; pb</code>. There are two special cases: <code>pa == -1</code> or <code>pb == -1</code>, i.e. no <code>'a'</code> or no <code>'b'</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2124. Check if All A's Appears Before All B's (https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool checkString(string s) {
        int pa = s.find_last_of('a'), pb = s.find('b');
        if (pa == -1 || pb == -1)
            return true;
        return (pa < pb);
    }
};
```
