# [1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/)


## Description:

<p>There is a <strong>bi-directional</strong> graph with <code>n</code> vertices, where each vertex is labeled from <code>0</code> to <code>n - 1</code> (<strong>inclusive</strong>). The edges in the graph are represented as a 2D integer array <code>edges</code>, where each <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> denotes a bi-directional edge between vertex <code>u<sub>i</sub></code> and vertex <code>v<sub>i</sub></code>. Every vertex pair is connected by <strong>at most one</strong> edge, and no vertex has an edge to itself.</p>

<p>You want to determine if there is a <strong>valid path</strong> that exists from vertex <code>start</code> to vertex <code>end</code>.</p>

<p>Given <code>edges</code> and the integers <code>n</code>, <code>start</code>, and <code>end</code>, return <em><code>true</code> if there is a <strong>valid path</strong> from <code>start</code> to <code>end</code>, or <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png)
<pre>
<strong>Input:</strong> n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex2.png)
<pre>
<strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no path from vertex 0 to vertex 5.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= n &lt;= 2 * 10<sup>5</sup></code></li>
    <li><code>0 &lt;= edges.length &lt;= 2 * 10<sup>5</sup></code></li>
    <li><code>edges[i].length == 2</code></li>
    <li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
    <li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
    <li><code>0 &lt;= start, end &lt;= n - 1</code></li>
    <li>There are no duplicate edges.</li>
    <li>There are no self edges.</li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p>Using <strong>breadth-first search</strong> to check if we can arrive at <code>end</code> from <code>start</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1971. Find if Path Exists in Graph
//  Author  : YCX
//  Time    : O(M + N)
//  Space   : O(M + N)


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        int m = edges.size();
        unordered_map<int, vector<int>> connect;
        for (int i = 0; i < m; i++)
        {
            connect[edges[i][0]].push_back(edges[i][1]);
            connect[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == end)
                return true;
            for (auto& nxt : connect[cur])
                if (!visited[nxt])
                {
                    visited[nxt] = true;
                    q.push(nxt);
                }
        }
        return false;
    }
};
```


## Solution 2:

<strong>Logical Thinking</strong>
<p>Using <strong>union find</strong> to see if <code>start</code> and <code>end</code> belong to the same group.</p>


<strong>C++</strong>

```
//  Topic   : 1971. Find if Path Exists in Graph
//  Author  : YCX
//  Time    : O(MlogN)
//  Space   : O(N)


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> group(n, 0);
        for (int i = 0; i < n; i++)
            group[i] = i;
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            int root1 = findRoot(group, edges[i][0]);
            int root2 = findRoot(group, edges[i][1]);
            if (root1 != root2)
                group[root1] = root2;
        }
        return (findRoot(group, start) == findRoot(group, end));
    }
    
private: 
    int findRoot(vector<int>& group, int node)
    {
        if (group[node] == node)
            return node;
        return findRoot(group, group[node]);
    }
};
```