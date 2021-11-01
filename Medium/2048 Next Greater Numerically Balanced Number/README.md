# [2048. Next Greater Numerically Balanced Number](https://leetcode.com/problems/next-greater-numerically-balanced-number/)


## Description:

<p>An integer <code>x</code> is <strong>numerically balanced</strong> if for every digit d</code> in the number <code>x</code>, there are <strong>exactly</strong> <code>d</code> occurrences of that digit in <code>x</code>.</p>

<p>Given an integer <code>n</code>, return the <strong>smallest numerically balanced</strong> number <strong>strictly greater</strong> than <code>n</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 22
<strong>Explanation:</strong> 
22 is numerically balanced since:
- The digit 2 occurs 2 times. 
It is also the smallest numerically balanced number strictly greater than 1.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 1000
<strong>Output:</strong> 1333
<strong>Explanation:</strong> 
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times. 
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> n = 3000
<strong>Output:</strong> 3133
<strong>Explanation:</strong> 
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.
</pre>


## Constraints:

<ul>
  <li><code>0 &lt;= n &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the limitation <code>10<sup>6</sup></code>is not very large, we can use <strong>Brute Force</strong> to manually generate all the numerically balanced numbers and then check whether they are greater than <code>n</code>. Thanks to <code>votrubac@LeetCode</code>, we don't need to give all candidates, instead, we only need the smallest number with a fixed combination, e.g. <code>1</code>, <code>22</code>, <code>122</code>, <code>333</code> and so on, then use the <strong>next_permutation</strong> function to generate all the candidates.</p>

 
<strong>C++</strong>

```
//  Topic   ：2048. Next Greater Numerically Balanced Number (https://leetcode.com/problems/next-greater-numerically-balanced-number/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : better than O(N), worse than O(1)


class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> pool = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666};
        int ans = 1224444; 
        string ns = to_string(n);
        for (auto i : pool)
        {
            string cs = to_string(i);
            if (cs.length() < ns.length())
                continue;
            else if (cs.length() > ns.length())
                ans = min<int>(ans, i);
            else
            {
                do
                {
                    if (cs > ns)
                        ans = min<int>(ans, stoi(cs));
                } while (next_permutation(cs.begin(), cs.end()));
            }
        }
        return ans;
    }
};
```
