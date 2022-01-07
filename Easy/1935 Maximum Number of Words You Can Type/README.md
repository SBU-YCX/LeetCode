# [1935. Maximum Number of Words You Can Type](https://leetcode.com/problems/maximum-number-of-words-you-can-type/)


## Description:

<p>There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.</p>

<p>Given a string <code>text</code> of words separated by a single space (no leading or trailing spaces) and a string <code>brokenLetters</code> of all <strong>distinct</strong> letter keys that are broken, return <em>the <strong>number of words</strong> in <code>text</code> you can fully type using this keyboard.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> text = "hello world", brokenLetters = "ad"
<strong>Output:</strong> 1
<strong>Explanation:</strong> We cannot type "world" because the 'd' key is broken.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> text = "leet code", brokenLetters = "lt"
<strong>Output:</strong> 1
<strong>Explanation:</strong> We cannot type "leet" because the 'l' and 't' keys are broken.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> text = "leet code", brokenLetters = "e"
<strong>Output:</strong> 0
<strong>Explanation:</strong> We cannot type either word because the 'e' key is broken.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= text.length &lt;= 10<sup>4</sup></code></li>
    <li><code>0 &lt;= brokenLetters.length &lt;= 26</code></li>
    <li><code>text</code> consists of words separated by a single space without any leading or trailing spaces.</li>
    <li>Each word only consists of lowercase English letters.</li>
    <li><code>brokenLetters</code> consists of <strong>distinct</strong> lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using a <strong>hash table</strong> to store all the broken letters. For each letter in <code>text</code>, check whether it is broken and use a variable <code>success</code> to indicate it. Whenever we meet a <code>' '</code> or reach the tail of <code>text</code>, which means the end of a word, if <code>success == true</code>, we can fully type it.</p>


<strong>C++</strong>

```
//  Topic   : 1935. Maximum Number of Words You Can Type
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(M)


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (auto& c : brokenLetters)
            broken[c - 'a'] = true;
        int ans = 0, n = text.length();
        bool success = true;
        for (int i = 0; i <= n; i++)
        {
            if (i == n || text[i] == ' ')
            {
                if (success)
                    ans++;
                success = true;
            }
            else if (broken[text[i] - 'a'])
                success = false;
        }
        return ans;
    }
};
```