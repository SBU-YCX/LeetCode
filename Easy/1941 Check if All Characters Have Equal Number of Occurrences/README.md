# [1941. Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/)


## Description:

<p>Given a string <code>s</code>, return <em><code>true</code> if <code>s</code> is a <strong>good</strong> string, or <code>false</code> otherwise.</em></p>

<p>A string <code>s</code> is <strong>good</strong> if <strong>all</strong> the characters that appear in <code>s</code> have the <strong>same</strong> number of occurrences (i.e., the same frequency).</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "abacbc"
<strong>Output:</strong> true
<strong>Explanation:</strong> The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "aaabb"
<strong>Output:</strong> false
<strong>Explanation:</strong> The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 1000</code></li>
    <li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using a <strong>hash table</strong> to count the frequency of each character in <code>s</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1941. Check if All Characters Have Equal Number of Occurrences
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.length(), k = 0, m = 25;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;
        while (m >= 0 && freq[m] == 0)
            m--;
        k = freq[m];
        while (m >= 0)
        {
            if (freq[m] != k && freq[m] != 0)
                return false;
            m--;
        }
        return true;
    }
};
```