# [63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)


## Description:

<p>A robot is located at the top-left corner of a <code>m x n</code> grid (marked 'Start' in the diagram below).</p>
<p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).</p>
<p>Now consider if some obstacles are added to the grids. How many unique paths would there be?</p>
<p>An obstacle and space is marked as <code>1</code> and <code>0</code> respectively in the grid.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)</br>
<pre>
<strong>Input:</strong> obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg)</br>
<pre>
<strong>Input:</strong> obstacleGrid = [[0,1],[0,0]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>m == obstacleGrid.length</code></li>
  <li><code>n == obstacleGrid[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 100</code></li>
  <li><code>obstacleGrid[i][j]</code> is <code>0</code> or <code>1</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>It is a <strong>Dynamic Programming</strong> problem, since the robot can only move either down or right, if there is no obstacle at <code>(i, j)</code>, then the number of ways to get to <code>(i, j)</code> is <code>ans[i][j] = ans[i - 1][j] + ans[i][j - 1]</code>. Instead of using an <code>m * n</code> matrix to store the results, we can just use a 1D array because each update only requires the value at <code>j</code> and <code>j - 1</code>.</p>


<strong>C++</strong>

```
//  Topic   ：63. Unique Paths II (https://leetcode.com/problems/unique-paths-ii/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(N)


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long> ans(n, 0);
        if (obstacleGrid[m - 1][n - 1] != 1)
            ans[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--)
            if (obstacleGrid[m - 1][j] != 1)
                ans[j] = ans[j + 1];
        for (int i = m - 2; i >= 0; i--)
        {
            if (obstacleGrid[i][n - 1] == 1)
                ans[n - 1] = 0;
            for (int j = n - 2; j >= 0; j--)
            {
                if (obstacleGrid[i][j] != 1)
                    ans[j] += ans[j + 1];
                else
                    ans[j] = 0;
            }
        }
        return ans[0];
    }
};
```
