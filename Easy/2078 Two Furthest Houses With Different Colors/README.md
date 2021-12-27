# [2078. Two Furthest Houses With Different Colors](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)


## Description:

<p>There are <code>n</code> houses evenly lined up on the street, and each house is beautifully painted. You are given a <strong>0-indexed</strong> integer array <code>colors</code> of length <code>n</code>, where <code>colors[i]</code> represents the color of the <code>i<sup>th</sup></code> house.</p>

<p>Return <em>the <strong>maximum</strong> distance between <strong>two</strong> houses with <strong>different</strong> colors.</em></p>

<p>The distance between the <code>i<sup>th</sup></code> and <code>j<sup>th</sup></code> houses is <code>abs(i - j)</code>, where <code>abs(x)</code> is the <strong>absolute value</strong> of <code>x</code>.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/31/eg1.png)
<pre>
<strong>Input:</strong> colors = [<strong>1</strong>,1,1,<strong>6</strong>,1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
In the above image, color 1 is blue, and color 6 is red.
The furthest two houses with different colors are house 0 and house 3.
House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
Note that houses 3 and 6 can also produce the optimal answer.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/10/31/eg2.png)
<pre>
<strong>Input:</strong> colors = [<strong>1</strong>,8,3,8,<strong>3</strong>]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
The furthest two houses with different colors are house 0 and house 4.
House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> colors = [<strong>0</strong>,<strong>1</strong>]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
The furthest two houses with different colors are house 0 and house 1.
House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.
</pre>


## Constraints:

<ul>
  <li><code>n == colors.length</code></li>
  <li><code>2 &lt;= n &lt;= 100</code></li>
  <li><code>0 &lt;= colors[i] &lt;= 100</code></li>
  <li><code>Test data are generated such that <strong>at least</strong> two houses have different colors.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Go through the whole array, each time we meet a new color, store the index of that color in a <strong>hash table</strong> <code>idx</code>. So, for each house, we only need to obtain the index of the left-most different color.</p>


<strong>C++</strong>

```
//  Topic   : 2078. Two Furthest Houses With Different Colors (https://leetcode.com/problems/two-furthest-houses-with-different-colors/)
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(N)


class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_map<int, int> idx;
        int n = colors.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            bool exist = false;
            for (auto& j : idx)
            {
                if (j.first != colors[i])
                    ans = max<int>(ans, i - j.second);
                else
                    exist = true;
            }
            if (!exist)
                idx[colors[i]] = i;
        }
        return ans;
    }
};
```