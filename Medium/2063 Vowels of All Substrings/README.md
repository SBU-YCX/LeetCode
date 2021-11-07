# [2063. Vowels of All Substrings](https://leetcode.com/problems/vowels-of-all-substrings/)


## Description:

<p>Given a string <code>word</code>, return <em>the <strong>sum of the number of vowels</strong> (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>) in every substring of word.</em></p>

<p>A <strong>substring</strong> is a contiguous (non-empty) sequence of characters within a string.</p>

<p><strong>Note:</strong> Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word = "aba"
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3. 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word = "ltcd"
<strong>Output:</strong> 0
<strong>Explanation:</strong>
There are no vowels in any substring of "ltcd".
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> nums = [2,8,16], start = 0, goal = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong>
There is no way to convert 0 into 1.
</pre>

<strong>Example 5:</strong>
<pre>
<strong>Input:</strong> word = "noosabasboosa"
<strong>Output:</strong> 237
<strong>Explanation:</strong>
There are a total of 237 vowels in all the substrings.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
  <li><code>word</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>The naive approach is that for each substring, count the number of vowels in it, which will take <code>O(n ^ 3)</code> time and get an TLE. An improved method is to use the <strong>prefix sum</strong> idea, and calculate the number of vowels from <code>0</code> to <code>i</code> in advance, so that the number of vowels of each substring can be obtained through the array, but it still takes <code>O(n ^ 2)</code> (TLE).</p>
<p>So, let's see this problem in another view. The problem asks us to calculate the sum of numbers of vowels in all substrings, so each vowel is counted once a substring contains it. In other words, for each vowel, we only need to sum the number of substrings containing it and finally sum them up. Now, things become easier since we can easily get that for a character at index <code>i</code>, the number of substrings including:</p>
<ul>
    <li>The substrings starting with this character -- <code>n - i</code></li>
    <li>The substrings starting with previous characters containing this character -- <code>arr[i - 1] - i</code></li>
</ul>

<strong>C++</strong>

```
//  Topic   ：2063. Vowels of All Substrings (https://leetcode.com/problems/vowels-of-all-substrings/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    long long countVowels(string word) {
        int n = word.length();
        long long ans = 0;
        vector<long long> freq(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                freq[i] = n;
            else
                freq[i] = (n - i) + freq[i - 1] - i;
        }
        for (int i = 0; i < n; i++)
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
                ans += freq[i];
        return ans;
    }
};
```

## Solution: [Improved]

<strong>Logical Thinking</strong>
<p>To calculate the number of substrings containing a character:</p>
<ul>
    <li>The substrings starting with this character -- <code>n - i</code></li>
    <li>The substrings ending with this character -- <code>i + 1</code></li>
</ul>
<p>so all the substrings are combinations of these two kind of substrings and the number is <code>(n - 1) * (i + 1)</code>, now the space complexity is only <code>O(1)</code>.</p>

 
<strong>C++</strong>

```
//  Topic   ：2063. Vowels of All Substrings (https://leetcode.com/problems/vowels-of-all-substrings/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    long long countVowels(string word) {
        long long n = word.length(), ans = 0;
        for (int i = 0; i < n; i++)
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
                ans += (n - i) * (i + 1);
        return ans;
    }
};
```
