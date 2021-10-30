# [2055. Plates Between Candles](https://leetcode.com/problems/plates-between-candles/)


## Description:

<p>There is a long table with a line of plates and candles arranged on top of it. You are given a <strong>0-indexed</strong> string s consisting of characters <code>'\ast'</code> and <code>'\mid'</code> only, where a <code>'\ast'</code> represents a <strong>plate</strong> and a '\mid' represents a <strong>candle</strong>.</p>
<p>You are also given a <strong>0-indexed</strong> 2D integer array queries where queries[i] = [lefti, righti] denotes the <strong>substring</strong> s[lefti...righti] (<strong>inclusive</strong>). For each query, you need to find the number of plates <strong>between candles</strong> that are <strong>in the substring</strong>. A plate is considered <strong>between candles</strong> if there is at least one candle to its left <strong>and</strong> at least one candle to its right <strong>in the substring</strong>.</p>
<ul>
    <li>For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle <strong>in the substring</strong> to its left <strong>and</strong> right.</li>
</ul>
<p>Return an integer array answer where answer[i] is the answer to the ith query.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/04/ex-1.png)</br>
<pre>
<strong>Input:</strong> s = "**|**|***|", queries = [[2,5],[5,9]]
<strong>Output:</strong> [2,3]
<strong>Explanation:</strong> 
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/10/04/ex-2.png)</br>
<pre>
<strong>Input:</strong> s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
<strong>Output:</strong> [9,0,0,0,0]
<strong>Explanation:</strong>
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.
</pre>


## Constraints:

<ul>
  <li><code>3 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
  <li><code>s</code> consists of <code>'*'</code> and <code>'|'</code> characters.</li>
  <li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
  <li><code>queries[i].length == 2</code></li>
  <li><code>0 &lt;= left<sub>i</sub> &lt;= right<sub>i</sub> &lt; s.length</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Firstly, <strong>sort</strong> <code>events</code> by their start times in an increasing order. Then for each event <code>i</code>, we check whether we can get the maximum sum by attending it. So, we need to find the maximum value <code>maxv</code> of the events on the left side of it which has no conflict with it, i.e. end time smaller than the start time of current event. We can use a <strong>heap</strong> to keep the events up to now by their end times increasing.</p>

 
<strong>C++</strong>

```
//  Topic   ：2055. Plates Between Candles (https://leetcode.com/problems/plates-between-candles/)
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(N + M)


class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = 0, idx = -1;
        vector<int> prefix(n, 0), suffix(n, 0), num(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '|')
            {
                idx = i;
                m++;
            }
            prefix[i] = idx;
            num[i] = m;
        }
        idx = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '|')
                idx = i;
            suffix[i] = idx;
        }
        vector<int> ans;
        for (auto q : queries)
        {
            int l = q[0], r = q[1], j = prefix[r], i = suffix[l];
            if (i == -1 || j == -1 || j - i <= 1)
                ans.push_back(0);
            else
            {
                int n_c = num[j] - num[i] + 1;
                ans.push_back(j - i + 1 - n_c);
            }
        }
        return ans;
    }
};
```
