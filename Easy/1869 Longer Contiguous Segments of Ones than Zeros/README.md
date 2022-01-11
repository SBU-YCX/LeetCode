# [1869. Longer Contiguous Segments of Ones than Zeros](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/)


## Description:

<p>Given a binary string <code>s</code>, return <em><code>true</code> if the <strong>longest</strong> contiguous segment of <code>1</code>'s is <strong>strictly longer</strong> than the <strong>longest</strong> contiguous segment of <code>0</code>'s in <code>s</code>,</em> or return <em><code>false</code> otherwise.</em></p>

<ul>
    <li>For example, in <code>s = "110100010"</code> the longest continuous segment of <code>1</code>s has length <code>2</code>, and the longest continuous segment of <code>0</code>s has length <code>3</code>.</li>
</ul>

<p>Note that if there are no <code>0</code>'s, then the longest continuous segment of <code>0</code>'s is considered to have a length <code>0</code>. The same applies if there is no <code>1</code>'s.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "1101"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The longest contiguous segment of 1s has length 2: "1101"
The longest contiguous segment of 0s has length 1: "1101"
The segment of 1s is longer, so return true.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "111000"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
The longest contiguous segment of 1s has length 3: "111000"
The longest contiguous segment of 0s has length 3: "111000"
The segment of 1s is not longer, so return false.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "110100010"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
The longest contiguous segment of 1s has length 2: "110100010"
The longest contiguous segment of 0s has length 3: "110100010"
The segment of 1s is not longer, so return false.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 100</code></li>
    <li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Check the character one by one and count the length of each continuous segment.</p>


<strong>C++</strong>

```
//  Topic   : 1869. Longer Contiguous Segments of Ones than Zeros
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool checkZeroOnes(string s) {
        int n0 = 0, n1 = 0;
        int n = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                n += 1;
            else
            {
                if (s[i - 1] == '0')
                    n0 = max<int>(n0, n);
                else
                    n1 = max<int>(n1, n);
                n = 1;
            }
        }
        if (s[s.length() - 1] == '0')
            n0 = max<int>(n0, n);
        else
            n1 = max<int>(n1, n);
        return (n1 > n0);
    }
};
```