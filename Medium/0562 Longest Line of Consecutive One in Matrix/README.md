# [562. Longest Line of Consecutive One in Matrix](https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/)


## Description:

<p>Given an <code>m x n</code> binary matrix <code>mat</code>, return <em>the length of the longest line of consecutive one in the matrix.</em></p>
<p>The line could be horizontal, vertical, diagonal, or anti-diagonal.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> mat = [[1,1,1,1],[0,1,1,0],[0,0,0,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>m == mat.length</code></li>
  <li><code>n == mat[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
  <li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
  <li><code>mat[i][1]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>It is a dynamic programming problem, for each position <code>{i, j}</code>, we check its top <code>{i - 1, j}</code>, left <code>{i, j - 1}</code>, top-left <code>{i - 1, j - 1}</code>, top-right <code>{i - 1, j + 1}</code> to see whether it can make the consecutive ones longer. For fear of messing up the directions, we use extra space here, i.e. one <code>m * n</code> matrix for each direction.</p>


<strong>C++</strong>

```
//  Topic   ：562. Longest Line of Consecutive One in Matrix (https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(M * N)


class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<vector<vector<int>>> ans(m + 2, vector<vector<int>>(n + 2, vector<int>(4, 0)));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (mat[i - 1][j - 1] == 1)
                {
                    res = max<int>(res, ans[i][j][0] = 1 + ans[i][j - 1][0]);
                    res = max<int>(res, ans[i][j][1] = 1 + ans[i - 1][j][1]);
                    res = max<int>(res, ans[i][j][2] = 1 + ans[i - 1][j - 1][2]);
                    res = max<int>(res, ans[i][j][3] = 1 + ans[i - 1][j + 1][3]);
                }
        return res;
    }
};
```
