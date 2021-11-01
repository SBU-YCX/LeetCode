# [2049. Count Nodes With the Highest Score](https://leetcode.com/problems/count-nodes-with-the-highest-score/)


## Description:

<p>There is a <strong>binary</strong> tree rooted at <code>0</code> consisting of n nodes. The nodes are labeled from <code>0</code> to <code>n - 1</code>. You are given a <strong>0-indexed</strong> integer array <code>parents</code> representing the tree, where <code>parents[i]</code> is the parent of node <code>i</code>. Since node <code>0</code> is the root, <code>parents[0] == -1</code>.</p>
<p>Each node has a <strong>score</strong>. To find the score of a node, consider if the node and the edges connected to it were <strong>removed</strong>. The tree would become one or more <strong>non-empty</strong> subtrees. The <strong>size</strong> of a subtree is the number of the nodes in it. The <strong>score</strong> of the node is the <strong>product of the sizes</strong> of all those subtrees.</p>
<p>Return <em>the <strong>number</strong> of nodes that have the <strong>highest score</strong>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br />![ex1](https://assets.leetcode.com/uploads/2021/10/03/example-1.png)
<pre>
<strong>Input:</strong> parents = [-1,2,0,2,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
- The score of node 0 is: 3 * 1 = 3
- The score of node 1 is: 4 = 4
- The score of node 2 is: 1 * 1 * 2 = 2
- The score of node 3 is: 4 = 4
- The score of node 4 is: 4 = 4
The highest score is 4, and three nodes (node 1, node 3, and node 4) have the highest score.
</pre>

<strong>Example 2:</strong>
<br />![ex2](https://assets.leetcode.com/uploads/2021/10/03/example-2.png)
<pre>
<strong>Input:</strong> parents = [-1,2,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- The score of node 0 is: 2 = 2
- The score of node 1 is: 2 = 2
- The score of node 2 is: 1 * 1 = 1
The highest score is 2, and two nodes (node 0 and node 1) have the highest score.
</pre>


## Constraints:

<ul>
  <li><code>n == parents.length</code></li>
  <li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
  <li><code>parents[0] == -1</code></li>
  <li><code>0 &lt;= parents[i] &lt;= n - 1</code> for <code>i != 0</code></li>
  <li><code>parents</code> represents a valid binary tree.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>From the given array <code>parents</code>, we can get the number of children of each node, then we can start from leaf nodes and use <strong>Breadth-First Search</strong> to calculate the number of nodes in each subtree and store them in an array <code>nodes</code>. Then, for each node <code>i</code>, the score is <code>(n - nodes[i]) * (nodes[child[i][j]] for j is i's child)</code>, and the answer is the maximum one.</p>

 
<strong>C++</strong>

```
//  Topic   ：2049. Count Nodes With the Highest Score (https://leetcode.com/problems/count-nodes-with-the-highest-score/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size(), ans = 0;
        long long maxv = 0; 
        vector<int> nodes(n, 1), children(n, 0);
        unordered_map<int, vector<int>> child;
        for (int i = 0; i < n; i++)
        {
            child[parents[i]].push_back(i);
            if (i != 0)
                children[parents[i]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (children[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == 0)
                continue;
            children[parents[cur]]--;
            nodes[parents[cur]] += nodes[cur];
            if (children[parents[cur]] == 0)
                q.push(parents[cur]);
        }
        for (int i = 0; i < n; i++)
        {
            long long prod = max<long long>(1, n - nodes[i]);
            for (int j = 0; j < child[i].size(); j++)
                prod *= nodes[child[i][j]];
            if (prod > maxv)
            {
                maxv = prod;
                ans = 1;
            }
            else if (prod == maxv)
                ans++;
        }
        return ans;
    }
};
```
