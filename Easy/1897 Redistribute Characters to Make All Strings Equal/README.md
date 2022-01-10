# [1897. Redistribute Characters to Make All Strings Equal](https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/)


## Description:

<p>You are given an array of strings <code>words</code> (<strong>0-indexed</strong>).</p>

<p>In one operation, pick two <strong>distinct</strong> indices <code>i</code> and <code>j</code>, where <code>words[i]</code> is a non-empty string, and move <strong>any</strong> character from <code>words[i]</code> to <strong>any</strong> position in <code>words[j]</code>.</p>

<p>Return <em><code>true</code> if you can make <strong>every</strong> string in <code>words</code> <strong>equal</strong> using <strong>any</strong> number of operations, and <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> words = ["abc","aabc","bc"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Move the first 'a' in words[1] to the front of words[2],
to make words[1] = "abc" and words[2] = "abc".
All the strings are now equal to "abc", so return true.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> words = ["ab","a"]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to make all the strings equal using the operation.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= words.length &lt;= 100</code></li>
    <li><code>1 &lt;= words[i].length &lt;= 100</code></li>
    <li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>In order to make all strings equal, we only need the total frequency of each letter can be divided by the number of strings.</p>


<strong>C++</strong>

```
//  Topic   : 1897. Redistribute Characters to Make All Strings Equal
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(1)


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26, 0);
        int m = words.size();
        for (int i = 0; i < m; i++)
        {
            int n = words[i].size();
            for (int j = 0; j < n; j++)
                freq[words[i][j] - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++)
            if (freq[i] % m != 0)
                return false;
        return true;
    }
};
```
