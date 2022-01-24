# [1704. Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)


## Description:

<p>You are given a string <code>s</code> of even length. Split this string into two halves of equal lengths, and let <code>a</code> be the first half and <code>b</code> be the second half.</p>

<p>Two strings are <strong>alike</strong> if they have the same number of vowels (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>, <code>'A'</code>, <code>'E'</code>, <code>'I'</code>, <code>'O'</code>, <code>'U'</code>). Notice that <code>s</code> contains uppercase and lowercase letters.</p>

<p>Return <em><code>true</code> if <code>a</code> and <code>b</code> are <strong>alike</strong>.</em> Otherwise, return <em><code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "book"
<strong>Output:</strong> true
<strong>Explanation:</strong> a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "textbook"
<strong>Output:</strong> false
<strong>Explanation:</strong> a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= s.length &lt;= 1000</code></li>
    <li><code>s.length</code> is even.</li>
    <li><code>s</code> consists of <strong>uppercase and lowercase</strong> letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use <strong>two pointers</strong>, <code>i = 0</code> and moves from left to right, <code>j = s.length() - 1</code> and moves from right to left. Every time <code>i</code> points to a vowel, see if we can find a <code>j</code> points to a vowel too.</p>


<strong>C++</strong>

```
//  Topic   : 1704. Determine if String Halves Are Alike
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool halvesAreAlike(string s) {
        int m = s.length();
        int j = m - 1;
        for (int i = 0; i < m / 2; i++)
        {
            if (isVowel(s[i]))
            {
                if (j < m / 2)
                    return false;
                while (!isVowel(s[j]))
                {
                    j--;
                    if (j < m / 2)
                        return false;
                }
                j--;
            }
        }
        for (; j >= m / 2; j--)
            if (isVowel(s[j]))
                return false;
        return true;
    }
    
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};
```