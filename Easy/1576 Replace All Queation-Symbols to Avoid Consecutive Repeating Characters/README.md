# [1576. Replace All ?'s to Avoid Consecutive Repeating Characters](https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/)


## Description:

<p>Given a string <code>s</code> containing only lowercase English letters and the <code>'?'</code> character, convert <strong>all</strong> the <code>'?'</code> characters into lowercase letters such that the final string does not contain any <strong>consecutive repeating</strong> characters. You <strong>cannot</strong> modify the non <code>'?'</code> characters.</p>

<p>It is <strong>guaranteed</strong> that there are no consecutive repeating characters in the given string <strong>except</strong> for <code>'?'</code>.</p>

<p>Return <em>the final string after all the conversions (possibly zero) have been made.</em> If there is more than one solution, return <strong>any of them</strong>. It can be shown that an answer is always possible with the given constraints.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "?zs"
<strong>Output:</strong> "azs"
<strong>Explanation:</strong> There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "ubv?w"
<strong>Output:</strong> "ubvaw"
<strong>Explanation:</strong> There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code></li>
    <li><code>s</code> consist of lowercase English letters and <code>'?'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the replacement process and try all possible letters for each <code>'?'</code> and see if it will break the condition.</p>


<strong>C++</strong>

```
//  Topic   : 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
//  Author  : YCX
//  Time    : O(26 * N)
//  Space   : O(1)


class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '?')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (i == 0)
                    {
                        if (j + 'a' != s[i + 1])
                        {
                            s[i] = j + 'a';
                            break;
                        }
                    } 
                    else if (i == s.length() - 1)
                    {
                        if (j + 'a' != s[i - 1])
                        {
                            s[i] = j + 'a';
                            break;
                        }
                    }
                    else
                    {
                        if (j + 'a' != s[i + 1] && j + 'a' != s[i - 1])
                        {
                            s[i] = j + 'a';
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};
```
