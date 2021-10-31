# [2047. Number of Valid Words in a Sentence](https://leetcode.com/problems/number-of-valid-words-in-a-sentence/)


## Description:

<p>A sentence consists of lowercase letters (<code>'a'</code> to <code>'z'</code>), digits (<code>'0'</code> to <code>'9'</code>), hyphens (<code>'-'</code>), punctuation marks (<code>'!'</code>, <code>'.'</code>, and <code>','</code>), and spaces (<code>' '</code>) only. Each sentence can be broken down into <strong>one or more tokens</strong> separated by one or more spaces <code>' '</code>.</p>
<p>A token is a valid word if <strong>all three</strong> of the following are true:</p>
<ul>
  <li>It only contains lowercase letters, hyphens, and/or punctuation (<strong>no</strong> digits).</li>
  <li>There is <strong>at most one</strong> hyphen <code>'-'</code>. If present, it <strong>must</strong> be surrounded by lowercase characters (<code>"a-b"</code> is valid, but <code>"-ab"</code> and <code>"ab-"</code> are not valid).</li>
  <li>There is <strong>at most one</strong> punctuation mark. If present, it <strong>must</strong> be at the <strong>end</strong> of the token (<code>"ab,"</code>, <code>"cd!"</code>, and <code>"."</code> are valid, but <code>"a!b"</code> and <code>"c.,"</code> are not valid).</li>
</ul>
<p>Examples of valid words include <code>"a-b."</code>, <code>"afad"</code>, <code>"ba-c"</code>, <code>"a!"</code>, and <code>"!"</code>.</p>
<p>Given a string <code>sentence</code>, return <em>the <strong>number</strong> of valid words in <code>sentence</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> sentence = "cat and  dog"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The valid words in the sentence are "cat", "and", and "dog".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> sentence = "!this  1-s b8d!"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no valid words in the sentence.
"!this" is invalid because it starts with a punctuation mark.
"1-s" and "b8d" are invalid because they contain digits.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> sentence = "alice and  bob are playing stone-game10"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The valid words in the sentence are "alice", "and", "bob", "are", and "playing".
"stone-game10" is invalid because it contains digits.
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."
<strong>Output:</strong> 6
<strong>Explanation:</strong> The valid words in the sentence are "he", "bought", "pencils,", "erasers,", "and", and "pencil-sharpener.".
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= sentence.length &lt;= 1000</code></li>
  <li><code>sentence</code> only contains lowercase English letters, digits, <code>' '</code>, <code>'-'</code>, <code>'!'</code>, <code>'.'</code>, and <code>','</code>.</li>
  <li>There will be at least <code>1</code> token.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Split the string <code>sentence</code> into words and check each word by the three conditions.</p>


<strong>C++</strong>

```
//  Topic   : 2047. Number of Valid Words in a Sentence (https://leetcode.com/problems/number-of-valid-words-in-a-sentence/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int countValidWords(string sentence) {
        int l = 0, r = sentence.length(), ans = 0; 
        while (l < r)
        {
            int p = sentence.find(' ', l);
            if (p == -1)
                p = r;
            string word = sentence.substr(l, p - l);
            if (word.length() != 0 && isValid(word))
                ans++;
            l = p + 1;
        }
        return ans;
    }

private: 
    bool isValid(string word)
    {
        int n = word.length(), np = 0, nh = 0;
        for (int i = 0; i < n; i++)
        {
            if (word[i] <= '9' && word[i] >= '0')
                return false;
            else if (word[i] == '-')
            {
                nh++;
                if (nh >= 2)
                    return false;
                if (i == 0)
                    return false;
                else if (i == n - 1)
                    return false;
                else if ((word[i - 1] > 'z' || word[i - 1] < 'a') || (word[i + 1] > 'z' || word[i + 1] < 'a'))
                    return false;
            }
            else if (word[i] == '!' || word[i] == '.' || word[i] == ',')
            {
                np++;
                if (np >= 2 || i != n - 1)
                    return false;
            }
        }
        return true;
    }
};
```
