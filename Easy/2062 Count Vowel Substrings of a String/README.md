# [2062. Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string/)


## Description:

<p>A <strong>substring</strong> is a contiguous (non-empty) sequence of characters within a string.</p>

<p>A <strong>vowel substring</strong> is a substring that <strong>only</strong> consists of vowels (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>) and has <strong>all five</strong> vowels present in it.</p>

<p>Given a string <code>word</code>, return <em>the number of <strong>vowel substrings</strong> in <code>word</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word = "aeiouu"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The vowel substrings of word are as follows (underlined):
- "<u>aeiou</u>u"
- "aeiouu"
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word = "unicornarihan"
<strong>Output:</strong> 0
<strong>Explanation:</strong> Not all 5 vowels are present, so there are no vowel substrings.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word = "cuaieuouac"
<strong>Output:</strong> 7
<strong>Explanation:</strong> The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> word = "bbaeixoubb"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only substrings that contain all five vowels also contain consonants, so there are no vowel substrings.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 100</code></li>
  <li><code>0 &lt;= nums[i] &lt;= 9</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Just go through the whole array <code>nums</code> and check each element.</p>


<strong>C++</strong>

```
//  Topic   : 2057. Smallest Index With Equal Value (https://leetcode.com/problems/smallest-index-with-equal-value/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (i % 10 == nums[i])
                return i;
        return -1;
    }
};
```
