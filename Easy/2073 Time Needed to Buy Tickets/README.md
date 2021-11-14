# [2073. Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets/)


## Description:

<p>There are <code>n</code> people in a line queuing to buy tickets, where the <code>0<sup>th</sup></code> person is at the <strong>front</strong> of the line and the <code>(n - 1)<sup>th</sup></code> person is at the <strong>back</strong> of the line.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>tickets</code> of length <code>n</code> where the number of tickets that the <code>ith</code> person would like to buy is <code>tickets[i]</code>.</p>

<p>Each person takes <strong>exactly 1 second</strong> to buy a ticket. A person can only buy <strong>1 ticket at a time</strong> and has to go back to <strong>the end</strong> of the line (which happens <strong>instantaneously</strong>) in order to buy more tickets. If a person does not have any tickets left to buy, the person will <strong>leave</strong> the line.</p>

<p>Return <em>the <strong>time taken</strong> for the person at position <code>k</code> <strong>(0-indexed)</strong> to finish buying tickets.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> tickets = [2,3,2], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> tickets = [5,1,1,1], k = 0
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
</pre>


## Constraints:

<ul>
  <li><code>n == tickets.length</code></li>
  <li><code>1 &lt;= n &lt;= 100</code></li>
  <li><code>1 &lt;= tickets[i] &lt;= 100</code></li>
  <li><code>0 &lt;= k &lt; n</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can easily solve this problem through <code>simulation</code>. Suppose the <code>k<sup>th</sup></code> person needs <code>target = tickets[k]</code> tickets, then when this person leaves, the people in front of him <code>i < k</code> must have bought the same number of tickets (if they need more tickets), i.e. each of them bought <code>min(target, tickets[i])</code>. Similarly, the people behind him <code>i > k</code> must have bought <code>1</code> less tickets, i.e. <code>min(target - 1, tickets[i])</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2073. Time Needed to Buy Tickets (https://leetcode.com/problems/time-needed-to-buy-tickets/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, target = tickets[k], n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            if (i <= k)
                ans += min<int>(tickets[i], target);
            else
                ans += min<int>(tickets[i], target - 1);
        }
        return ans;
    }
};
```