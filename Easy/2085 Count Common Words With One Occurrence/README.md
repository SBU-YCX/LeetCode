# [2085. Count Common Words With One Occurrence](https://leetcode.com/problems/count-common-words-with-one-occurrence/)


## Description:

<p>Given two string arrays <code>words1</code> and <code>words2</code>, return <em>the number of strings that appear <strong>exactly once</strong> in <strong>each</strong> of the two arrays.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
There are no strings that appear in each of the two arrays.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> words1 = ["a","ab"], words2 = ["a","a","a","ab"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
The only string that appears exactly once in each of the two arrays is "ab".
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= words1.length, words2.length &lt;= 1000</code></li>
  <li><code>1 &lt;= words1[i].length, words2[j].length &lt;= 30</code></li>
  <li><code>words1[i]</code> and <code>words2[j]</code> consists only of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using two <strong>Hash Tables</strong>, <code>f1</code> and <code>f2</code>, to count the frequencies of strings in two arrays, and then check each key <code>s</code> in <code>f1</code> to see if <code>f1[s] == 1 && f2[s] == 1</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2085. Count Common Words With One Occurrence (https://leetcode.com/problems/count-common-words-with-one-occurrence/)
//  Author  : YCX
//  Time    : O(N1 + N2)
//  Space   : O(N1 + N2)


class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> f1, f2;
        for (auto& w : words1)
            f1[w]++;
        for (auto& w : words2)
            f2[w]++;
        int ans = 0;
        for (auto& p : f1)
            if (f2[p.first] == 1 && p.second == 1)
                ans++;
        return ans;
    }
};
```