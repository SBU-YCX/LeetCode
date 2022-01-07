# [1961. Check If String Is a Prefix of Array](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/)


## Description:

<p>Given a string <code>s</code> and an array of strings <code>words</code>, determine whether <code>s</code> is a <strong>prefix string</strong> of <code>words</code>.</p>

<p>A string <code>s</code> is a <strong>prefix string</strong> of <code>words</code> if <code>s</code> can be made by concatenating the first <code>k</code> strings in <code>words</code> for some <strong>positive</strong> <code>k</code> no larger than <code>words.length</code>.</p>

<p>Return <em><code>true</code> if <code>s</code> is a <strong>prefix string</strong> of <code>words</code>, or <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "iloveleetcode", words = ["i","love","leetcode","apples"]
<strong>Output:</strong> true
<strong>Explanation:</strong> 
s can be made by concatenating "i", "love", and "leetcode" together.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "iloveleetcode", words = ["apples","i","love","leetcode"]
<strong>Output:</strong> false
<strong>Explanation:</strong>
It is impossible to make s using a prefix of arr.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= words.length &lt;= 100</code></li>
    <li><code>1 &lt;= words[i].length &lt;= 20</code></li>
    <li><code>1 &lt;= s.length &lt;= 1000</code></li>
    <li><code>words[i]</code> and <code>s</code> consist of only lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the concatenating process and see if we can form <code>s</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1961. Check If String Is a Prefix of Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string t = "";
        for (int i = 0; i < words.size(); i++)
        {
            t += words[i];
            if (s == t)
                return true;
        }
        return false;
    }
};
```