# [2100. Find Good Days to Rob the Bank](https://leetcode.com/problems/find-good-days-to-rob-the-bank/)


## Description:

<p>You and a gang of thieves are planning on robbing a bank. You are given a <strong>0-indexed</strong> integer array <code>security</code>, where <code>security[i]</code> is the number of guards on duty on the <code>i<sup>th</sup></code> day. The days are numbered starting from <code>0</code>. You are also given an integer <code>time</code>.</p>

<p>The <code>i<sup>th</sup></code> day is a good day to rob the bank if:</p>
<ul>
  <li>There are at least <code>time</code> days before and after the <code>i<sup>th</sup></code> day,</li>
  <li>The number of guards at the bank for the <code>time</code> days <strong>before</strong> <code>i</code> are <strong>non-increasing</strong>, and</li>
  <li>The number of guards at the bank for the <code>time</code> days <strong>after</strong> <code>i</code> are <strong>non-decreasing</strong>.</li>
</ul>
<p>More formally, this means day <code>i</code> is a good day to rob the bank if and only if <code>security[i - time] &gt;= security[i - time + 1] &gt;= ... &gt;= security[i] &lt;= ... &lt;= security[i + time - 1] &lt;= security[i + time]</code>.</p>

<p>Return a list of <strong>all</strong> days (<strong>0-indexed</strong>) that are good days to rob the bank. The order that the days are returned in does <strong>not</strong> matter.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> security = [5,3,3,3,5,6,2], time = 2
<strong>Output:</strong> [2,3]
<strong>Explanation:</strong> 
On day 2, we have security[0] &gt;= security[1] &gt;= security[2] &lt;= security[3] &lt;= security[4].
On day 3, we have security[1] &gt;= security[2] &gt;= security[3] &lt;= security[4] &lt;= security[5].
No other days satisfy this condition, so days 2 and 3 are the only good days to rob the bank.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> security = [1,1,1,1,1], time = 0
<strong>Output:</strong> [0,1,2,3,4]
<strong>Explanation:</strong> 
Since time equals 0, every day is a good day to rob the bank, so return every day.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> security = [1,2,3,4,5,6], time = 2
<strong>Output:</strong> []
<strong>Explanation:</strong> 
No day has 2 days before it that have a non-increasing number of guards.
Thus, no day is a good day to rob the bank, so return an empty list.
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> security = [1], time = 5
<strong>Output:</strong> []
<strong>Explanation:</strong> 
No day has 5 days before and after it.
Thus, no day is a good day to rob the bank, so return an empty list.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= security.length &lt;= 10<sup>5</sup></code></li>
  <li><code>0 &lt;= security[i], time &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Going through the whole array twice (forward and backward), during each pass, using <strong>Two Pointers</strong> to find the longest interval which meets the requirement on one side for each element. Then we just need to check for each element whether the interval on its both sides longer than the given <code>time</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2100. Find Good Days to Rob the Bank (https://leetcode.com/problems/find-good-days-to-rob-the-bank/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size(), m = n - 1;
        vector<vector<int>> range(n, vector<int>(2, 0));
        for (int i = n - 2; i >= 0; i--)
        {
            if (security[i] <= security[i + 1])
                range[i][0] = m - i;
            else
            {
                m = i;
                range[i][0] = m - i;
            }
        }
        m = 0;
        for (int i = 1; i < n; i++)
        {
            if (security[i] <= security[i - 1])
                range[i][1] = i - m;
            else
            {
                m = i;
                range[i][1] = i - m;
            }
        }
        vector<int> ans;
        for (int i = time; i < n - time; i++)
            if (range[i][0] >= time && range[i][1] >= time)
                ans.push_back(i);
        return ans;
    }
};
```
