# [1582. Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)


## Description:

<p>Given an <code>m x n</code> binary matrix <code>mat</code>, return <em>the number of special positions in <code>mat</code>.</em></p>

<p>A position <code>(i, j)</code> is called <strong>special</strong> if <code>mat[i][j] == 1</code> and all other elements in row <code>i</code> and column <code>j</code> are <code>0</code> (rows and columns are <strong>0-indexed</strong>).</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/12/23/special1.jpg)
<pre>
<strong>Input:</strong> mat = [[1,0,0],[0,0,1],[1,0,0]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
</pre>

<strong>Example 2:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/12/24/special-grid.jpg)
<pre>
<strong>Input:</strong> mat = [[1,0,0],[0,1,0],[0,0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> (0, 0), (1, 1) and (2, 2) are special positions.
</pre>


## Constraints:

<ul>
    <li><code>m == mat.length</code></li>
    <li><code>n == mat[i].length</code></li>
    <li><code>1 &lt;= m, n &lt;= 100</code></li>
    <li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use <strong>hash tables</strong> to count the number of <code>1</code>s for each row and column.</p>


<strong>C++</strong>

```
//  Topic   : 1582. Special Positions in a Binary Matrix
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(N ^ 2)


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> numCol(m, 0);
        unordered_map<int, vector<int>> numRow;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1)
                {
                    numRow[j].push_back(i);
                    numCol[i] += 1;
                }
        int ans = 0;
        unordered_map<int, vector<int>>::iterator iter = numRow.begin();
        while (iter != numRow.end())
        {
            if (iter->second.size() == 1 && numCol[iter->second[0]] == 1)
                ans += 1;
            iter++;
        }
        return ans;
    }
};
```
