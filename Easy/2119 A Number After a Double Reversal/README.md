# [2119. A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal/)


## Description:

<p><strong>Reversing</strong> an integer means to reverse all its digits.</p>
<ul>
    <li>For example, reversing <code>2021</code> gives <code>1202</code>. Reversing <code>12300</code> gives <code>321</code> as the <strong>leading zeros are not retained</strong>.</li>
</ul>
<p>Given an integer <code>num</code>, <strong>reverse</strong> <code>num</code> to get <code>reversed1</code>, <strong>then reverse</strong> <code>reversed1</code> to get <code>reversed2</code>. Return <em><code>true</code> if <code>reversed2</code> equals <code>num</code>.</em> Otherwise return <em><code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> num = 526
<strong>Output:</strong> true
<strong>Explanation:</strong> 
Reverse num to get 625, then reverse 625 to get 526, which equals num.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> num = 1800
<strong>Output:</strong> false
<strong>Explanation:</strong> 
Reverse num to get 81, then reverse 81 to get 18, which does not equal num.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> num = 0
<strong>Output:</strong> true
<strong>Explanation:</strong> 
Reverse num to get 0, then reverse 0 to get 0, which equals num.
</pre>


## Constraints:

<ul>
  <li><code>0 &lt;= num &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We only need to check the last digit of number. A special case is <code>num = 0</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2119. A Number After a Double Reversal (https://leetcode.com/problems/a-number-after-a-double-reversal/)
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0)
            return true;
        int a = num % 10;
        return (a != 0);
    }
};
```