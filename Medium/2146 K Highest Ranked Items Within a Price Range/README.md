# [2146. K Highest Ranked Items Within a Price Range](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/)


## Description:

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>grid</code> of size <code>m x n</code> that represents a map of the items in a shop. The integers in the grid represent the following:</p>

<ul>
    <li><code>0</code> represents a wall that you cannot pass through.</li>
    <li><code>1</code> represents an empty cell that you can freely move to and from.</li>
    <li>All other positive integers represent the price of an item in that cell. You may also freely move to and from these item cells.</li>
</ul>

<p>It takes <code>1</code> step to travel between adjacent grid cells.</p>

<p>You are also given integer arrays <code>pricing</code> and <code>start</code> where <code>pricing = [low, high]</code> and <code>start = [row, col]</code> indicates that you start at the position <code>(row, col)</code> and are interested only in items with a price in the range of <code>[low, high]</code> (<strong>inclusive</strong>). You are further given an integer <code>k</code>.</p>

<p>You are interested in the <strong>positions</strong> of the <code>k</code> <strong>highest-ranked</strong> items whose prices are <strong>within</strong> the given price range. The rank is determined by the <strong>first</strong> of these criteria that is different:</p>

<ol>
    <li>Distance, defined as the length of the shortest path from the <code>start</code> (<strong>shorter</strong> distance has a higher rank).</li>
    <li>Price (<strong>lower</strong> price has a higher rank, but it must be <strong>in the price range</strong>).</li>
    <li>The row number (<strong>smaller</strong> row number has a higher rank).</li>
    <li>The column number (<strong>smaller</strong> column number has a higher rank).</li>
</ol>

<p>Return <em>the <code>k</code> highest-ranked items within the price range <strong>sorted</strong> by their rank (highest to lowest).</em> If there are fewer than <code>k</code> reachable items within the price range, return <em><strong>all</strong> of them.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/12/16/example1drawio.png)
<pre>
<strong>Input:</strong> grid = [[1,2,0,1],[1,3,0,1],[0,2,5,1]], pricing = [2,5], start = [0,0], k = 3
<strong>Output:</strong> [[0,1],[1,1],[2,1]]
<strong>Explanation:</strong> You start at (0,0).
With a price range of [2,5], we can take items from (0,1), (1,1), (2,1) and (2,2).
The ranks of these items are:
- (0,1) with distance 1
- (1,1) with distance 2
- (2,1) with distance 3
- (2,2) with distance 4
Thus, the 3 highest ranked items in the price range are (0,1), (1,1), and (2,1).
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/12/16/example2drawio1.png)
<pre>
<strong>Input:</strong> grid = [[1,2,0,1],[1,3,3,1],[0,2,5,1]], pricing = [2,3], start = [2,3], k = 2
<strong>Output:</strong> [[2,1],[1,2]]
<strong>Explanation:</strong> You start at (2,3).
With a price range of [2,3], we can take items from (0,1), (1,1), (1,2) and (2,1).
The ranks of these items are:
- (2,1) with distance 2, price 2
- (1,2) with distance 2, price 3
- (1,1) with distance 3
- (0,1) with distance 4
Thus, the 2 highest ranked items in the price range are (2,1) and (1,2).
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/12/30/example3.png)
<pre>
<strong>Input:</strong> grid = [[1,1,1],[0,0,1],[2,3,4]], pricing = [2,3], start = [0,0], k = 3
<strong>Output:</strong> [[2,1],[2,0]]
<strong>Explanation:</strong> You start at (0,0).
With a price range of [2,3], we can take items from (2,0) and (2,1). 
The ranks of these items are: 
- (2,1) with distance 5
- (2,0) with distance 6
Thus, the 2 highest ranked items in the price range are (2,1) and (2,0). 
Note that k = 3 but there are only 2 reachable items within the price range.
</pre>


## Constraints:

<ul>
    <li><code>m == grid.length</code></li>
    <li><code>n == grid[i].length</code></li>
    <li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
    <li><code>pricing.length == 2</code></li>
    <li><code>2 &lt;= low &lt;= high &lt;= 10<sup>5</sup></code></li>
    <li><code>start.length == 2</code>
    <li><code>0 &lt;= row &lt;= m - 1</code></li>
    <li><code>0 &lt;= col &lt;= n - 1</code></li>
    <li><code>grid[row][col] &gt; 0</code></li>
    <li><code>1 &lt;= k &lt;= m * n</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>To sort the items with criteria, we can use a <strong>heap</strong> <code>pq</code>, then we use <strong>breadth first search</strong> to traverse all locations, and push the item into <code>pq</code> the first time we encounter it if its price satisfies the condition. Whenever there are more than <code>k</code> items in <code>pq</code>, pop them up until <code>pq.size() <= k</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2146. K Highest Ranked Items Within a Price Range
//  Author  : YCX
//  Time    : O(NlogK)
//  Space   : O(N)


class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<int> dirs = {0, 1, 0, -1, 0};
        priority_queue<tuple<int, int, int, int>> pq;
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = 0;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second, d = visited[x][y], v = grid[x][y];
            q.pop();
            if (v <= pricing[1] && v >= pricing[0])
            {
                pq.push({d, v, x, y});
                if (pq.size() > k)
                    pq.pop();
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0 || visited[nx][ny] <= d + 1)
                    continue;
                visited[nx][ny] = d + 1;
                q.push({nx, ny});
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            auto t = pq.top();
            ans.push_back({get<2>(t), get<3>(t)});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```