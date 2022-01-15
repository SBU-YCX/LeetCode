# [1768. Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/)


## Description:

<p>You are given two strings <code>word1</code> and <code>word2</code>. Merge the strings by adding letters in alternating order, starting with <code>word1</code>. If a string is longer than the other, append the additional letters onto the end of the merged string.</p>

<p>Return <em>the merged string.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word1 = "abc", word2 = "pqr"
<strong>Output:</strong> "apbqcr"
<strong>Explanation:</strong> The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word1 = "ab", word2 = "pqrs"
<strong>Output:</strong> "apbqrs"
<strong>Explanation:</strong> Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word1 = "abcd", word2 = "pq"
<strong>Output:</strong> "apbqcd"
<strong>Explanation:</strong> Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= word1.length, word2.length &lt;= 100</code></li>
    <li><code>word1</code> and <code>word2</code> consist of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the merging process.</p>


<strong>C++</strong>

```
//  Topic   : 1768. Merge Strings Alternately
//  Author  : YCX
//  Time    : O(max(M, N))
//  Space   : O(1)


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        string ans = "";
        if (m >= n)
        {
            for (int i = 0; i < n; i++)
            {
                ans += word1[i];
                ans += word2[i];
            }
            for (int j = n; j < m; j++)
                ans += word1[j];
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                ans += word1[i];
                ans += word2[i];
            }
            for (int j = m; j < n; j++)
                ans += word2[j];
        }
        return ans;
    }
};
```