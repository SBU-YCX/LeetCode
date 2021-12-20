# [2108. Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)


## Description:

<p>Given an array of strings <code>words</code>, return <em>the first <strong>palindromic</strong> string in the array.</em> If there is no such string, return <em>an <strong>empty string</strong> <code>""</code>.</em></p>

<p>A string is <strong>palindromic</strong> if it reads the same forward and backward.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> words = ["abc","car","ada","racecar","cool"]
<strong>Output:</strong> "ada"
<strong>Explanation:</strong> 
The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> words = ["notapalindrome","racecar"]
<strong>Output:</strong> "racecar"
<strong>Explanation:</strong> 
The first and only string that is palindromic is "racecar".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> words = ["def","ghi"]
<strong>Output:</strong> ""
<strong>Explanation:</strong> 
There are no palindromic strings, so the empty string is returned.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= words.length &lt;= 100</code></li>
  <li><code>1 &lt;= words[i].length &lt;= 100</code></li>
  <li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Greedily</strong>, we check each word in the array. For each word, we use two pointers moving towards each other ans see whether the corresponding characters are equal.</p>


<strong>C++</strong>

```
//  Topic   : 2108. Find First Palindromic String in the Array (https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(1)


class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& w : words)
            if (isPalindrome(w))
                return w;
        return "";
    }
    
private: 
    bool isPalindrome(string& s)
    {
        int l = 0, r = s.length() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
```
