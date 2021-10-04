# [463. Island Perimeter](https://leetcode.com/problems/island-perimeter/)


## Description:

<p>You are given <code>row x col</code> grid representing a map where <code>grid[i][j] = 1</code> represents land and <code>grid[i][j] = 0</code> represents water.</p>
<p>Grid cells are connected <strong>horizontally/vertically</strong> (not diagonally). The <code>grid</code> is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).</p>
<p>The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
<strong>Output:</strong> 16
<strong>Explanation:</strong> The perimeter is the 16 yellow stripes in the image above.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> grid = [[1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> grid = [[1,0]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>row == grid.length</code></li>
  <li><code>col == grid[i].length</code></li>
  <li><code>1 &lt;= row, col &lt;= 100</code></li>
  <li><code>grid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
  <li>There is exactly one island in <code>grid</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Just traverse the whole matrix, if there is an island, check whether its surrounding cells are also islands.</p>


<strong>C++</strong>

```
//  Topic   : 463. Island Perimeter (https://leetcode.com/problems/island-perimeter/)
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(1)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j]  == 1)
                {
                    if (i == 0 || i > 0 && grid[i - 1][j] == 0)
                        ans += 1;
                    if (i == m || i < m - 1 && grid[i + 1][j] == 0)
                        ans += 1;
                    if (j == 0 || j > 0 && grid[i][j - 1] == 0)
                        ans += 1;
                    if (j == n || j < n && grid[i][j + 1] == 0)
                        ans += 1;
                }
            }
        return ans;
    }
};
```
