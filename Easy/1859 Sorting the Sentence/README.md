# [1859. Sorting the Sentence](https://leetcode.com/problems/sorting-the-sentence/)


## Description:

<p>A <strong>sentence</strong> is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.</p>

<p>A sentence can be <strong>shuffled</strong> by appending the <strong>1-indexed word position</strong> to each word then rearranging the words in the sentence.</p>

<ul>
    <li>For example, the sentence <code>"This is a sentence"</code> can be shuffled as <code>"sentence4 a3 is2 This1"</code> or <code>"is2 sentence4 This1 a3"</code>.</li>
</ul>

<p>Given a <strong>shuffled sentence</strong> <code>s</code> containing no more than <code>9</code> words, reconstruct and return <em>the original sentence.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "is2 sentence4 This1 a3"
<strong>Output:</strong> "This is a sentence"
<strong>Explanation:</strong> Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "Myself2 Me1 I4 and3"
<strong>Output:</strong> "Me Myself and I"
<strong>Explanation:</strong> Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= s.length &lt;= 200</code></li>
    <li><code>s</code> consists of lowercase and uppercase English letters, spaces, and digits from <code>1</code> to <code>9</code>.</li>
    <li>The number of words in <code>s</code> is between <code>1</code> and <code>9</code>.</li>
    <li>The words in <code>s</code> are separated by a single space.</li>
    <li><code>s</code> contains no leading or trailing spaces.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Divide the string <code>s</code> into words, then use a <strong>hash table</strong> to <strong>sort</strong> them according to their last characters.</p>


<strong>C++</strong>

```
//  Topic   : 1859. Sorting the Sentence
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string sortSentence(string s) {
        string ans = "";
        string word = "";
        int num = 1;
        vector<string> words(9);
        s += " ";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                int cur = word[word.length() - 1] - '0';
                num = max<int>(cur, num);
                words[cur - 1] = word.substr(0, word.length() - 1);
                word = "";
            }
            else
                word += s[i];
        }
        for (int i = 0; i < num; i++)
        {
            ans += words[i];
            if (i != num - 1)
                ans += " ";
        }
        return ans;
    }
};
```