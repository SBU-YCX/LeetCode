# [1592. Rearrange Spaces Between Words](https://leetcode.com/problems/rearrange-spaces-between-words/)


## Description:

<p>You are given a string <code>text</code> of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that <code>text</code> <strong>contains at least one word</strong>.</p>

<p>Rearrange the spaces so that there is an <strong>equal</strong> number of spaces between every pair of adjacent words and that number is <strong>maximized</strong>. If you cannot redistribute all the spaces equally, place the <strong>extra spaces at the end</strong>, meaning the returned string should be the same length as <code>text</code>.</p>

<p>Return <em>the string after rearranging the spaces.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> text = "  this   is  a sentence "
<strong>Output:</strong> "this   is   a   sentence"
<strong>Explanation:</strong> There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> text = " practice   makes   perfect"
<strong>Output:</strong> "practice   makes   perfect "
<strong>Explanation:</strong> There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= text.length &lt;= 100</code></li>
    <li><code>text</code> consists of lowercase English letters and <code>' '</code>.</li>
    <li><code>text</code> contains at least one word.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a <strong>queue</strong> to store all the words and count the total number of white spaces, calculate the number of white spaces should be placed between words and concate words with these white spaces.</p>


<strong>C++</strong>

```
//  Topic   : 1592. Rearrange Spaces Between Words
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string reorderSpaces(string text) {
        int num = 0, n = text.length();
        queue<string> words;
        string s = "";
        for (int i = 0; i < n; i++)
        {
            if (text[i] == ' ')
            {
                if (s.length() > 0)
                    words.push(s);
                num += 1;
                s = "";
            }
            else
                s += text[i];
        }
        if (s.length() > 0)
            words.push(s);
        string ans = "";
        if (words.size() == 1)
        {
            ans += words.front();
            for (int i = 0; i < num; i++)
                ans += " ";
            return ans;
        }
        int k = num / (words.size() - 1), r = num % (words.size() - 1);
        string ks = "", rs = "";
        for (int i = 0; i < k; i++)
            ks += " ";
        for (int j = 0; j < r; j++)
            rs += " ";
        while (!words.empty())
        {
            ans += words.front();
            words.pop();
            if (words.empty())
                break;
            ans += ks;
        }
        ans += rs;
        return ans;
    }
};
```