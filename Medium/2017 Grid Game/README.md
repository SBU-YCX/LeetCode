# [2017. Grid Game](https://leetcode.com/problems/grid-game/)


## Description:

<p>You are given a <strong>0-indexed</strong> 2D array <code>grid</code> of size <code>2 x n</code>, where <code>grid[r][c]</code> represents the number of points at position <code>(r, c)</code> on the matrix. Two robots are playing a game on this matrix.</p>

<p>Both robots initially start at <code>(0, 0)</code> and want to reach <code>(1, n-1)</code>. Each robot may only move to the <strong>right</strong> (<code>(r, c)</code> to <code>(r, c + 1)</code>) or <strong>down</strong> (<code>(r, c)</code> to <code>(r + 1, c)</code>).</p>

<p>At the start of the game, the <strong>first</strong> robot moves from <code>(0, 0)</code> to <code>(1, n-1)</code>, collecting all the points from the cells on its path. For all cells <code>(r, c)</code> traversed on the path, <code>grid[r][c]</code> is set to <code>0</code>. Then, the second robot moves from <code>(0, 0)</code> to <code>(1, n-1)</code>, collecting the points on its path. Note that their paths may intersect with one another.</p>

<p>The <strong>first</strong> robot wants to <strong>minimize</strong> the number of points collected by the <strong>second</strong> robot. In contrast, the <strong>second</strong> robot wants to <strong>maximize</strong> the number of points it collects. If both robots play <strong>optimally</strong>, return <em>the <strong>number of points</strong> collected by the <strong>second</strong> robot.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/09/08/a1.png)
<pre>
<strong>Input:</strong> grid = [[2,5,4],[1,5,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/09/08/a2.png)
<pre>
<strong>Input:</strong> grid = [[3,3,1],[8,5,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/09/08/a3.png)
<pre>
<strong>Input:</strong> grid = [[1,3,1,15],[1,3,3,1]]
<strong>Output:</strong> 7
<strong>Explanation:</strong>
The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
</pre>


## Constraints:

<ul>
    <li><code>grid.length == 2</code></li>
    <li><code>n == grid[r].length</code></li>
    <li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
    <li><code>1 &lt;= grid[r][c] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution :

<strong>Logical Thinking</strong>
<p>Since the robot can only move right or down, we need to find the best position <code>i</code> for the first robot to go down and obtain points <code>sum(grid[0][0], ..., grid[0][i]) + sum(grid[1][i], ..., grid[1][n - 1])</code>. Then, the path of the first path divide the grid into two parts -- top-right and bottom-left, and the second robot only have two choices: </p>
<ul>
    <li>go down immediately, and get the points <code>sum(grid[1][0], ..., grid[1][i - 1])</code></li>
    <li>stay up until the last, and get the points <code>sum(grid[0][i + 1], ..., grid[0][n - 1])</code></li>
</ul>

<p>The second robot will choose the maximum of the above two paths.To save time, we can use <strong>prefix sum</strong> to calculate the sum in advance.</p>


<strong>C++</strong>

```
//  Topic   ：2017. Grid Game (https://leetcode.com/problems/grid-game/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> presum(2, vector<long long>(n + 1, 0));
        for (int j = 1; j <= n; j++)
        {
            presum[0][j] = presum[0][j - 1] + grid[0][j - 1];
            presum[1][j] = presum[1][j - 1] + grid[1][j - 1];
        }
        long long ans = 2e18;
        for (int i = 1; i <= n; i++)
            ans = min<long long>(ans, max<long long>(presum[0][n] - presum[0][i], presum[1][i - 1]));
        return ans;
    }
};
```