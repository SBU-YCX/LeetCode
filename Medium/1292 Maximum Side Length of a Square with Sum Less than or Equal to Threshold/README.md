# [1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)


## Description:

<p>Given a <code>m x n</code> matrix <code>mat</code> and an integer <code>threshold</code>. Return <em>the maximum side-length of a square with a sum less than or equal to <code>threshold</code> or return <strong>0</strong> if there is no such square.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex](https://assets.leetcode.com/uploads/2019/12/05/e1.png)</br>
<pre>
<strong>Input:</strong> mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum side length of square with sum less than 4 is 2 as shown.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= m, n &lt;= 300</code></li>
  <li><code>m == mat.length</code></li>
  <li><code>n == mat[i].length</code></li>
  <li><code>0 &lt;= mat[i][j] &lt;= 10000</code></li>
  <li><code>0 &lt;= threshold &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Firstly, we traverse the whole matrix and calculate the sub-matrix sum up to <code>(i, j)</code> using <strong>Prefix Sum</strong>, which takes <code>O(mn)</code> time. Then, we need to check the maximum side-length for each pair of coordinates <code>(i, j)</code>. If we iterate all the possible lengths, it will take us <code>O(mnmin(m, n))</code> in total. Instead, we can only check the possible lengths longer than current <code>ans</code>, since all elements in <code>mat</code> are positive, we can jump out the checking for one <code>(i, j)</code> whenever the sum of sub-matrix is larger than the <code>threshold</code>. By doing so, we will only need <code>O(min(m + n))</code> extra time since each checking will always increase the <code>ans</code>, then the total time is reduced to <code>O(mn + min(m, n))</code>.</p>


<strong>C++</strong>

```
// Topic     : 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold (https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)
// Author    : YCX
// Time      : O(M * N + min(M, N))
// Space     : O(M * N)


class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<vector<int>> presum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + mat[i - 1][j - 1];
                int l = min<int>(i, j), p = ans + 1;
                while (p <= l && squaresum(presum, i - p, j - p, i, j) <= threshold)
                {
                    ans = p;
                    p++;
                }
            }
        return ans;
    }
    
private: 
    int squaresum(vector<vector<int>>& presum, int x1, int y1, int x2, int y2)
    {
        return presum[x2][y2] - presum[x2][y1] - presum[x1][y2] + presum[x1][y1];
    }
};
```
