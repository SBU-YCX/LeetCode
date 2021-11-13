# [2068. Check Whether Two Strings are Almost Equivalent](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/)


## Description:

<p>Two strings <code>word1</code> and <code>word2</code> are considered <strong>almost equivalent</strong> if the differences between the frequencies of each letter from <code>'a'</code> to <code>'z'</code> between <code>word1</code> and <code>word2</code> is <strong>at most</strong> <code>3</code>.</p>

<p>Given two strings <code>word1</code> and <code>word2</code>, each of length <code>n</code>, return <em><code>true</code> if <code>word1</code> and <code>word2</code> are <strong>almost equivalent</strong>, or <code>false</code> otherwise.</em></p>

<p>The <strong>frequency</strong> of a letter <code>x</code> is the number of times it occurs in the string.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word1 = "aaaa", word2 = "bccb"
<strong>Output:</strong> false
<strong>Explanation:</strong> There are 4 'a's in "aaaa" but 0 'a's in "bccb".
The difference is 4, which is more than the allowed 3.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word1 = "abcdeef", word2 = "abaaacc"
<strong>Output:</strong> true
<strong>Explanation:</strong> The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 1 time in word1 and 4 times in word2. The difference is 3.
- 'b' appears 1 time in word1 and 1 time in word2. The difference is 0.
- 'c' appears 1 time in word1 and 2 times in word2. The difference is 1.
- 'd' appears 1 time in word1 and 0 times in word2. The difference is 1.
- 'e' appears 2 times in word1 and 0 times in word2. The difference is 2.
- 'f' appears 1 time in word1 and 0 times in word2. The difference is 1.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word1 = "cccddabba", word2 = "babababab"
<strong>Output:</strong> true
<strong>Explanation:</strong> The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 2 times in word1 and 4 times in word2. The difference is 2.
- 'b' appears 2 times in word1 and 5 times in word2. The difference is 3.
- 'c' appears 3 times in word1 and 0 times in word2. The difference is 3.
- 'd' appears 2 times in word1 and 0 times in word2. The difference is 2.
</pre>


## Constraints:

<ul>
  <li><code>n == word1.length == word2.length</code></li>
  <li><code>1 &lt;= n &lt;= 100</code></li>
  <li><code>word1</code> and <code>word2</code> consist only of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Clearly, the problem is about the frequencies of letters, so we need to utilize <strong>map</strong> to solve it. Specifically, a map <code>freq</code> is build to store the difference of numbers of each letter in <code>word1</code> and <code>word2</code>, then we check whether the absolute value of difference is larger than <code>3</code> for each letter.</p>


<strong>C++</strong>

```
//  Topic   : 2068. Check Whether Two Strings are Almost Equivalent (https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/)
//  Author  : YCX
//  Time    : O(N1 + N2)
//  Space   : O(1)


class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> freq(26, 0);
        for (auto c : word1)
            freq[c - 'a']++;
        for (auto c : word2)
            freq[c - 'a']--;
        for (auto l : freq)
            if (l > 3 || l < -3)
                return false;
        return true;
    }
};
```