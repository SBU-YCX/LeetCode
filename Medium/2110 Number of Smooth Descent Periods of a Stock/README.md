# [2110. Number of Smooth Descent Periods of a Stock](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/)


## Description:

<p>You are given an integer array <code>prices</code> representing the daily price history of a stock, where <code>prices[i]</code> is the stock price on the <code>i<sup>th</sup></code> day.</p>

<p>A <strong>smooth descent period</strong> of a stock consists of <strong>one or more contiguous</strong> days such that the price on each day is <strong>lower</strong> than the price on the <strong>preceding day</strong> by <strong>exactly</strong> <code>1</code>. The first day of the period is exempted from this rule.</p>

<p>Return <em>the number of <strong>smooth descent periods</strong>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> prices = [3,2,1,4]
<strong>Output:</strong> 7
<strong>Explanation:</strong>
There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> prices = [8,6,7,7]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> prices = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
There is 1 smooth descent period: [1]
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Here, we use <strong>Two Pointers</strong> to find each longest continuous smooth descent segment. For each segment with length <code>i - j</code>, the total number of subarrays within this segment is <code>(i - j) * (i - j + 1)</code>. Finally, just add up all the subarrays.</p>

 
<strong>C++</strong>

```
//  Topic   ：2110. Number of Smooth Descent Periods of a Stock (https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return n;
        long long ans = 0;
        for (int i = 1, j = 0; i <= n; i++)
        {
            if (i == n || prices[i] != prices[i - 1] - 1)
            {
                ans += (long long)(i - j) * (i - j  + 1) / 2;
                j = i;
            }
        }
        return ans;
    }
};
```
