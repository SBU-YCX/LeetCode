# [1791. Find Center of Star Graph](https://leetcode.com/problems/find-center-of-star-graph/)


## Description:

<p>There is an undirected <strong>star</strong> graph consisting of <code>n</code> nodes labeled from <code>1</code> to <code>n</code>. A star graph is a graph where there is one <strong>center</strong> node and <strong>exactly</strong> <code>n - 1</code> edges that connect the center node with every other node.</p>

<p>You are given a 2D integer array <code>edges</code> where each <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> indicates that there is an edge between the nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code>. Return <em>the center of the given star graph.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/02/24/star_graph.png)
<pre>
<strong>Input:</strong> edges = [[1,2],[2,3],[4,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> edges = [[1,2],[5,1],[1,3],[1,4]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>edges.length == n - 1</code></li>
    <li><code>edges[i].length == 2</code></li>
    <li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
    <li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
    <li>The given <code>edges</code> represent a valid star graph.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since it is a star graph, only one node has more than one connections and it must appear in each edge. So, we just need to find the common node in the first two edges.</p>


<strong>C++</strong>

```
//  Topic   : 1791. Find Center of Star Graph
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
    }
};
```