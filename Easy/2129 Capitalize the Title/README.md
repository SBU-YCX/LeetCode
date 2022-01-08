# [2129. Capitalize the Title](https://leetcode.com/problems/capitalize-the-title/)


## Description:

<p>You are given a string <code>title</code> consisting of one or more words separated by a single space, where each word consists of English letters. <strong>Capitalize</strong> the string by changing the capitalization of each word such that:</p>

<ul>
    <li>If the length of the word is <code>1</code> or <code>2</code> letters, change all letters to lowercase.</li>
    <li>Otherwise, change the first letter to uppercase and the remaining letters to lowercase.</li>
</ul>

<p>Return <em>the <strong>capitalized</strong> <code>title</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> title = "capiTalIze tHe titLe"
<strong>Output:</strong> "Capitalize The Title"
<strong>Explanation:</strong> 
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> title = "First leTTeR of EACH Word"
<strong>Output:</strong> "First Letter of Each Word"
<strong>Explanation:</strong> 
The word "of" has length 2, so it is all lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> title = "i lOve leetcode"
<strong>Output:</strong> "i Love Leetcode"
<strong>Explanation:</strong> 
The word "i" has length 1, so it is lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= title.length &lt;= 100</code></li>
    <li><code>title</code> consists of words separated by a single space without any leading or trailing spaces.</li>
    <li>Each word consists of uppercase and lowercase English letters and is <strong>non-empty</strong>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using <strong>two pointers</strong>, <code>p</code> to separate the words first, then <code>l</code> to check characters within a word one by one.</p>


<strong>C++</strong>

```
//  Topic   : 2129. Capitalize the Title
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string capitalizeTitle(string title) {
        int r = title.length(), l = 0;
        while (l < r)
        {
            int p = title.find(' ', l);
            if (p == -1)
                p = r;
            int m = p - l;
            if (m <= 2)
            {
                while (l < p)
                {
                    if (title[l] <= 'Z' && title[l] >= 'A')
                        title[l] = (title[l] - 'A' + 'a');
                    l++;
                }
            }
            else
            {
                if (title[l] <= 'z' && title[l] >= 'a')
                    title[l] = (title[l] - 'a' + 'A');
                l++;
                while (l < p)
                {
                    if (title[l] <= 'Z' && title[l] >= 'A')
                        title[l] = (title[l] - 'A' + 'a');
                    l++;
                }
            }
            l = p + 1;
        }
        return title;
    }
};
```
