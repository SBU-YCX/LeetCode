# [1967. Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/)


## Description:

<p>Given an array of strings <code>patterns</code> and a string <code>word</code>, return <em>the <strong>number</strong> of strings in <code>patterns</code> that exist as a <strong>substring</strong> in <code>word</code>.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> patterns = ["a","abc","bc","d"], word = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> patterns = ["a","b","c"], word = "aaaaabbbbb"
<strong>Output:</strong> 2
<strong>Explanation:</strong>
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> patterns = ["a","a","a"], word = "ab"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Each of the patterns appears as a substring in word "ab".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= patterns.length &lt;= 100</code></li>
    <li><code>1 &lt;= patterns[i].length &lt;= 100</code></li>
    <li><code>1 &lt;= word.length &lt;= 100</code></li>
    <li><code>patterns[i]</code> and <code>word</code> consist of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using <strong>brute force</strong> to check each string in <code>patterns</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1967. Number of Strings That Appear as Substrings in Word
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(1)


class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (int i = 0; i < patterns.size(); i++)
        {
            size_t found = word.find(patterns[i]);
            if (found != string::npos)
                ans += 1;
        } 
        return ans;
    }
};
```