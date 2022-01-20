# [1716. Calculate Money in Leetcode Bank](https://leetcode.com/problems/calculate-money-in-leetcode-bank/)


## Description:

<p>Hercy wants to save money for his first car. He puts money in the Leetcode bank <strong>every day</strong>.</p>

<p>He starts by putting in <code>$1</code> on Monday, the first day. Every day from Tuesday to Sunday, he will put in <code>$1</code> more than the day before. On every subsequent Monday, he will put in <code>$1</code> more than the <strong>previous Monday</strong>.</p>

<p>Given <code>n</code>, return <em>the total amount of money he will have in the Leetcode bank at the end of the <code>n<sup>th</sup></code> day.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> 10
<strong>Explanation:</strong> After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 37
<strong>Explanation:</strong> After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> n = 20
<strong>Output:</strong> 96
<strong>Explanation:</strong> After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can use a prefix sum array <code>week_sum</code> to store the total amount up to each day in the first week. Since there are <code>m = n / 7</code> complete weeks and <code>r = n % 7</code> extra days, we can separately calculate them</p>

<ul>
    <li>For complete weeks, we have <code>week_sum[6] + (week_sum[6] + 7) + (week_sum[6] + 7 * 2) + ... + (week_sum[6] + 7 * (m - 1)) = m * week_sum[6] + 7 * (m - 1) * m / 2</code></li>
    <li>For extra days, we have <code>week_sum[r - 1] + r * m</code></li>
</ul>


<strong>C++</strong>

```
//  Topic   : 1716. Calculate Money in Leetcode Bank
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    int totalMoney(int n) {
        vector<int> week_sum(7, 0);
        week_sum[0] = 1;
        for (int i = 1; i < 7; i++)
            week_sum[i] = week_sum[i - 1] + i + 1;
        int m = n / 7;
        int r = n % 7;
        int ans = m * week_sum[6] + 7 * (m - 1) * m / 2;
        if (r != 0)
            ans += (week_sum[r - 1] + r * m);
        return ans;
    }
};
```