# [1957. Delete Characters to Make Fancy String](https://leetcode.com/problems/delete-characters-to-make-fancy-string/)


## Description:

<p>A <strong>fancy string</strong> is a string where no <strong>three consecutive</strong> characters are equal.</p>

<p>Given a string <code>s</code>, delete the <strong>minimum</strong> possible number of characters from <code>s</code> to make it <strong>fancy</strong>.</p>

<p>Return <em>the final string after the deletion.</em> It can be shown that the answer will always be <strong>unique</strong>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "leeetcode"
<strong>Output:</strong> "leetcode"
<strong>Explanation:</strong> 
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "aaabaaaa"
<strong>Output:</strong> "aabaa"
<strong>Explanation:</strong>
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "aab"
<strong>Output:</strong> "aab"
<strong>Explanation:</strong> 
No three consecutive characters are equal, so return "aab".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
    <li><code>s</code> consists only of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Check each character in a <strong>greedy</strong> way, such that for each character <code>s[i]</code>, if <code>s[i] == s[i - 1] && s[i] == s[i - 2]</code>, drop the character; otherwise, keep it.</p>


<strong>C++</strong>

```
//  Topic   : 1957. Delete Characters to Make Fancy String
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3)
            return s;
        string ans = "";
        ans += s[0];
        ans += s[1];
        for (int i = 2; i < s.length(); i++)
            if (s[i] != s[i - 1] || s[i] != s[i - 2])
                ans += s[i];
        return ans;
    }
};
```