# [1624. Largest Substring Between Two Equal Characters](https://leetcode.com/problems/largest-substring-between-two-equal-characters/)


## Description:

<p>Given a string <code>s</code>, return <em>the length of the longest substring between two equal characters, excluding the two characters.</em> If there is no such substring return <em><code>-1</code>.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "aa"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The optimal substring here is an empty substring between the two 'a's.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "abca"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The optimal substring here is "bc".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "cbzxy"
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no characters that appear twice in s.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 300</code></li>
    <li><code>s</code> contains only lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Keep record of the index for each character when it appears for the first time, then, each time we meet a character <code>s[i]</code>, compare <code>i - loc[s[i]] - 1</code> with answer and find the maximum one.</p>


<strong>C++</strong>

```
//  Topic   : 1624. Largest Substring Between Two Equal Characters
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(26)


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<int> loc(26, -1);
        for (int i = 0; i < s.length(); i++)
        {
            if (loc[s[i] - 'a'] == -1)
                loc[s[i] - 'a'] = i;
            else
                ans = max<int>(ans, i - loc[s[i] - 'a'] - 1);
        }
        return ans;
    }
};
```