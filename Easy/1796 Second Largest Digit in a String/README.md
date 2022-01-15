# [1796. Second Largest Digit in a String](https://leetcode.com/problems/second-largest-digit-in-a-string/)


## Description:

<p>Given an alphanumeric string <code>s</code>, return <em>the <strong>second largest</strong> numerical digit that appears in <code>s</code>, or <code>-1</code> if it does not exist.</em></p>

<p>An <strong>alphanumeric</strong> string is a string consisting of lowercase English letters and digits.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "dfa12321afd"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "abc1111"
<strong>Output:</strong> -1
<strong>Explanation:</strong> The digits that appear in s are [1]. There is no second largest digit. 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s.length &lt;= 500</code></li>
    <li><code>s</code> consists of only lowercase English letters and/or digits.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Count the appearance of each digit and find the second largest one.</p>


<strong>C++</strong>

```
//  Topic   : 1796. Second Largest Digit in a String
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(10)


class Solution {
public:
    int secondHighest(string s) {
        vector<int> cache(10, 0);
        for (int i = 0; i < s.length(); i++)
            if (s[i] <= '9' && s[i] >= '0')
                cache[s[i] - '0'] = 1;
        int second = 0;
        for (int j = 9; j >= 0; j--)
            if (cache[j] == 1)
            {
                second += 1;
                if (second == 2)
                    return j;
            }
        return -1;
    }
};
```