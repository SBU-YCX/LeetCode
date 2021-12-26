# [2087. Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)


## Description:

<p>There is an <code>m x n</code> grid, where <code>(0, 0)</code> is the top-left cell and <code>(m - 1, n - 1)</code> is the bottom-right cell. You are given an integer array <code>startPos</code> where <code>startPos = [start<sub>row</sub>, start<sub>col</sub>]</code> indicates that initially, a robot is at the cell <code>(start<sub>row</sub>, start<sub>col</sub>)</code>. You are also given an integer array <code>homePos</code> where <code>homePos = [home<sub>row</sub>, home<sub>col</sub>]</code> indicates that its <strong>home</strong> is at the cell <code>(home<sub>row</sub>, home<sub>col</sub>)</code>.</p>

<p>The robot needs to go to its home. It can move one cell in four directions: <strong>left</strong>, <strong>right</strong>, <strong>up</strong>, or <strong>down</strong>, and it can not move outside the boundary. Every move incurs some cost. You are further given two <strong>0-indexed</strong> integer arrays: <code>rowCosts</code> of length <code>m</code> and <code>colCosts</code> of length <code>n</code>.</p>

<ul>
    <li>If the robot moves <strong>up</strong> or <strong>down</strong> into a cell whose <strong>row</strong> is <code>r</code>, then this move costs <code>rowCosts[r]</code>.</li>
    <li>If the robot moves <strong>left</strong> or <strong>right</strong> into a cell whose <strong>column</strong> is <code>c</code>, then this move costs <code>colCosts[c]</code>.</li>
<ul>

<p>Return <em>the <strong>minimum total cost</strong> for this robot to return home.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/11/eg-1.png)
<pre>
<strong>Input:</strong> startPos = [1, 0], homePos = [2, 3], rowCosts = [5, 4, 3], colCosts = [8, 2, 6, 7]
<strong>Output:</strong> 18
<strong>Explanation:</strong>
One optimal path is that:
Starting from (1, 0)
-> It goes down to (2, 0). This move costs rowCosts[2] = 3.
-> It goes right to (2, 1). This move costs colCosts[1] = 2.
-> It goes right to (2, 2). This move costs colCosts[2] = 6.
-> It goes right to (2, 3). This move costs colCosts[3] = 7.
The total cost is 3 + 2 + 6 + 7 = 18
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> startPos = [0, 0], homePos = [0, 0], rowCosts = [5], colCosts = [26]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
The robot is already at its home. Since no moves occur, the total cost is 0.
</pre>


## Constraints:

<ul>
    <li><code>m == rowCosts.length</code></li>
    <li><code>n == colCosts.length</code></li>
    <li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= rowCosts[r], colCosts[c] &lt;= 10<sup>4</sup></code></li>
    <li><code>startPos.length == 2</code></li>
    <li><code>homePos.length == 2</code></li>
    <li><code>0 &lt;= startrow, homerow &lt; m</code></li>
    <li><code>0 &lt;= startcol, homecol &lt; n</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the <code>rowCosts</code> and <code>colCosts</code> are irrelevant, we can separately consider the row moving and column moving:</p>

<ul>
    <li>For row moving, the best path is going directly from <code>startPos<sub>row</sub></code> to <code>homePos<sub>row</sub></code></li>
    <li>For column moving, the best path is going directly from <code>startPos<sub>col</sub></code> to <code>homePos<sub>col</sub></code></li>
</ul>

 
<strong>C++</strong>

```
//  Topic   ：2087. Minimum Cost Homecoming of a Robot in a Grid (https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(1)


class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        if (startPos[0] >= homePos[0])
            for (int i = startPos[0] - 1; i >= homePos[0]; i--)
                ans += rowCosts[i];
        else
            for (int i = startPos[0] + 1; i <= homePos[0]; i++)
                ans += rowCosts[i];
        if (startPos[1] >= homePos[1])
            for (int j = startPos[1] - 1; j >= homePos[1]; j--)
                ans += colCosts[j];
        else
            for (int j = startPos[1] + 1; j <= homePos[1]; j++)
                ans += colCosts[j];
        return ans;
    }
};
```
