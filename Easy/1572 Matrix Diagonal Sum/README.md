# [1572. Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)


## Description:

<p>Given a square matrix <code>mat</code>, return the sum of the matrix diagonals.</p>

<p>Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png)
<pre>
<strong>Input:</strong> mat = [[1,2,3],
                               [4,5,6],
                               [7,8,9]]
<strong>Output:</strong> 25
<strong>Explanation:</strong> Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> mat = [[1,1,1,1],
                               [1,1,1,1],
                               [1,1,1,1],
                               [1,1,1,1]]
<strong>Output:</strong> 8
<strong>Explanation:</strong>
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> mat = [[5]]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
</pre>


## Constraints:

<ul>
    <li><code>n == mat.length == mat[i].length</code></li>
    <li><code>1 &lt;= n &lt;= 100</code></li>
    <li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the process.</p>


<strong>C++</strong>

```
//  Topic   : 1572. Matrix Diagonal Sum
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (2 * i == n - 1)
                ans += mat[i][i];
            else
            {
                ans += mat[i][i];
                ans += mat[i][n - 1 - i];
            }
        }
        return ans;
    }
};
```
