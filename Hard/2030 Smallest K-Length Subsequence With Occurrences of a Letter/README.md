# [2030. Smallest K-Length Subsequence With Occurrences of a Letter](https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/)


## Description:

<p>You are given a string <code>s</code>, an integer <code>k</code>, a letter <code>letter</code>, and an integer <code>repetition</code>.</p>

<p>Return <em>the <strong>lexicographically smallest</strong> subsequence of <code>s</code> of length <code>k</code> that has the letter <code>letter</code> appear <strong>at least</strong> <code>repetition</code> times.</em> The test cases are generated so that the <code>letter</code> appears in <code>s</code> <strong>at least</strong> <code>repetition</code> times.</p>

<p>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</p>

<p>A string <code>a</code> is <strong>lexicographically smaller</strong> than a string <code>b</code> if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears earlier in the alphabet than the corresponding letter in <code>b</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "leet", k = 3, letter = "e", repetition = 1
<strong>Output:</strong> "eet"
<strong>Explanation:</strong> There are four subsequences of length 3 that have the letter 'e' appear at least 1 time:
- "lee" (from "leet")
- "let" (from "leet")
- "let" (from "leet")
- "eet" (from "leet")
The lexicographically smallest subsequence among them is "eet".
</pre>

<strong>Example 2:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/09/13/smallest-k-length-subsequence.png)
<pre>
<strong>Input:</strong> s = "leetcode", k = 4, letter = "e", repetition = 2
<strong>Output:</strong> "ecde"
<strong>Explanation:</strong> "ecde" is the lexicographically smallest subsequence of length 4 that has the letter "e" appear at least 2 times.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "bb", k = 2, letter = "b", repetition = 2
<strong>Output:</strong> "bb"
<strong>Explanation:</strong> "bb" is the only subsequence of length 2 that has the letter "b" appear at least 2 times.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= repetition &lt;= k &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
    <li><code>s</code> consists of lowercase English letters.</li>
    <li><code>letter</code> is a lowercase English letter, and appears in <code>s</code> at least <code>repetition</code> times.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Let's regard the answer string <code>ans</code> as a <strong>stack</strong> and check the character in <code>s</code> one by one. Since we need the lexicographically smallest string, for a new character <code>s[i]</code>, we can check from the tail of <code>ans</code> to see if <code>s[i]</code> can make <code>ans</code> smaller, i.e. pop out the tail characters in <code>ans</code> if <code>ans.back() > s[i]</code>. When poping out, we need to make sure the following two conditions true:</p>

<ul>
    <li>there are at least <code>k - ans.length()</code> characters left in <code>s</code> to make sure that <code>ans</code> of length <code>k</code>, i.e. <code>n - i - ans.length() > k</code></li>
    <li>there are at least <code>repetition - p</code> target letters left in <code>s</code>, where <code>p</code> is the number of target in <code>ans</code></li>
</ul>

<p>When adding new character <code>s[i]</code> to <code>ans</code>, we also need to make sure that</p>

<ul>
    <li>there are enough room for target letters in <code>ans</code>, i.e., <code>k - ans.length() > repetition - p</code></li>
</ul>


<strong>C++</strong>

```
// Topic     : 2030. Smallest K-Length Subsequence With Occurrences of a Letter (https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2025%20Maximum%20Number%20of%20Ways%20to%20Partition%20an%20Array)
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.length(), m = count(s.begin(), s.end(), letter);
        string ans;
        for (int i = 0; i < n; i++)
        {
            int l = ans.length();
            while (l > 0 && ans.back() > s[i] && (n - i + l) > k)
            {
                if (ans.back() == letter && m <= repetition)
                    break;
                else if (ans.back() == letter)
                    repetition++;
                ans.pop_back();
                l = ans.length();
            }
            if (l < k)
                if (s[i] == letter || k - l > repetition)
                {
                    ans += s[i];
                    if (s[i] == letter)
                        repetition--;
                }
            if (s[i] == letter)
                m--;
        }
        return ans;
    }
};
```
