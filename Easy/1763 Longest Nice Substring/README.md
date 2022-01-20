# [1763. Longest Nice Substring](https://leetcode.com/problems/longest-nice-substring/)


## Description:

<p>A string <code>s</code> is <strong>nice</strong> if, for every letter of the alphabet that <code>s</code> contains, it appears <strong>both</strong> in uppercase and lowercase. For example, <code>"abABB"</code> is nice because <code>'A'</code> and <code>'a'</code> appear, and <code>'B'</code> and <code>'b'</code> appear. However, <code>"abA"</code> is not because <code>'b'</code> appears, but <code>'B'</code> does not.</p>

<p>Given a string <code>s</code>, return <em>the longest <strong>substring</strong> of <code>s</code> that is <strong>nice</strong>. If there are multiple, return the substring of the <strong>earliest</strong> occurrence. If there are none, return an empty string.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "YazaAay"
<strong>Output:</strong> "aAa"
<strong>Explanation:</strong> "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "Bb"
<strong>Output:</strong> "Bb"
<strong>Explanation:</strong> "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "c"
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no nice substrings.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code></li>
    <li><code>s</code> consists of uppercase and lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Whenever we met a character without the other case, make it as a break point and split the string into several substrings, recursively check these substrings in the same way.</p>


<strong>C++</strong>

```
//  Topic   : 1763. Longest Nice Substring
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string longestNiceSubstring(string s) {
        return longestNiceSubstring(s, 0, s.length());
    }
    
private: 
    string longestNiceSubstring(string s, int start, int end)
    {
        vector<vector<int>> freq(26, vector<int>(2, 0));
        for (int i = start; i < end; i++)
        {
            if (s[i] <= 'z' && s[i] >= 'a')
                freq[s[i] - 'a'][0] = 1;
            else if (s[i] <= 'Z' && s[i] >= 'A')
                freq[s[i] - 'A'][1] = 1;
        }
        string ans = "";
        int begin = start - 1;
        for (int i = start; i <= end; i++)
        {
            if (i == end || (s[i] <= 'Z' && s[i] >= 'A' && freq[s[i] - 'A'][0] + freq[s[i] - 'A'][1] == 1) || (s[i] <= 'z' && s[i] >= 'a' && freq[s[i] - 'a'][0] + freq[s[i] - 'a'][1] == 1))
            {
                if (i == end && begin == start - 1)
                    return s.substr(start, end - start);
                string res = longestNiceSubstring(s, begin + 1, i);
                if (res.length() > ans.length())
                    ans = res;
                begin = i;
            }
        }
        return ans;
    }
};
```