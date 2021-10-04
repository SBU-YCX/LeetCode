# [62. Unique Paths](https://leetcode.com/problems/unique-paths/)


## Description:

<p>A robot is located at the top-left corner of a <code>m x n</code> grid (marked 'Start' in the diagram below).</p>
<p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).</p>
<p>How many possible unique paths are there?</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> m = 3, n = 7
<strong>Output:</strong> 28
<strong>Explanation:</strong> 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> m = 3, n = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> m = 7, n = 3
<strong>Output:</strong> 28
<strong>Explanation:</strong> 
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> m = 3, n = 3
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= m, n &lt;= 100</code></li>
  <li>It's guaranteed that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</li>
</ul>


## Solution1:

<strong>Logical Thinking</strong>
<p>It is a typical dynamic programming problem. Since the robot can only move either down or right, the number of paths to a specific point is the sum of the paths from its upside (unless it is on the first row) and the paths from its left side (unless it is on the first column). In order to save the space, we can use an 1D array instead of a 2D matrix.</p>


<strong>C++</strong>

```
//  Topic   ：62. Unique Paths (https://leetcode.com/problems/unique-paths/)
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(N)


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> num(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                num[j] += num[j - 1];
        return num[n - 1];
    }
};
```
