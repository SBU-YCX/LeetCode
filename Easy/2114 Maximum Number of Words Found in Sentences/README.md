# [2114. Maximum Number of Words Found in Sentences](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/)


## Description:

<p>A <strong>sentence</strong> is a list of <strong>words</strong> that are separated by a single space with no leading or trailing spaces.</p>

<p>You are given an array of strings <code>sentences</code>, where each <code>sentences[i]</code> represents a single <strong>sentence</strong>.</p>

<p>Return <em>the <strong>maximum number of words</strong> that appear in a single sentence.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> sentences = ["please wait", "continue to fight", "continue to win"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
It is possible that multiple sentences contain the same number of words. 
In this example, the second and third sentences (underlined) have the same number of words.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= sentences.length &lt;= 100</code></li>
  <li><code>1 &lt;= sentences[i].length &lt;= 100</code></li>
  <li><code>sentences[i]</code> consists only of lowercase English letters and <code>' '</code> only.</li>
  <li><code>sentences[i]</code> does not have leading or trailing spaces.</li>
  <li>All the words in <code>sentences[i]</code> are separated by a single space.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since words are separated by a single space, we can just <strong>count</strong> the number of spaces <code>n<sub>s</sub></code>, and the number of words is <code>n<sub>w</sub> = n<sub>s</sub> + 1</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2114. Maximum Number of Words Found in Sentences (https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/)
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(1)


class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = count(sentences[i].begin(), sentences[i].end(), ' ') + 1;
            ans = max<int>(ans, cnt);
        }
        return ans;
    }
};
```