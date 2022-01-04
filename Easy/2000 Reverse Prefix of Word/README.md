# [2000. Reverse Prefix of Word](https://leetcode.com/problems/reverse-prefix-of-word/)


## Description:

<p>Given a <strong>0-indexed</strong> string <code>word</code> and a character <code>ch</code>, <strong>reverse</strong> the segment of <code>word</code> that starts at index <code>0</code> and ends at the index of the <strong>first occurrence</strong> of <code>ch</code> (<strong>inclusive</strong>). If the character <code>ch</code> does not exist in <code>word</code>, do nothing.</p>

<ul>
    <li>For example, if <code>word = "abcdefd"</code> and <code>ch = "d"</code>, then you should <strong>reverse</strong> the segment that starts at <code>0</code> and ends at <code>3</code> (<strong>inclusive</strong>). The resulting string will be <code>"dcbaefd"</code>.</li>
</ul>

<p>Return <em>the resulting string.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word = "abcdefd", ch = "d"
<strong>Output:</strong> "dcbaefd"
<strong>Explanation:</strong> The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word = "xyxzxe", ch = "z"
<strong>Output:</strong> "zxyxxe"
<strong>Explanation:</strong> The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word = "abcd", ch = "z"
<strong>Output:</strong> "abcd"
<strong>Explanation:</strong> "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= word.length &lt;= 250</code></li>
    <li><code>word</code> consists of lowercase English letters.</li>
    <li><code>ch</code> is a lowercase English letter.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Go through the whole string and find the first position of <code>ch</code>, then reverse the prefix string with <strong>two pointers</strong>. We can also achieve the goal with built in functions given in the string library.</p>


<strong>C++</strong>

```
//  Topic   : 2000. Reverse Prefix of Word
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length(), i = 0;
        for (; i < n; i++)
            if (word[i] == ch)
                break;
        if (i == n)
            return word;
        for (int j = 0; j <= i / 2; j++)
        {
            char tmp = word[j];
            word[j] = word[i - j];
            word[i - j] = tmp;
        }
        return word;
    }
};
```

```
//  Topic   : 2000. Reverse Prefix of Word
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int p = word.find(ch) + 1;
        reverse(word.begin(), word.begin() + p);
        return word;
    }
};
```
