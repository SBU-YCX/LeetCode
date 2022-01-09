# [2133. Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/)


## Description:

<p>An <code>n x n</code> matrix is <strong>valid</strong> if every row and every column contains <strong>all</strong> the integers from <code>1</code> to <code>n</code> (<strong>inclusive</strong>).</p>

<p>Given an <code>n x n</code> integer matrix <code>matrix</code>, return <em><code>true</code> if the matrix is <strong>valid</strong>. Otherwise, return <code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/12/21/example1drawio.png)
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[3,1,2],[2,3,1]]
<strong>Output:</strong> true
<strong>Explanation:</strong> In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/12/21/example2drawio.png)
<pre>
<strong>Input:</strong> matrix = [[1,1,1],[1,2,3],[1,2,3]]
<strong>Output:</strong> false
<strong>Explanation:</strong> In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.
</pre>


## Constraints:

<ul>
    <li><code>n == matrix.length == matrix[i].length</code></li>
    <li><code>1 &lt;= n &lt;= 100</code></li>
    <li><code>1 &lt;= matrix[i][j] &lt;= n</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a <strong>bitmask</strong> <code>s</code> of length <code>n</code> such that <code>s[i]</code> indicate whether a row (or a column) contains number <code>i + 1</code>. Then check each row and each column.</p>


<strong>C++</strong>

```
//  Topic   : 2133. Check if Every Row and Column Contains All Numbers
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(N)


class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            string s = string(n, '0');
            for (int j = 0; j < n; j++)
                s[matrix[i][j] - 1] = '1';
            if (s != string(n, '1'))
                return false;
        }
        for (int j = 0; j < n; j++)
        {
            string t = string(n, '0');
            for (int i = 0; i < n; i++)
                t[matrix[i][j] - 1] = '1';
            if (t != string(n, '1'))
                return false;
        }
        return true;
    }
};
```
