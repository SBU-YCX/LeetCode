# [2132. Stamping the Grid](https://leetcode.com/problems/stamping-the-grid/)


## Description:

<p>You are given an <code>m x n</code> binary matrix <code>grid</code> where each cell is either <code>0</code> (empty) or <code>1</code> (occupied).</p>

<p>You are then given stamps of size <code>stampHeight x stampWidth</code>. We want to fit the stamps such that they follow the given <strong>restrictions</strong> and <strong>requirements</strong>:</p>

<ol>
    <li>Cover all the <strong>empty</strong> cells.</li>
    <li>Do not cover any of the <strong>occupied</strong> cells.</li>
    <li>We can put as <strong>many</strong> stamps as we want.</li>
    <li>Stamps can <strong>overlap</strong> with each other.</li>
    <li>Stamps are not allowed to be <strong>rotated</strong>.</li>
    <li>Stamps must stay completely <strong>inside</strong> the grid.</li>
</ol>

<p>Return <em><code>true</code> if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return <code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/11/03/ex1.png)
<pre>
<strong>Input:</strong> grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
<strong>Output:</strong> true
<strong>Explanation:</strong> We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/11/03/ex2.png)
<pre>
<strong>Input:</strong> grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
<strong>Output:</strong> false 
<strong>Explanation:</strong> There is no way to fit the stamps onto all the empty cells without the stamps going outside the grid.
</pre>


## Constraints:

<ul>
    <li><code>m == grid.length</code></li>
    <li><code>n == grid[r].length</code></li>
    <li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
    <li><code>grid[r][c]</code> is either <code>0</code> or <code>1</code>.</li>
    <li><code>1 &lt;= stampHeight, stampWidth &lt;= 10<sup>5</sup></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>First, there are two observations:</p>

<ul>
    <li>If we can fit a stamp whose right-bottom corner is <code>(i, j)</code>, we need to make sure that the area with left-top <code>(i - h + 1, j - w + 1)</code> and right-bottom <code>(i, j)</code> are all empty</li>
    <li>If a cell <code>(i, j)</code> is covered, the stamp's right-bottom corner should be in the area with left-top <code>(i, j)</code> and right-bottom <code>(i + h - 1, j + w - 1)</code></li>
</ul>

<p>Thus, we can first use <strong>prefix sum</strong> to calculate the number of occupied cells and find out the cells where a stamp's right-bottom corner could be. Then, use <strong>prefix sum</strong> again to find out whether there is a available stamp for each cell.</p>


<strong>C++</strong>

```
// Topic     : 2132. Stamping the Grid
// Author    : YCX 
// Time      : O(M * N) 
// Space     : O(M * N)


class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> blocks(m + 1, vector<int>(n + 1, 0)), stamps(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                blocks[i][j] = blocks[i - 1][j] + blocks[i][j - 1] - blocks[i - 1][j - 1] + grid[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 0 && i >= stampHeight && j >= stampWidth)
                {
                    int k = blocks[i][j] - blocks[i - stampHeight][j] - blocks[i][j - stampWidth] + blocks[i - stampHeight][j - stampWidth];
                    if (k == 0)
                        stamps[i - 1][j - 1] = 1;
                }
            }
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                stamps[i][j] += (stamps[i + 1][j] + stamps[i][j + 1] - stamps[i + 1][j + 1]);
                int x = min<int>(m, i + stampHeight), y = min<int>(n, j + stampWidth);
                int k = stamps[i][j] - stamps[x][j] - stamps[i][y] + stamps[x][y];
                if (grid[i][j] == 0 && k == 0)
                    return false;
            }
        return true;
    }
};
```
