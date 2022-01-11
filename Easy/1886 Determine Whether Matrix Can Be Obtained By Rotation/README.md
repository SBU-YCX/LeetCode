# [1886. Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)


## Description:

<p>Given two <code>n x n</code> binary matrices <code>mat</code> and <code>target</code>, return <em><code>true</code> if it is possible to make <code>mat</code> equal to <code>target</code> by <strong>rotating</strong> <code>mat</code> in <strong>90-degree increments</strong>, or <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/05/20/grid3.png)
<pre>
<strong>Input:</strong> mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
<strong>Output:</strong> true
<strong>Explanation:</strong> We can rotate mat 90 degrees clockwise to make mat equal target.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/05/20/grid4.png)
<pre>
<strong>Input:</strong> mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to make mat equal to target by rotating mat.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/05/26/grid4.png)
<pre>
<strong>Input:</strong> mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> We can rotate mat 90 degrees clockwise two times to make mat equal target.
</pre>


## Constraints:

<ul>
    <li><code>n == mat.length == target.length</code></li>
    <li><code>n == mat[i].length == target[i].length</code></li>
    <li><code>1 &lt;= n &lt;= 10</code></li>
    <li><code>mat[i][j]</code> and <code>target[i][j]</code> are either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the rotation process.</p>


<strong>C++</strong>

```
//  Topic   : 1886. Determine Whether Matrix Can Be Obtained By Rotation
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(M * N)


class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> tmp = mat;
        for (int i = 0; i <= 3; i++)
        {
            if (equal(tmp, target))
                return true;
            tmp = rotate(tmp);
        }
        return false;
    }
    
private: 
    vector<vector<int>> rotate(vector<vector<int>> mat) {
        int n = mat.size();
        vector<vector<int>> new_mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                new_mat[j][n - 1 - i] = mat[i][j];
        return new_mat;
    }
    
    bool equal(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] != b[i][j])
                    return false;
        return true;
    }
};
```