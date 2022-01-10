# [1903. Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/)


## Description:

<p>You are given a string <code>num</code>, representing a large integer. Return <em>the <strong>largest-valued odd</strong> integer (as a string) that is a <strong>non-empty substring</strong> of <code>num</code>, or an empty string <code>""</code> if no odd integer exists.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> num = "52"
<strong>Output:</strong> "5"
<strong>Explanation:</strong> The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> num = "4206"
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no odd numbers in "4206".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> num = "35427"
<strong>Output:</strong> "35427"
<strong>Explanation:</strong> "35427" is already an odd number.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
    <li><code>num</code> only consists of digits and does not contain any leading zeros.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Find the right-most odd digit in the string.</p>


<strong>C++</strong>

```
//  Topic   : 1903. Largest Odd Number in String
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int i;
        for (i = n - 1; i >= 0; i--)
            if ((num[i] - '0') % 2)
                break;
        return num.substr(0, i + 1);
    }
};
```