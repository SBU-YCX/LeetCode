# [1876. Substrings of Size Three with Distinct Characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)


## Description:

<p>A string is <strong>good</strong> if there are no repeated characters.</p>

<p>Given a string <code>s</code>, return <em>the number of <strong>good substrings</strong> of length <strong>three</strong> in <code>s</code>.</em></p>

<p>Note that if there are multiple occurrences of the same substring, every occurrence should be counted.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "xyzzaz"
<strong>Output:</strong> 1
<strong>Explanation:</strong> There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "aababcabc"
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code></li>
    <li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Check each <strong>sliding window</strong> of size <code>3</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1876. Substrings of Size Three with Distinct Characters
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i < s.length() - 2; i++)
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i])
                ans += 1;
        return ans;
    }
};
```