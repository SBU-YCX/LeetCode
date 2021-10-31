# [2033. Minimum Operations to Make a Uni-Value Grid](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)


## Description:

<p>You are given a 2D integer <code>grid</code> of size <code>m x n</code> and an integer <code>x</code>. In one operation, you can <strong>add</strong> <code>x</code> to or <strong>subtract</strong> <code>x</code> from any element in the <code>grid</code>.</p>
<p>A <strong>uni-value grid</strong> is a grid where all the elements of it are equal.</p>
<p>Return <em>the <strong>minimum</strong> number of operations to make the grid <strong>uni-value</strong>. If it is not possible, return <code>-1</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/09/21/gridtxt.png)</br>
<pre>
<strong>Input:</strong> grid = [[2,4],[6,8]], x = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/09/21/gridtxt-1.png)</br>
<pre>
<strong>Input:</strong> grid = [[1,5],[2,3]], x = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can make every element equal to 3.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/09/21/gridtxt-2.png)</br>
<pre>
<strong>Input:</strong> grid = [[1,2],[3,4]], x = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to make every element equal.
</pre>


## Constraints:

<ul>
  <li><code>m == grid.length</code></li>
  <li><code>n == grid[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= x, grid[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>The problem is equivalent to [Minimize the MAE](https://en.wikipedia.org/wiki/Mean_absolute_error). Reshape the matrix into an 1-D vector, <strong>sort</strong> it and the uni-value should be the <strong>median</strong> of the sorted vector.</p>

 
<strong>C++</strong>

```
//  Topic   ：2033. Minimum Operations to Make a Uni-Value Grid (https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(N * M)


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> element(m * n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                element[i * n + j] = grid[i][j];
        sort(element.begin(), element.end());
        for (int i = 1; i < m * n; i++)
        {
            element[i] -= element[0];
            if (element[i] % x != 0)
                return -1;
        }
        element[0] = 0;
        int p = (m * n) / 2, ans = 0;
        for (int i = 0; i < m * n; i++)
            ans += (abs(element[i] - element[p]) / x);
        return ans;
    }
};
```
