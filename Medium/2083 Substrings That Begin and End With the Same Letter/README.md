# [2083. Substrings That Begin and End With the Same Letter](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/)


## Description:

<p>You are given a <strong>0-indexed</strong> string <code>s</code> consisting of only lowercase English letters. Return <em>the number of <strong>substrings</strong> in <code>s</code> that begin and end with the <strong>same</strong> character.</em></p>

<p>A <strong>substring</strong> is a contiguous non-empty sequence of characters within a string.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "abcba"
<strong>Output:</strong> 7
<strong>Explanation:</strong> 
The substrings of length 1 that start and end with the same letter are: "a", "b", "c", "b", and "a".
The substring of length 3 that starts and ends with the same letter is: "bcb".
The substring of length 5 that starts and ends with the same letter is: "abcba".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "abacad"
<strong>Output:</strong> 9
<strong>Explanation:</strong> 
The substrings of length 1 that start and end with the same letter are: "a", "b", "a", "c", "a", and "d".
The substrings of length 3 that start and end with the same letter are: "aba" and "aca".
The substring of length 5 that starts and ends with the same letter is: "abaca".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "a"
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
The substring of length 1 that starts and ends with the same letter is: "a".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
    <li><code>s</code> consists only of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Go through the whle string <code>s</code>, use an <strong>hash table</strong> <code>freq</code> to count the frequency of each character. Each time we encounter a new character <code>c</code>, increase <code>freq[c]</code> and the number of newly added substrings ended with <code>c</code> is <code>freq[c]</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2083. Substrings That Begin and End With the Same Letter (https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    long long numberOfSubstrings(string s) {
        vector<int> freq(26, 0);
        long long ans = 0;
        for (auto& c : s)
        {
            freq[c - 'a']++;
            ans += freq[c - 'a'];
        }
        return ans;
    }
};
```