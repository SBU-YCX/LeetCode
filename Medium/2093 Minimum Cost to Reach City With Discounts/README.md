# [2093. Minimum Cost to Reach City With Discounts](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/)


## Description:

<p>A series of highways connect <code>n</code> cities numbered from <coode>0</coode> to <code>n - 1</code>. You are given a 2D integer array <code>highways</code> where <code>highways[i] = [city1<sub>i</sub>, city2<sub>i</sub>, toll<sub>i</sub>]</code> indicates that there is a highway that connects <code>city1<sub>i</sub></code> and <code>city2<sub>i</sub></code>, allowing a car to go from <code>city1<sub>i</sub></code> to <code>city2<sub>i</sub></code> and <strong>vice versa</strong> for a cost of <code>toll<sub>i</sub></code>.</p>

<p>You are also given an integer <code>discounts</code> which represents the number of discounts you have. You can use a discount to travel across the <code>i<sup>th</sup></code> highway for a cost of <code>toll<sub>i</sub> / 2</code> (<strong>integer division</strong>). Each discount may only be used <strong>once</strong>, and you can only use at most <strong>one</strong> discount per highway.

<p>Return <em>the <strong>minimum total cost</strong> to go from city <code>0</code> to city <code>n - 1</code>, or <code>-1</code> if it is not possible to go from city <code>0</code> to city <code>n - 1</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/11/29/image-20211129222429-1.png)
<pre>
<strong>Input:</strong> n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], discounts = 1
<strong>Output:</strong> 9
<strong>Explanation:</strong> 
Go from 0 to 1 for a cost of 4.
Go from 1 to 4 and use a discount for a cost of 11 / 2 = 5.
The minimum cost to go from 0 to 4 is 4 + 5 = 9.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/11/29/image-20211129222650-4.png)
<pre>
<strong>Input:</strong> n = 4, highways = [[1,3,17],[1,2,7],[3,2,5],[0,1,6],[3,0,20]], discounts = 20
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
Go from 0 to 1 and use a discount for a cost of 6 / 2 = 3.
Go from 1 to 2 and use a discount for a cost of 7 / 2 = 3.
Go from 2 to 3 and use a discount for a cost of 5 / 2 = 2.
The minimum cost to go from 0 to 3 is 3 + 3 + 2 = 8.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/11/29/image-20211129222531-3.png)
<pre>
<strong>Input:</strong> n = 4, highways = [[0,1,3],[2,3,2]], discounts = 0
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
It is impossible to go from 0 to 3 so return -1.
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= n &lt;= 1000</code></li>
    <li><code>1 &lt;= highways.length &lt;= 1000</code></li>
    <li><code>highways[i].length == 3</code>
    <li><code>0 &lt;= city1<sub>i</sub>, city2<sub>i</sub> &lt;= n - 1</code></li>
    <li><code>city1<sub>i</sub> != city2<sub>i</sub></code></li>
    <li><code>0 &lt;= toll<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= discounts &lt;= 500</code></li>
    <li>There are no duplicate highways.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>If there is no <code>discount</code>, the problem becomes to find the shortest path from a single source to a single destination, and we can solve it using <strong>Dijkstra's Algorithm</strong>. With the help of <strong>heap</strong>, we each time find out the city with the smallest cost from city <code>0</code> for pruning. Now, we also need to consider <code>discounts</code>, so we can use <strong>dynamic programming</strong> and a 2-D vector <code>dp</code> is built to store the minimum cost from <code>0</code> to <code>i</code> with <code>k</code> discounts left in <code>dp[i][k]</code>. Correspondingly, when we push cities into the heap, besides the current cost, we also need to add the number of discounts left with it.</p>


<strong>C++</strong>

```
//  Topic   : 2093. Minimum Cost to Reach City With Discounts (https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/)
//  Author  : YCX
//  Time    : O(MlogM) [M = N ^ 2]
//  Space   : O(N * K + M)


class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> roads(n);
        for (auto& r : highways)
        {
            roads[r[0]].push_back({r[1], r[2]});
            roads[r[1]].push_back({r[0], r[2]});
        }
        vector<vector<int>> dp(n, vector<int>(discounts + 1, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        pq.push({0, {0, discounts}});
        while (!pq.empty())
        {
            int city = pq.top().first;
            int cost = pq.top().second.first;
            int disc = pq.top().second.second;
            if (city == n - 1)
                break;
            pq.pop();
            for (auto& p : roads[city])
            {
                int nxt = p.first, toll = p.second;
                if (cost + toll < dp[nxt][disc])
                {
                    dp[nxt][disc] = cost + toll;
                    pq.push({nxt, {dp[nxt][disc], disc}});
                }
                toll /= 2;
                if (disc > 0 && cost + toll < dp[nxt][disc - 1])
                {
                    dp[nxt][disc - 1] = cost + toll;
                    pq.push({nxt, {dp[nxt][disc - 1], disc - 1}});
                }
            }
        }
        if (pq.empty())
            return -1;
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

private: 
    struct cmp
    {
        bool operator() (pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
        {
            return a.second.first > b.second.first;
        }
    };
};
```