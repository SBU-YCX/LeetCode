# [1816. Truncate Sentence](https://leetcode.com/problems/truncate-sentence/)


## Description:

<p>A <strong>sentence</strong> is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of <strong>only</strong> uppercase and lowercase English letters (no punctuation).</p>

<ul>
    <li>For example, <code>"Hello World"</code>, <code>"HELLO"</code>, and <code>"hello world hello world"</code> are all sentences.</li>
</ul>

<p>You are given a sentence <code>s</code> and an integer <code>k</code>. You want to <strong>truncate</strong> <code>s</code> such that it contains only the <strong>first</strong> <code>k</code> words. Return <em><code>s</code> after <strong>truncating</strong> it.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "Hello how are you Contestant", k = 4
<strong>Output:</strong> "Hello how are you"
<strong>Explanation:</strong> 
The words in s are ["Hello", "how" "are", "you", "Contestant"].
The first 4 words are ["Hello", "how", "are", "you"].
Hence, you should return "Hello how are you".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "What is the solution to this problem", k = 4
<strong>Output:</strong> "What is the solution"
<strong>Explanation:</strong> 
The words in s are ["What", "is" "the", "solution", "to", "this", "problem"].
The first 4 words are ["What", "is", "the", "solution"].
Hence, you should return "What is the solution".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "chopper is not a tanuki", k = 5
<strong>Output:</strong> "chopper is not a tanuki"
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 500</code></li>
    <li><code>k</code> is in the range <code>[1, the number of words in s]</code>.</li>
    <li><code>s</code> consist of only lowercase and uppercase English letters and spaces.</li>
    <li>The words in <code>s</code> are separated by a single space.</li>
    <li>There are no leading or trailing spaces.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Each word is ended with a <code>' '</code> (except the last one), so we only need to find the <code>k<sup>th</sup></code> <code>' '</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1816. Truncate Sentence
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string truncateSentence(string s, int k) {
        int l = 0, r = s.length(), m = 0;
        while (l < r)
        {
            int p = s.find(' ', l);
            if (p == -1)
                p = r;
            m++;
            if (m == k)
            {
                r = p;
                break;
            }
            l = p + 1;
        }
        return s.substr(0, r);
    }
};
```