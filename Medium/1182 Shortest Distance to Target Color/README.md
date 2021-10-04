# [1182. Shortest Distance to Target Color](https://leetcode.com/problems/shortest-distance-to-target-color/)


## Description:

<p>You are given an array <code>colors</code>, in which there are three colors: <code>1</code>, <code>2</code> and <code>3</code>.</p>
<p>You are also given some queries. Each query consists of two integers <code>i</code> and <code>c</code>, return the shortest distance between the given index <code>i</code> and the target color <code>c</code>. If there is no solution return <code>-1</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
<strong>Output:</strong> [3,0,3]
<strong>Explanation:</strong> 
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> colors = [1,2], queries = [[0,3]]
<strong>Output:</strong> [-1]
<strong>Explanation:</strong> 
 There is no 3 in the array.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= colors.length &lt;= 5*10<sup>4</sup></code></li>
  <li><code>1 &lt;= colors[i] &lt;= 3</code></li>
  <li><code>1 &lt;= queries.length &lt;= 5*10<sup>4</sup></code></li>
  <li><code>queries[i].length == 2</code></li>
  <li><code>0 &lt;= queries[i][0] &lt; colors.length</code></li>
  <li><code>1 &lt;= queries[i][1] &lt;= 3</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using an 1D array <code>pos</code> to keep a record of the positions of three colors. We need to go through <code>colors</code> twice, one is from left to right and <code>pos</code> keeps the right-most position of each color on the left of current index <code>i</code>; the other one is from right to left and <code>pos</code> keeps the left-most position of each color on the right of current index <code>i</code>. For each <code>i</code>, we use a <code>n * 3</code> matrix to store the shortest distances between <code>i</code> and all colors.</p>


<strong>C++</strong>

```
//  Topic   ：1182. Shortest Distance to Target Color (https://leetcode.com/problems/shortest-distance-to-target-color/)
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(N)


class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size(), m = queries.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        vector<int> pos(3, -1);
        for (int i = 0; i < n; i++)
        {
            pos[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++)
                if (pos[j] != -1)
                    dp[i][j] = i - pos[j];
        }
        pos[0] = pos[1] = pos[2] = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            pos[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++)
                if (pos[j] != -1 && (dp[i][j] == -1 || dp[i][j] > pos[j] - i))
                    dp[i][j] = pos[j] - i;
        }  
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int p = queries[i][0], q = queries[i][1] - 1;
            ans.push_back(dp[p][q]);
        }
        return ans;
    }
};
```
