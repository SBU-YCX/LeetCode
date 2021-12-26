# [2088. Count Fertile Pyramids in a Land](https://leetcode.com/problems/count-fertile-pyramids-in-a-land/)


## Description:

<p>A farmer has a <strong>rectangular grid</strong> of land with <code>m</code> rows and <code>n</code> columns that can be divided into unit cells. Each cell is either <strong>fertile</strong> (represented by a <code>1</code>) or <strong>barren</strong> (represented by a <code>0</code>). All cells outside the grid are considered barren.</p>

<p>A <strong>pyramidal plot</strong> of land can be defined as a set of cells with the following criteria:</p>
<ul>
    <li>The number of cells in the set has to be <strong>greater than</strong> <code>1</code> and all cells must be <strong>fertile</strong>.</li>
    <li>The <strong>apex</strong> of a pyramid is the <strong>topmost</strong> cell of the pyramid. The <strong>height</strong> of a pyramid is the number of rows it covers. Let <code>(r, c)</code> be the apex of the pyramid, and its height be <code>h</code>. Then, the plot comprises of cells <code>(i, j)</code> where <code>r &lt;= i &lt;= r + h - 1</code> and <code>c - (i - r) &lt;= j &lt;= c + (i - r)</code>.</li>
</ul>
<p>An <strong>inverse pyramidal plot</strong> of land can be defined as a set of cells with similar criteria:</p>
<ul>
    <li>The number of cells in the set has to be <strong>greater than</strong> <code>1</code> and all cells must be <strong>fertile</strong>.</li>
    <li>The <strong>apex</strong> of an inverse pyramid is the <strong>bottommost</strong> cell of the inverse pyramid. The <strong>height</strong> of an inverse pyramid is the number of rows it covers. Let <code>(r, c)</code> be the apex of the pyramid, and its height be <code>h</code>. Then, the plot comprises of cells <code>(i, j)</code> where <code>r - h + 1 &lt;= i &lt;= r</code> and <code>c - (r - i) &lt;= j &lt;= c + (r - i)</code>.</li>
</ul>
<p>Some examples of valid and invalid pyramidal (and inverse pyramidal) plots are shown below. Black cells indicate fertile cells.</p>

<br/>![ex](https://assets.leetcode.com/uploads/2021/11/08/image.png)

<p>Given a 0-indexed m x n binary matrix grid representing the farmland, return the total number of pyramidal and inverse pyramidal plots that can be found in grid.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/12/22/1.JPG)
<pre>
<strong>Input:</strong> grid = [[0,1,1,0],[1,1,1,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The 2 possible pyramidal plots are shown in blue and red respectively.
There are no inverse pyramidal plots in this grid. 
Hence total number of pyramidal and inverse pyramidal plots is 2 + 0 = 2.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/12/22/2.JPG)
<pre>
<strong>Input:</strong> grid = [[1,1,1],[1,1,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The pyramidal plot is shown in blue, and the inverse pyramidal plot is shown in red. 
Hence the total number of plots is 1 + 1 = 2.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/12/22/3.JPG)
<pre>
<strong>Input:</strong> grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
<strong>Output:</strong> 13
<strong>Explanation:</strong> 
There are 7 pyramidal plots, 3 of which are shown in the 2nd and 3rd figures.
There are 6 inverse pyramidal plots, 2 of which are shown in the last figure.
The total number of plots is 7 + 6 = 13.
</pre>


## Constraints:

<ul>
    <li><code>m == grid.length</code></li>
    <li><code>n == grid[i].length</code></li>
    <li><code>1 &lt;= m, n &lt;= 1000</code></li>
    <li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
    <li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We notice that if a cell is the topmost (or bottommost) of the pyramid, the number of such pyramids is <code>n<sub>p</sub> = h - 1</code>, where <code>h</code> is the height. Besides, for any cell <code>(i, j)</code>, its height is only decided by the heights of <code>(i + 1, j - 1)</code>, <code>(i + 1, j)</code> and <code>(i + 1, j + 1)</code> (in inverse pyramid, <code>(i - 1, j - 1)</code>, <code>(i - 1, j)</code> and <code>(i - 1, j + 1)</code>), i.e. <code>h<sub>i, j</sub> = min(h<sub>i + 1, j - 1</sub>, h<sub>i + 1, j</sub>, h<sub>i + 1, j + 1</sub>). Therefore, we can use <strong>dynamic programming</strong> here, once for pyramid and once for inverse pyramid</code>, to count the pyramids (or inverse pyramids) with every cell as the topmost (or bottommost) cell.</p>


<strong>C++</strong>

```
// Topic     : 2088. Count Fertile Pyramids in a Land (https://leetcode.com/problems/count-fertile-pyramids-in-a-land/)
// Author    : YCX
// Time      : O(M * N)
// Space     : O(M * N)


class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int ans = 0;
        ans += count(grid);
        reverse(grid.begin(), grid.end());
        ans += count(grid);
        return ans;
    }
    
private: 
    int count(vector<vector<int>> grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = m - 2; i >= 0; i--)
            for (int j = 1; j < n - 1; j++)
                if (grid[i][j])
                {
                    grid[i][j] = min<int>(grid[i + 1][j], min<int>(grid[i + 1][j - 1], grid[i + 1][j + 1])) + 1;
                    ans += (grid[i][j] - 1);
                }
        return ans;
    }
};
```