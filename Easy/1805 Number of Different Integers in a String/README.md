# [1805. Number of Different Integers in a String](https://leetcode.com/problems/number-of-different-integers-in-a-string/)


## Description:

<p>You are given a string <code>word</code> that consists of digits and lowercase English letters.</p>

<p>You will replace every non-digit character with a space. For example, <code>"a123bc34d8ef34"</code> will become <code>" 123  34 8  34"</code>. Notice that you are left with some integers that are separated by at least one space: <code>"123"</code>, <code>"34"</code>, <code>"8"</code>, and <code>"34"</code>.</p>

<p>Return <em>the number of <strong>different</strong> integers after performing the replacement operations on <code>word</code>.</em></p>

<p>Two integers are considered different if their decimal representations <strong>without any leading zeros</strong> are different.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word = "a123bc34d8ef34"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word = "leet1234code234"
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word = "a1b01c001"
<strong>Output:</strong> 1
<strong>Explanation:</strong> The three integers "1", "01", and "001" all represent the same integer because
the leading zeros are ignored when comparing their decimal values.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= word.length &lt;= 1000</code></li>
    <li><code>word</code> consists of digits and lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Check all the characters, and split the string into segments with all digits. Pay attention to drop the leading zeros. Use a <strong>set</strong> to keep all different ones.</p>


<strong>C++</strong>

```
//  Topic   : 1816. Truncate Sentence
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> ans;
        string num = "";
        word += " ";
        bool zero = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (isdigit(word[i]))
            {
                if (word[i] == '0' && num.length() == 0)
                {
                    zero = true;
                    continue;
                }
                num += word[i];
            }
            else
            {
                if (num.length() == 0 && zero)
                    num += '0';
                if (num.length() != 0)
                    ans.insert(num);
                num = "";
                zero = false;
            }
        }
        return ans.size();
    }
};
```