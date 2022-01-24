# [1668. Maximum Repeating Substring](https://leetcode.com/problems/maximum-repeating-substring/)


## Description:

<p>For a string <code>sequence</code>, a string <code>word</code> is <strong><code>k</code>-repeating</strong> if <code>word</code> concatenated <code>k</code> times is a substring of <code>sequence</code>. The <code>word</code>'s <strong>maximum <code>k</code>-repeating value</strong> is the highest value <code>k</code> where <code>word</code> is <code>k</code>-repeating in <code>sequence</code>. If <code>word</code> is not a substring of <code>sequence</code>, <code>word</code>'s maximum <code>k</code>-repeating value is <code>0</code>.</p>

<p>Given strings <code>sequence</code> and <code>word</code>, return <em>the <strong>maximum <code>k</code>-repeating value</strong> of <code>word</code> in <code>sequence</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> sequence = "ababc", word = "ab"
<strong>Output:</strong> 2
<strong>Explanation:</strong> "abab" is a substring in "ababc".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> sequence = "ababc", word = "ba"
<strong>Output:</strong> 1
<strong>Explanation:</strong> "ba" is a substring in "ababc". "baba" is not a substring in "ababc".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> sequence = "ababc", word = "ac"
<strong>Output:</strong> 0
<strong>Explanation:</strong> "ac" is not a substring in "ababc".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= sequence.length &lt;= 100</code></li>
    <li><code>1 &lt;= word.length &lt;= 100</code></li>
    <li><code>sequence</code> and <code>word</code> contains only lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using <strong>dynamic programming</strong> and check each substring of <code>sequence</code> with length <code>word.length</code> from right to left.</p>


<strong>C++</strong>

```
//  Topic   : 1668. Maximum Repeating Substring
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(N)


class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m = sequence.length(), n = word.length();
        if (m < n)
            return 0;
        int ans = 0;
        vector<int> match(m + 1, 0);
        for (int i = m - n; i >= 0; i--)
        {
            if (sequence.substr(i, n) == word)
                match[i] = 1 + match[i + n];
            else
                match[i] = 0;
            ans = max<int>(ans, match[i]);
        }
        return ans;       
    }
};
```