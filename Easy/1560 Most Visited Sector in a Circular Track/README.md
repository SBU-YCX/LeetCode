# [1560. Most Visited Sector in a Circular Track](https://leetcode.com/problems/most-visited-sector-in-a-circular-track/)


## Description:

<p>Given an integer <code>n</code> and an integer array <code>rounds</code>. We have a circular track which consists of <code>n</code> sectors labeled from <code>1</code> to <code>n</code>. A marathon will be held on this track, the marathon consists of <code>m</code> rounds. The <code>i<sup>th</sup></code> round starts at sector <code>rounds[i - 1]</code> and ends at sector <code>rounds[i]</code>. For example, round 1 starts at sector <code>rounds[0]</code> and ends at sector <code>rounds[1]</code></p>

<p>Return <em>an array of the most visited sectors sorted in <strong>ascending</strong> order.</em></p>

<p>Notice that you circulate the track in ascending order of sector numbers in the counter-clockwise direction (See the first example).</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2020/08/14/tmp.jpg)
<pre>
<strong>Input:</strong> n = 4, rounds = [1,3,1,2]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> The marathon starts at sector 1. The order of the visited sectors is as follows:
1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2) --> 2 (end of round 3 and the marathon)
We can see that both sectors 1 and 2 are visited twice and they are the most visited sectors. Sectors 3 and 4 are visited only once.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 2, rounds = [2,1,2,1,2,1,2,1,2]
<strong>Output:</strong> [2]
<strong>Explanation:</strong>
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> n = 7, rounds = [1,3,5,7]
<strong>Output:</strong> [1,2,3,4,5,6,7]
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= n &lt;= 100</code></li>
    <li><code>1 &lt;= m &lt;= 100</code></li>
    <li><code>rounds.length == m + 1</code></li>
    <li><code>1 &lt;= rounds[i] &lt;= n</code></li>
    <li><code>rounds[i] != rounds[i + 1]</code> for <code>0 &lt;= i &lt; m</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the process.</p>


<strong>C++</strong>

```
//  Topic   : 1560. Most Visited Sector in a Circular Track
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(N)


class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> visit(n, 0);
        visit[rounds[0] - 1] = 1;
        int m = rounds.size(), most = 0;
        for (int i = 0; i < m - 1; i++)
        {
            int end, start = rounds[i];
            if (rounds[i + 1] >= start)
                end = rounds[i + 1];
            else
                end = rounds[i + 1] + n;
            for (int j = start; j <= end - 1; j++)
            {
                visit[j % n]++;
                most = max<int>(most, visit[j % n]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (visit[i] == most)
                ans.push_back(i + 1);
        return ans;
    }
};
```
