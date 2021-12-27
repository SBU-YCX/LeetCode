# [2077. Paths in Maze That Lead to Same Room](https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/)


## Description:

<p>A maze consists of <code>n</code> rooms numbered from <code>1</code> to <code>n</code>, and some rooms are connected by corridors. You are given a 2D integer array <code>corridors</code> where <code>corridors[i] = [room1<sub>i</sub>, room2<sub>i</sub>]</code> indicates that there is a corridor connecting <code>room1<sub>i</sub></code> and <code>room2<sub>i</sub></code>, allowing a person in the maze to go from <code>room1<sub>i</sub></code> to <code>room2<sub>i</sub></code> <strong>and vice versa</strong>.</p>

<p>The designer of the maze wants to know how confusing the maze is. The <strong>confusion score</strong> of the maze is the number of different cycles of <strong>length 3</strong>.</p>

<ul>
    <li>For example, <code>1 → 2 → 3 → 1</code> is a cycle of length 3, but <code>1 → 2 → 3 → 4</code> and <code>1 → 2 → 3 → 2 → 1</code> are not.</li>
</ul>

<p>Two cycles are considered to be <strong>different</strong> if one or more of the rooms visited in the first cycle is <strong>not</strong> in the second cycle.</p>

<p>Return <em>the <strong>confusion score</strong> of the maze.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/11/14/image-20211114164827-1.png)
<pre>
<strong>Input:</strong> n = 5, corridors = [[1,2],[5,2],[4,1],[2,4],[3,1],[3,4]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
One cycle of length 3 is 4 → 1 → 3 → 4, denoted in red.
Note that this is the same cycle as 3 → 4 → 1 → 3 or 1 → 3 → 4 → 1 because the rooms are the same.
Another cycle of length 3 is 1 → 2 → 4 → 1, denoted in blue.
Thus, there are two different cycles of length 3.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/11/14/image-20211114164851-2.png)
<pre>
<strong>Input:</strong> 0
<strong>Output:</strong> 
[null, 1, 2]
<strong>Explanation:</strong> 
There are no cycles of length 3.
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= n &lt;= 1000</code></li>
    <li><code>1 &lt;= corridors.length &lt;= 5 * 10<sup>4</sup></code></li>
    <li><code>corridors[i].length == 2</code></li>
    <li><code>1 &lt;= room1<sub>i</sub>, room2<sub>i</sub> &lt;= n</code></li>
    <li><code>room1<sub>i</sub> != room2<sub>i</sub></code></li>
    <li>There are no duplicate corridors.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using a 2-D vector <code>connect</code> where <code>connect[i][j] = true</code> indicats that there is a corridor between room <code>i</code> and room <code>j</code>. Then, for the two endpoints <code>n<sub>1</sub></code> and <code>n<sub>2</sub></code> of each corridor <code>e</code>, we enumerate all the rooms to count the number of rooms make both <code>connect[i][n<sub>1</sub>]</code> and <code>connect[i][n<sub>2</sub>]</code> be <code>true</code>, i.e. forming a cycle of length 3. Finally, since we count the same cycle three time (each corridor once), we need <code>ans / 3</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2077. Paths in Maze That Lead to Same Room (https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/)
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(N)


class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        for (auto& e : corridors)
        {
            connect[e[0] - 1][e[1] - 1] = true;
            connect[e[1] - 1][e[0] - 1] = true;
        }
        int ans = 0;
        for (auto& e : corridors)
        {
            int n1 = e[0] - 1, n2 = e[1] - 1;
            for (int i = 0; i < n; i++)
                if (connect[i][n1] && connect[i][n2])
                    ans++;
        }
        return (ans / 3);
    }
};
```