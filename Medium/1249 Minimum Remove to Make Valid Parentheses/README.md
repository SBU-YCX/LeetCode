# [1249. Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)


## Description:

<p>Given a string s of <code>'('</code>, <code>')'</code> and lowercase English characters.</p>
<p>Your task is to remove the minimum number of parentheses (<code>'('</code> or <code>')'</code>, in any positions) so that the resulting parentheses string is valid and return <strong>any</strong> valid string.</p>
<p>Formally, a parentheses string is valid if and only if:</p>
<ul>
    <li>It is the empty string, contains only lowercase characters, or</li>
    <li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid strings, or</li>
    <li>It can be written as <code>(A)</code>, where <code>A</code> is a valid string.</li>
</ul>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "lee(t(c)o)de)"
<strong>Output:</strong> "lee(t(c)o)de"
<strong>Explanation:</strong> "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "a)b(c)d"
<strong>Output:</strong> "ab(c)d"
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "))(("
<strong>Output:</strong> ""
<strong>Explanation:</strong> An empty string is also valid.
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> s = "(a(b(c)d)"
<strong>Output:</strong> "a(b(c)d)"
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
  <li><code>s[i]</code> is either <code>'('</code>,<code>')'</code>, or lowercase English letter.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>To solve this problem, we can traverse <code>s</code> twice. The first time, we go forward and ignore all the <code>')'</code> that cannot be paired, i.e. we use an extra variable <code>n</code> to keep the number of unpaired <code>'('</code>, when we meet a <code>')'</code>, if <code>n</code> is non-positive, we drop it. Similarly, the second time we go backward and drop all the <code>'('</code> that cannot be paired. </p>


<strong>C++</strong>

```
//  Topic   ：1249. Minimum Remove to Make Valid Parentheses (https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "", t = "";
        int n = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                n += 1;
                t += s[i];
            }
            else if (s[i] == ')')
            {
                if (n >= 1)
                {
                    n -= 1;
                    t += s[i];
                }
            }
            else
                t += s[i];
        }
        n = 0;
        for (int j = t.length() - 1; j >= 0; j--)
        {
            if (t[j] == ')')
            {
                n += 1;
                ans += t[j];
            }
            else if (t[j] == '(')
            {
                if (n >= 1)
                {
                    n -= 1;
                    ans += t[j];
                }
            }
            else
                ans += t[j];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```