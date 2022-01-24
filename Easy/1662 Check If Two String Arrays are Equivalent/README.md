# [1662. Check If Two String Arrays are Equivalent(https://leetcode.com/problems/maximum-repeating-substring/)


## Description:

<p>Given two string arrays <code>word1</code> and <code>word2</code>, return <em><code>true</code> if the two arrays <strong>represent</strong> the same string, and <code>false</code> otherwise.</em></p>

<p>A string is <strong>represented</strong> by an array if the array elements concatenated <strong>in order</strong> forms the string.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word1 = ["ab", "c"], word2 = ["a", "bc"]
<strong>Output:</strong> true
<strong>Explanation:</strong>
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word1 = ["a", "cb"], word2 = ["ab", "c"]
<strong>Output:</strong> false
<strong>Explanation:</strong>
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
<strong>Output:</strong> true
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= word1.length, word2.length &lt;= 10<sup>3</sup></code></li>
    <li><code>1 &lt;= word1[i].length, word2[i].length &lt;= 10<sup>3</sup></code></li>
    <li><code>1 &lt;= sum(word1[i].length), sum(word2[i].length) &lt;= 10<sup>3</sup></code></li>
    <li><code>word1[i]</code> and <code>word2[i]</code> consist of lowercase letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Append all the strings in <code>word1</code> as <code>s1</code>, append all the strings in <code>word2</code> as <code>s2</code>, compare <code>s1</code> and <code>s2</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1662. Check If Two String Arrays are Equivalent
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for (int i = 0; i < word1.size(); i++)
            s1 += word1[i];
        for (int j = 0; j < word2.size(); j++)
            s2 += word2[j];
        return (s1 == s2);
    }
};
```