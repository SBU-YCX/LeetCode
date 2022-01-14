# [1832. Check if the Sentence Is Pangram](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)


## Description:

<p>A <strong>pangram</strong> is a sentence where every letter of the English alphabet appears at least once.</p>

<p>Given a string <code>sentence</code> containing only lowercase English letters, return <em><code>true</code> if <code>sentence</code> is a <strong>pangram</strong>, or <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> sentence = "thequickbrownfoxjumpsoverthelazydog"
<strong>Output:</strong> true
<strong>Explanation:</strong> sentence contains at least one of every letter of the English alphabet.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> sentence = "leetcode"
<strong>Output:</strong> false
<strong>Explanation:</strong>
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= sentence.length &lt;= 1000</code></li>
    <li><code>sentence</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Count</strong> the frequency of each letter.</p>


<strong>C++</strong>

```
//  Topic   : 1832. Check if the Sentence Is Pangram
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(26)


class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> appear(26, 0);
        for (int i = 0; i < sentence.length(); i++)
            appear[sentence[i] - 'a'] = 1;
        for (int i = 0; i < 26; i++)
            if (appear[i] == 0)
                return false;
        return true;
    }
};
```
