# [2131. Longest Palindrome by Concatenating Two Letter Words](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/)


## Description:

<p>You are given an array of strings <code>words</code>. Each element of <code>words</code> consists of <strong>two</strong> lowercase English letters.</p>

<p>Create the <strong>longest possible palindrome</strong> by selecting some elements from <code>words</code> and concatenating them in <strong>any order</strong>. Each element can be selected <strong>at most once</strong>.</p>

<p>Return <em>the <strong>length</strong> of the longest palindrome that you can create.</em> If it is impossible to create any palindrome, return <em><code>0</code>.</em></p>

<p>A <strong>palindrome</strong> is a string that reads the same forward and backward.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> words = ["lc","cl","gg"]
<strong>Output:</strong> 6
<strong>Explanation:</strong> One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created. 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> words = ["ab","ty","yt","lc","cl","ab"]
<strong>Output:</strong> 8
<strong>Explanation:</strong> One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> words = ["cc","ll","xx"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
    <li><code>words[i].length == 2</code></li>
    <li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>If we want to make the palindrome string have the maximum length, we need use as many paired words (words and their reverses) as possible, besides, we can have one extra word in the form of <code>"aa"</code> in the middle of the string. By using a <strong>hash table</strong> <code>m</code> to count the frequency of each word, we can form the palindrome string with the following components:</p>

<ul>
    <li>For words like <code>"ab"</code>, find the reverse <code>"ba"</code>, and choose <code>min(m["ab"], m["ba"])</code> pairs to add to the string</li>
    <li>For words like <code>"aa"</code>, their reverses are themselves, so choose <code>m["aa"] / 2</code> pairs, besides, if <code>m["aa"]</code> is <strong>odd</strong>, we can add one (and only one among all such words) extra <code>"aa"</code> to the string</li>
</ul>


<strong>C++</strong>

```
//  Topic   : 2131. Longest Palindrome by Concatenating Two Letter Words
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for (auto& s : words)
            m[s]++;
        int ans = 0;
        bool use = false;
        for (auto& p : m)
        {
            if (p.first[0] == p.first[1])
            {
                if (p.second % 2 == 1)
                {
                    if (!use)
                    {
                        ans += 2;
                        use = true;
                    }
                }
                ans += (4 * (p.second / 2));
            }
            else
            {
                string t = p.first;
                reverse(t.begin(), t.end());
                if (!m.count(t))
                    continue;
                int n = min<int>(p.second, m[t]);
                ans += 4 * n;
                p.second -= n;
                m[t] -= n;
                if (m[t] == 0)
                    m.erase(t);
            }
        }
        return ans;
    }
};
```
