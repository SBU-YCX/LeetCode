# [2065. Maximum Path Quality of a Graph](https://leetcode.com/problems/maximum-path-quality-of-a-graph/)


## Description:

<p>There is an <strong>undirected</strong> graph with <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code> (<strong>inclusive</strong>). You are given a <strong>0-indexed</strong> integer array <code>values</code> where <code>values[i]</code> is the <strong>value</strong> of the <code>i<sup>th</sup></code> node. You are also given a <strong>0-indexed</strong> 2D integer array <code>edges</code>, where each <code>edges[j] = [u<sub>j</sub>, v<sub>j</sub>, time<sub>j</sub>]</code> indicates that there is an undirected edge between the nodes <code>u<sub>j</sub></code> and <code>v<sub>j</sub></code>, and it takes <code>time<sub>j</sub></code> seconds to travel between the two nodes. Finally, you are given an integer <code>maxTime</code>.</p>

<p>A <strong>valid path</strong> in the graph is any path that starts at node <code>0</code>, ends at node <code>0</code>, and takes <strong>at most</strong> <code>maxTime</code> seconds to complete. You may visit the same node multiple times. The <strong>quality</strong> of a valid path is the <strong>sum</strong> of the values of the <strong>unique nodes</strong> visited in the path (each node's value is added <strong>at most once</strong> to the sum).</p>

<p>Return <em>the <strong>maximum</strong> quality of a valid path.</em></p>

<p><strong>Note:</strong> There are <strong>at most four</strong> edges connected to each node.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/19/ex1drawio.png)</br>
<pre>
<strong>Input:</strong> values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
<strong>Output:</strong> 75
<strong>Explanation:</strong> 
One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 10 + 10 + 10 + 10 = 40 <= 49.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/10/19/ex2drawio.png)</br>
<pre>
<strong>Input:</strong> values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
<strong>Output:</strong> 25
<strong>Explanation:</strong> 
One possible path is 0 -> 3 -> 0. The total time taken is 10 + 10 = 20 <= 30.
The nodes visited are 0 and 3, giving a maximal path quality of 5 + 20 = 25.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/10/19/ex31drawio.png)</br>
<pre>
<strong>Input:</strong> values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
<strong>Output:</strong> 7
<strong>Explanation:</strong> 
One possible path is 0 -> 1 -> 3 -> 1 -> 0. The total time taken is 10 + 13 + 13 + 10 = 46 <= 50.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 1 + 2 + 4 = 7.
</pre>

<strong>Example 4:</strong>
<br/>![ex4](https://assets.leetcode.com/uploads/2021/10/21/ex4drawio.png)</br>
<pre>
<strong>Input:</strong> values = [0,1,2], edges = [[1,2,10]], maxTime = 10
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
The only path is 0. The total time taken is 0.
The only node visited is 0, giving a maximal path quality of 0.
</pre>


## Constraints:

<ul>
  <li><code>n == values.length</code></li>
  <li><code>1 &lt;= n &lt;= 1000</code></li>
  <li><code>0 &lt;= values[i] &lt;= 108</code></li>
  <li><code>0 &lt;= edges.length &lt;= 2000</code></li>
  <li><code>edges[j].length == 3</code></li>
  <li><code>0 &lt;= u<sub>j</sub> &lt; v<sub>j</sub> &lt;= n - 1</code></li>
  <li><code>10 &lt;= time<sub>j</sub>, maxTime &lt;= 100</code></li>
  <li>All the pairs <code>[u<sub>j</sub>, v<sub>j</sub>]</code> are <strong>unique</strong>.</li>
  <li>There are <strong>at most four</strong> edges connected to each node.</li>
  <li>The graph may not be connected.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since each node's value can be added only once, we'd better use <strong>Depth-First Search</strong> to solve this problem. So we start from node <code>0</code>, and try all possible paths (edges can be used more than once). Each time we come to a new node which is not counted before, update the current quality with its value. Whenever we come back to node <code>0</code>, update the answer with current quality. If current time is larger than the maximal time, stop the current path and try the next one.</p>


<strong>C++</strong>

```
// Topic     : 2065. Maximum Path Quality of a Graph (https://leetcode.com/problems/maximum-path-quality-of-a-graph/)
// Author    : YCX
// Time      : O(max<int>(M + N, T / minE))
// Space     : O(M + N)


class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        unordered_map<int, vector<pair<int, int>>> connect;
        for (auto e : edges)
        {
            connect[e[0]].push_back({e[1], e[2]});
            connect[e[1]].push_back({e[0], e[2]});
        }
        int n = values.size(), ans = 0;
        vector<int> cal(n, 0);
        cal[0] = 1;
        dfs(0, connect, cal, values, values[0], maxTime, 0, ans);
        return ans;
    }
    
private: 
    void dfs(int start, unordered_map<int, vector<pair<int, int>>>& connect, vector<int>& cal, vector<int>& values, int curQuality, int maxTime, int curTime, int& ans)
    {
        if (curTime > maxTime)
            return;
        if (start == 0)
            ans = max<int>(ans, curQuality);
        for (auto i : connect[start])
        {
            if (cal[i.first] == 0)
            {
                cal[i.first] = 1;
                dfs(i.first, connect, cal, values, curQuality + values[i.first], maxTime, curTime + i.second, ans);
                cal[i.first] = 0;
            }
            else
                dfs(i.first, connect, cal, values, curQuality, maxTime, curTime + i.second, ans);
        }
    }
};
```
