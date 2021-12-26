# [2097. Valid Arrangement of Pairs](https://leetcode.com/problems/valid-arrangement-of-pairs/)


## Description:

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>pairs</code> where <code>pairs[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>. An arrangement of <code>pairs</code> is <strong>valid</strong> if for every index <code>i</code> where <code>1 &lt;= i &lt; pairs.length</code>, we have <code>end<sub>i-1</sub> == start<sub>i</sub></code>.</p>

<p>Return <em><strong>any</strong> valid arrangement of <code>pairs</code>.</em></p>

<p><strong>Note:</strong> The inputs will be generated such that there exists a valid arrangement of <code>pairs</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> pairs = [[5,1],[4,5],[11,9],[9,4]]
<strong>Output:</strong> [[11,9],[9,4],[4,5],[5,1]]
<strong>Explanation:</strong> 
This is a valid arrangement since endi-1 always equals starti.
end<sub>0</sub> = 9 == 9 = start<sub>1</sub> 
end<sub>1</sub> = 4 == 4 = start<sub>2</sub>
end<sub>2</sub> = 5 == 5 = start<sub>3</sub>
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> pairs = [[1,3],[3,2],[2,1]]
<strong>Output:</strong> [[1,3],[3,2],[2,1]]
<strong>Explanation:</strong> 
This is a valid arrangement since endi-1 always equals starti.
end<sub>0</sub> = 3 == 3 = start<sub>1</sub>
end<sub>1</sub> = 2 == 2 = start<sub>2</sub>
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> pairs = [[1,2],[1,3],[2,1]]
<strong>Output:</strong> [[1,2],[2,1],[1,3]]
<strong>Explanation:</strong> 
This is a valid arrangement since endi-1 always equals starti.
end<sub>0 = 2 == 2 = start<sub>1</sub>
end<sub>1 = 1 == 1 = start<sub>2</sub>
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= pairs.length &lt;= 10<sup>5</sup></code></li>
    <li><code>pairs[i].length == 2</code></li>
    <li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
    <li><code>start<sub>i</sub> != end<sub>i</sub></code></li>
    <li>No two pairs are exactly the same.</li>
    <li>There <strong>exists</strong> a valid arrangement of <code>pairs</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>If we regard <code>pairs[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> as a directed path from <code>start<sub>i</sub></code> to <code>end<sub>i</sub></code>, the problem is indeed asking us to find an <strong>Eulerian Path</strong> in the graph. Therefore, we can utilize [<strong>Hierholzer's algorithm</strong>](https://en.wikipedia.org/wiki/Eulerian_path#Hierholzer's_algorithm). Specifically, we calculate the outdegree and indegree for each node using <strong>hash table</strong> <code>startIdx</code> and <code>endIdx</code>. The reason is that, if there is an Eulerian path in the graph, there is only one node <code>p</code> with <code>startIdx[p] &gt; endIdx[p]</code> as the source of the path, while one node <code>q</code> with <code>startIdx[p] &lt; endIdx[p]</code> as the destination. If there is a cycle, the source and the destination will be the same, then we can choose any node as the source. So we can greedily start from such <code>p</code> and follow the edges (if there are more than one edges, choose any one, since the cycle will always bring us back to this node again). With <strong>depth-first search</strong>, we can always enumerate all the edges and arrives at the destination.</p>


<strong>C++</strong>

```
//  Topic   : 2097. Valid Arrangement of Pairs (https://leetcode.com/problems/valid-arrangement-of-pairs/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> startIdx, endIdx;
        for (int i = 0; i < n; i++)
        {
            startIdx[pairs[i][0]].push_back(i);
            endIdx[pairs[i][1]].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto& p : startIdx)
            if (endIdx.count(p.first) == 0 || p.second.size() > endIdx[p.first].size())
            {
                int start = p.first;
                dfs(start, startIdx, pairs, ans);
                reverse(ans.begin(), ans.end());
                return ans;
            }
        dfs(pairs[0][0], startIdx, pairs, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
private: 
    void dfs(int start, unordered_map<int, vector<int>>& startIdx, vector<vector<int>>& pairs, vector<vector<int>>& ans)
    {
        while (startIdx[start].size() > 0)
        {
            int end = pairs[startIdx[start].back()][1];
            startIdx[start].pop_back();
            dfs(end, startIdx, pairs, ans);
            ans.push_back({start, end});
        }
    }
};
```