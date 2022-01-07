# [1933. Check if String Is Decomposable Into Value-Equal Substrings](https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings/)


## Description:

<p>A <strong>value-equal</strong> string is a string where <strong>all</strong> characters are the same.</p>

<ul>
    <li>For example, <code>"1111"</code> and <code>"33"</code> are value-equal strings.</li>
    <li>In contrast, <code>"123"</code> is not a value-equal string.</li>
</ul>

<p>Given a digit string <code>s</code>, decompose the string into some number of <strong>consecutive value-equal</strong> substrings where <strong>exactly one</strong> substring has a <strong>length of</strong> <code>2</code> and the remaining substrings have a <strong>length of</strong> <code>3</code>.</p>

<p>Return <em><code>true</code> if you can decompose <code>s</code> according to the above rules. Otherwise, return <code>false</code>.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "000111000"
<strong>Output:</strong> false
<strong>Explanation:</strong> s cannot be decomposed according to the rules because ["000", "111", "000"] does not have a substring of length 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "00011111222"
<strong>Output:</strong> true
<strong>Explanation:</strong> s can be decomposed into ["000", "111", "11", "222"].
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "011100022233"
<strong>Output:</strong> false
<strong>Explanation:</strong> s cannot be decomposed according to the rules because of the first '0'.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 1000</code></li>
    <li><code>s</code> consists of only digits <code>'0'</code> through <code>'9'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Check all the 3-character triplets, if a triplet is 3-equal, keep going; otherwise, check whether it is 2-equal and count the number of 2-equal pairs.</p>


<strong>C++</strong>

```
//  Topic   : 1933. Check if String Is Decomposable Into Value-Equal Substrings
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool isDecomposable(string s) {
        int n = s.length(), num2 = 0, i = 0;
        for (; i <= n - 2; i += 3)
        {
            if (s[i] == s[i + 1])
            {
                if (i == n - 2)
                {
                    if (num2 == 1)
                        return false;
                    else 
                        return true;
                }
                if (s[i] != s[i + 2])
                {
                    if (num2 == 1)
                        return false;
                    num2 += 1;
                    i -= 1;
                }
            }
            else
                return false;
        }
        if (i != n || num2 == 0)
            return false;
        return true;
    }
};
```