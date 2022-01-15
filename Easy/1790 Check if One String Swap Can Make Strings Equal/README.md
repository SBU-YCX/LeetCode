# [1790. Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)


## Description:

<p>You are given two strings <code>s1</code> and <code>s2</code> of equal length. A <strong>string swap</strong> is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.</p>

<p>Return <em><code>true</code> if it is possible to make both strings equal by performing <strong>at most one string swap</strong> on <strong>exactly one</strong> of the strings.</em> Otherwise, return <em><code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s1 = "bank", s2 = "kanb"
<strong>Output:</strong> true
<strong>Explanation:</strong> For example, swap the first character with the last character of s2 to make "bank".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s1 = "attack", s2 = "defend"
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to make them equal with one string swap.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s1 = "kelb", s2 = "kelb"
<strong>Output:</strong> true
<strong>Explanation:</strong> The two strings are already equal, so no string swap operation is required.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s1.length, s2.length &lt;= 100</code></li>
    <li><code>s1.length == s2.length</code></li>
    <li><code>s1</code> and <code>s2</code> consist of only lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Store the mismatched pairs in a vector <code>cache</code>, check the size of <code>cache</code></p>

<ul>
    <li><code>cache.size() &gt;= 3</code>, need more than one swap</li>
    <li><code>cache.size() == 2</code>, need <code>cache[0][0] == cache[1][1] && cache[0][1] == cache[1][0]</code></li>
    <li><code>cache.size() == 1</code>, cannot swap</li>
    <li><code>cache.size() == 0</code>, no need to swap</li>
</ul>


<strong>C++</strong>

```
//  Topic   : 1790. Check if One String Swap Can Make Strings Equal
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        vector<vector<char>> cache;
        for (int i = 0; i < s1.length(); i++)
            if (s1[i] != s2[i])
            {
                cache.push_back({s1[i], s2[i]});
                if (cache.size() >= 3)
                    return false;
            }
        if (cache.size() == 1)
            return false;
        if (cache[0][0] == cache[1][1] && cache[0][1] == cache[1][0])
            return true;
        return false;
    }
};
```