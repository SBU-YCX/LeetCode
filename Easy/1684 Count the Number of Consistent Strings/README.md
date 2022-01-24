# [1684. Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings/)


## Description:

<p>You are given a string <code>allowed</code> consisting of <strong>distinct</strong> characters and an array of strings <code>words</code>. A string is <strong>consistent</strong> if all characters in the string appear in the string <code>allowed</code>.</p>

<p>Return <em>the number of <strong>consistent</strong> strings in the array <code>words</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
<strong>Output:</strong> 7
<strong>Explanation:</strong> All strings are consistent.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Strings "cc", "acd", "ac", and "d" are consistent.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= words.length &lt;= 10<sup>4</sup></code></li>
    <li><code>1 &lt;= allowed.length &lt;= 26</code></li>
    <li><code>1 &lt;= words[i].length &lt;= 10</code></li>
    <li>The characters in <code>allowed</code> are <strong>distinct</strong>.</li>
    <li><code>words[i]</code> and <code>allowed</code> contain only lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a vector <code>allow</code> as a <strong>hash table</strong> to store the appearance of all characters in <code>allowed</code>, then check each string in <code>words</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1684. Count the Number of Consistent Strings
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(N)


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        vector<int> allow(26, 0);
        int is;
        for (int i = 0; i < allowed.length(); i++)
            allow[allowed[i] - 'a'] = 1;
        for (int j = 0; j < words.size(); j++)
        {
            is = true;
            for (int k = 0; k < words[j].length(); k++)
                if (allow[words[j][k] - 'a'] == 0)
                {
                    is = false;
                    break;
                }
            if (is)
                ans += 1;
        }
        return ans;
    }
};
```