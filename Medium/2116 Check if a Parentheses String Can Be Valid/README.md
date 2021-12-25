# [2116. Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)


## Description:

<p>A parentheses string is a <strong>non-empty</strong> string consisting only of <code>'('</code> and <code>')'</code>. It is valid if <strong>any</strong> of the following conditions is <strong>true</strong>:</p>
<ul>
    <li>It is <code>()</code>.</li>
    <li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid parentheses strings.</li>
    <li>It can be written as <code>(A)</code>, where <code>A</code> is a valid parentheses string.</li>
</ul>
<p>You are given a parentheses string <code>s</code> and a string <code>locked</code>, both of length <code>n</code>. <code>locked</code> is a binary string consisting only of <code>'0'</code>s and <code>'1'</code>s. For <strong>each</strong> index <code>i</code> of <code>locked</code>,</p>
<ul>
    <li>If <code>locked[i]</code> is <code>'1'</code>, you <strong>cannot</strong> change <code>s[i]</code>.</li>
    <li>But if <code>locked[i]</code> is <code>'0'</code>, you <strong>can</strong> change <code>s[i]</code> to either <code>'('</code> or <code>')'</code>.</li>
</ul>
<p>Return <em><code>true</code> if you can make <code>s</code> a valid parentheses string. Otherwise, return <code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/11/06/eg1.png)
<pre>
<strong>Input:</strong> s = "))()))", locked = "010100"
<strong>Output:</strong> true
<strong>Explanation:</strong>
locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "()()", locked = "0000"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
We do not need to make any changes because s is already valid.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = ")", locked = "0"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
locked permits us to change s[0]. 
Changing s[0] to either '(' or ')' will not make s valid.
</pre>


## Constraints:

<ul>
    <li><code>n == s.length == locked.length</code></li>
    <li>1 &lt;= n &lt;= 10<sup>5</sup></li>
    <li><code>s[i]</code> is either <code>'('</code> or <code>')'</code>.</li>
    <li><code>locked[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>When <code>locked[i]</code> is <code>'0'</code>, <code>s[i]</code> can be either <code>'('</code> or <code>')'</code>, so we can just store all such flexible positions <code>i</code>. Then, go through the whole string <code>s</code> and use <code>cnt</code> to count the number of fixed parentheses (increase when <code>'('</code>, decrease when <code>')'</code>). We know that whenever <code>cnt</code> is negative, there are more fixed right parentheses than left ones and we need to use those flexible one to make it up (let <code>s[i] = '('</code> and <code>locked[i] = '1'</code> to make sure it won't be used again). After one pass from left to right, we make all fixed right parentheses paired. Similarly, we can go through the whole string from right to left to make all fixed left parentheses paired. If we can make all fixed parentheses paired and the number of all reamining flexible parentheses is even, we can make <code>s</code> valid.</p>

 
<strong>C++</strong>

```
//  Topic   ：2116. Check if a Parentheses String Can Be Valid (https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length(), k = 0;
        deque<int> pos;
        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0')
                pos.push_back(i);
            else
            {
                if (s[i] == '(')
                    k++;
                else
                    k--;
                if (k < 0)
                {
                    if (pos.empty())
                        return false;
                    int j = pos.front();
                    pos.pop_front();
                    locked[j] = '1';
                    s[j] = '(';
                    k++;
                }
            }
        }
        k = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (locked[i] == '0')
                continue;
            else
            {
                if (s[i] == ')')
                    k++;
                else
                    k--;
                if (k < 0)
                {
                    if (pos.empty() || pos.back() < i)
                        return false;
                    pos.pop_back();
                    k++;
                }
            }
        }
        return ((k == 0) && (pos.size() % 2 == 0));
    }
};
```
