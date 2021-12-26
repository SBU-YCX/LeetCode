# [2120. Execution of All Suffix Instructions Staying in a Grid](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/)


## Description:

<p>There is an <code>n x n</code> grid, with the top-left cell at <code>(0, 0)</code> and the bottom-right cell at <code>(n - 1, n - 1)</code>. You are given the integer <code>n</code> and an integer array <code>startPos</code> where <code>startPos = [start<sub>row</sub>, start<sub>col</sub>]</code> indicates that a robot is initially at cell <code>(start<sub>row</sub>, start<sub>col</sub>)</code>.</p>

<p>You are also given a <strong>0-indexed</strong> string <code>s</code> of length <code>m</code> where <code>s[i]</code> is the <code>i<sup>th</sup></code> instruction for the robot: <code>'L'</code> (move left), <code>'R'</code> (move right), <code>'U'</code> (move up), and <code>'D'</code> (move down).</p>

<p>The robot can begin executing from any <code>i<sup>th</sup></code> instruction in <code>s</code>. It executes the instructions one by one towards the end of <code>s</code> but it stops if either of these conditions is met:

<ul>
    <li>The next instruction will move the robot off the grid.</li>
    <li>There are no more instructions left to execute.</li>
</ul>

<p>Return <em>an array <code>answer</code> of length <code>m</code> where <code>answer[i]</code> is <strong>the number of instructions</strong> the robot can execute if the robot <strong>begins executing from</strong> the <code>i<sup>th</sup> instruction in <code>s</code>.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/12/09/1.png)
<pre>
<strong>Input:</strong> n = 3, startPos = [0,1], s = "RRDDLU"
<strong>Output:</strong> [1,5,4,3,1,0]
<strong>Explanation:</strong> 
Starting from startPos and beginning execution from the ith instruction:
- 0th: "RRDDLU". Only one instruction "R" can be executed before it moves off the grid.
- 1st:  "RDDLU". All five instructions can be executed while it stays in the grid and ends at (1, 1).
- 2nd:   "DDLU". All four instructions can be executed while it stays in the grid and ends at (1, 0).
- 3rd:    "DLU". All three instructions can be executed while it stays in the grid and ends at (0, 0).
- 4th:     "LU". Only one instruction "L" can be executed before it moves off the grid.
- 5th:      "U". If moving up, it would move off the grid.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/12/09/2.png)
<pre>
<strong>Input:</strong> n = 2, startPos = [1,1], s = "LURD"
<strong>Output:</strong> [4,1,0,0]
<strong>Explanation:</strong> 
- 0th: "LURD".
- 1st:  "URD".
- 2nd:   "RD".
- 3rd:    "D".
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/12/09/3.png)
<pre>
<strong>Input:</strong> n = 1, startPos = [0,0], s = "LRUD"
<strong>Output:</strong> [0,0,0,0]
<strong>Explanation:</strong> 
No matter which instruction the robot begins execution from, it would move off the grid.
</pre>


## Constraints:

<ul>
    <li><code>m == s.length</code></li>
    <li><code>1 &lt;= n, m &lt;= 500</code></li>
    <li><code>startPos.length == 2</code>
    <li><code>0 &lt;= start<sub>row</sub>, start<sub>col</sub> &lt; n</code></li>
    <li><code>s</code> consists of <code>'L'</code>, <code>'R'</code>, <code>'U'</code>, and <code>'D'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using <strong>Brute Force</strong> here.</p>


<strong>C++</strong>

```
//  Topic   : 2120. Execution of All Suffix Instructions Staying in a Grid (https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/)
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(1)


class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.length();
        int ld = -startPos[1], rd = n - 1 - startPos[1], ud = -startPos[0], bd = n - 1 - startPos[0];
        unordered_map<char, pair<int, int>> dirs = {{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
        vector<vector<int>> move(m, vector<int>(2, 0));
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++)
        {
            int dx = 0, dy = 0;
            for (int j = i; j < m; j++)
            {
                dx += dirs[s[j]].first;
                dy += dirs[s[j]].second;
                if (dx < ud || dx > bd || dy < ld || dy > rd)
                {
                    ans[i] = j - i;
                    break;
                }
            } 
            if (ans[i] == -1)
                ans[i] = m - i;
        }   
        return ans;
    }
};
```