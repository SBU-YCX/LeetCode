# [1945. Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/)


## Description:

<p>You are given a string <code>s</code> consisting of lowercase English letters, and an integer <code>k</code>.</p>

<p>First, <strong>convert</strong> <code>s</code> into an integer by replacing each letter with its position in the alphabet (i.e., replace <code>'a'</code> with <code>1</code>, <code>'b'</code> with <code>2</code>, ..., <code>'z'</code> with <code>26</code>). Then, <strong>transform</strong> the integer by replacing it with the <strong>sum of its digits</strong>. Repeat the <strong>transform</strong> operation <code>k</code> <strong>times</strong> in total.</p>

<p>For example, if <code>s = "zbax"</code> and <code>k = 2</code>, then the resulting integer would be <code>8</code> by the following operations:</p>

<ul>
    <li><strong>Convert</strong>: <code>"zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124</code></li>
    <li><strong>Transform #1</strong>: <code>262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17</code></li>
    <li><strong>Transform #2</strong>: <code>17 ➝ 1 + 7 ➝ 8</code></li>
</ul>

<p>Return <em>the resulting integer after performing the operations described above.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "iiii", k = 1
<strong>Output:</strong> 36
<strong>Explanation:</strong> The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "leetcode", k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "zbax", k = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code></li>
    <li><code>1 &lt;= k &lt;= 10</code></li>
    <li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the process.</p>


<strong>C++</strong>

```
//  Topic   : 1945. Sum of Digits of String After Convert
//  Author  : YCX
//  Time    : O(N * K)
//  Space   : O(N)


class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
            ans += to_string(s[i] - 'a' + 1);
        int sum;
        for (int i = 0; i < k; i++)
        {
            sum = 0;
            for (int j = 0; j < ans.length(); j++)
                sum += (ans[j] - '0');
            ans = to_string(sum);
        }
        return sum;
    }
};
```