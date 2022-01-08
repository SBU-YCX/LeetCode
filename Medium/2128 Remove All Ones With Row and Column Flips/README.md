# [2128. Remove All Ones With Row and Column Flips](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/)


## Description:

<p>You are given an <code>m x n</code> binary matrix <code>grid</code>.</p>

<p>In one operation, you can choose <strong>any</strong> row or column and flip each value in that row or column (i.e., changing all <code>0</code>'s to <code>1</code>'s, and all <code>1</code>'s to <code>0</code>'s).</p>

<p>Return <em><code>true</code> if it is possible to remove all <code>1</code>'s from <code>grid</code> using <strong>any</strong> number of operations or <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2022/01/03/image-20220103191300-1.png)
<pre>
<strong>Input:</strong> grid = [[0,1,0],[1,0,1],[0,1,0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> One possible way to remove all 1's from grid is to:
- Flip the middle row
- Flip the middle column
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2022/01/03/image-20220103181204-7.png)
<pre>
<strong>Input:</strong> grid = [[1,1,0],[0,0,0],[0,0,0]]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to remove all 1's from grid.
</pre>

<strong>Example 2:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2022/01/03/image-20220103181224-8.png)
<pre>
<strong>Input:</strong> grid = [[0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are no 1's in grid.
</pre>


## Constraints:

<ul>
    <li><code>m == grid.length</code></li>
    <li><code>n == grid[i].length</code></li>
    <li><code>1 &lt;= m, n &lt;= 300</code></li>
    <li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Suppose we first flip rows, then columns, if we want to remove all ones, we need the columns have all ones or all zeros after row flips, i.e., after flipping some rows, all the rows should be the same. Therefore, we can just compare each row with the first row, if <code>grid[i]</code> is the same as <code>grid[0]</code>, the xor result should be all <code>0</code>s; if <code>grid[i]</code> is the same as <code>grid[0]</code> after flipping, the xor result should be all <code>1</code>s.</p>


<strong>C++</strong>

```
//  Topic   : 2128. Remove All Ones With Row and Column Flips
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(1)


class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++)
        {
            int k = grid[0][0] ^ grid[i][0];
            for (int j = 1; j < n; j++)
                if (grid[i][j] ^ grid[0][j] != k)
                    return false;
        }
        return true;
    }
};
```
