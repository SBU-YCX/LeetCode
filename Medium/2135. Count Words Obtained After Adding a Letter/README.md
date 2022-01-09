# [2135. Count Words Obtained After Adding a Letter](https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/)


## Description:

<p>You are given two <strong>0-indexed</strong> arrays of strings <code>startWords</code> and <code>targetWords</code>. Each string consists of <strong>lowercase English letters</strong> only.</p>

<p>For each string in <code>targetWords</code>, check if it is possible to choose a string from <code>startWords</code> and perform a <strong>conversion operation</strong> on it to be equal to that from <code>targetWords</code>.</p>

<p>The <strong>conversion operation</strong> is described in the following two steps:</p>

<ul>
    <li><strong>Append</strong> any lowercase letter that is <strong>not present</strong> in the string to its end.
        <ul>
            <li>For example, if the string is <code>"abc"</code>, the letters <code>'d'</code>, <code>'e'</code>, or <code>'y'</code> can be added to it, but not <code>'a'</code>. If <code>'d'</code> is added, the resulting string will be <code>"abcd"</code>.</li>
        </ul>
    </li>
    <li><strong>Rearrange</strong> the letters of the new string in <strong>any</strong> arbitrary order.
        <ul>
            <li>For example, <code>"abcd"</code> can be rearranged to <code>"acbd"</code>, <code>"bacd"</code>, <code>"cbda"</code>, and so on. Note that it can also be rearranged to <code>"abcd"</code> itself.</li>
        </ul>
    </li>
</ul>

<p>Return <em>the <strong>number of strings</strong> in <code>targetWords</code> that can be obtained by performing the operations on <strong>any</strong> string of <code>startWords</code>.</em></p>

<p><strong>Note</strong> that you will only be verifying if the string in <code>targetWords</code> can be obtained from a string in <code>startWords</code> by performing the operations. The strings in <code>startWords</code> <strong>do not</strong> actually change during this process.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- In order to form targetWords[0] = "tack", we use startWords[1] = "act", append 'k' to it, and rearrange "actk" to "tack".
- There is no string in startWords that can be used to obtain targetWords[1] = "act".
  Note that "act" does exist in startWords, but we must append one letter to the string before rearranging it.
- In order to form targetWords[2] = "acti", we use startWords[1] = "act", append 'i' to it, and rearrange "acti" to "acti" itself.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> startWords = ["ab","a"], targetWords = ["abc","abcd"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
- In order to form targetWords[0] = "abc", we use startWords[0] = "ab", add 'c' to it, and rearrange it to "abc".
- There is no string in startWords that can be used to obtain targetWords[1] = "abcd".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= startWords.length, targetWords.length &lt;= 5 * 10<sup>4</sup></code></li>
    <li><code>1 &lt;= startWords[i].length, targetWords[j].length &lt;= 26</code></li>
    <li>Each string of <code>startWords</code> and <code>targetWords</code> consists of lowercase English letters only.</li>
    <li>No letter occurs more than once in any string of <code>startWords</code> or <code>targetWords</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>From the description, we know the following things</p>

<ul>
    <li>Because of the rearrange operation, the order of the letters doesn't matter, so we can use the frequencies of letters to represent a word</li>
    <li>Since no letter occurs more than once, we can further simplify using <strong>bitmask</strong> to represent it</li>
</ul>

<p>So, we convert all the words to their bitmask representations and save those of start words into a <strong>set</strong>. Since the append operation can only be conducted once for each word, i.e., the target word is only one-letter longer than its root in the array of start words, for each target word, we try to remove each of its letters and see if we can find it in the set.</p> 


<strong>C++</strong>

```
//  Topic   : 2135. Count Words Obtained After Adding a Letter
//  Author  : YCX
//  Time    : O((M + N) * K) [K is the average length of each word]
//  Space   : O((M * K + K)


class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int m = startWords.size(), n = targetWords.size(), ans = 0;
        unordered_set<string> freq;
        for (int i = 0; i < m; i++)
        {
            string f = string(26, '0');
            for (auto& c : startWords[i])
                f[c - 'a'] = '1';
            freq.insert(f);
        }
        for (auto& w : targetWords)
        {
            string query = string(26, '0');
            for (auto& c : w)
                query[c - 'a'] = '1';
            for (auto& c : w)
            {
                query[c - 'a'] = '0';
                if (freq.count(query))
                {
                    ans++;
                    break;
                }
                query[c - 'a'] = '1';
            }
        }
        return ans;
    }
};
```