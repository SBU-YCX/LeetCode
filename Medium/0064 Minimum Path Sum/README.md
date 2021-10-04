# [64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)


## Description:

<p>Given a <code>m x n</code> <code>grid</code> filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.</p>
<p><strong>Note:</strong> You can only move either down or right at any point in time.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> grid = [[1,2,3],[4,5,6]]
<strong>Output:</strong> 12
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>m == grid.length</code></li>
  <li><code>n == grid[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 200</code></li>
  <li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since we can only move either down or right, for each position <code>{i, j}</code> in <code>grid</code>, we only need to choose the minimum one between the path from its top and the path from its left.</p>


<strong>C++</strong>

```
//  Topic   ：64. Minimum Path Sum (https://leetcode.com/problems/minimum-path-sum/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(M * N)


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    ans[i][j] = grid[i][j];
                else if (i == 0)
                    ans[i][j] = ans[i][j - 1] + grid[i][j];
                else if (j == 0)
                    ans[i][j] = ans[i - 1][j] + grid[i][j];
                else
                    ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]) + grid[i][j];
            }
        return ans[m - 1][n - 1];
    }
};
```