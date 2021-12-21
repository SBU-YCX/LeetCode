# 2101. Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs/)


## Description:

<p>You are given a list of bombs. The <strong>range</strong> of a bomb is defined as the area where its effect can be felt. This area is in the shape of a <strong>circle</strong> with the center as the location of the bomb.</p>

<p>The bombs are represented by a <strong>0-indexed</strong> 2D integer array <code>bombs</code> where <code>bombs[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]</code>. <code>x<sub>i</sub></code> and <code>y<sub>i</sub></code> denote the X-coordinate and Y-coordinate of the location of the <code>i<sup>th</sup></code> bomb, whereas <code>r<sub>i</sub></code> denotes the <strong>radius</strong> of its range.</p>

<p>You may choose to detonate a <strong>single</strong> bomb. When a bomb is detonated, it will detonate <strong>all bombs</strong> that lie in its range. These bombs will further detonate the bombs that lie in their ranges.</p>

<p>Given the list of <code>bombs</code>, return <em>the <strong>maximum</strong> number of bombs that can be detonated if you are allowed to detonate <strong>only one</strong> bomb.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/11/06/desmos-eg-3.png)
<pre>
<strong>Input:</strong> bombs = [[2,1,3],[6,1,4]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/11/06/desmos-eg-2.png)
<pre>
<strong>Input:</strong> bombs = [[1,1,5],[10,10,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
Detonating either bomb will not detonate the other bomb, so the maximum number of bombs that can be detonated is 1.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/11/07/desmos-eg1.png)
<pre>
<strong>Input:</strong> bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
The best bomb to detonate is bomb 0 because:
- Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
- Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
- Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
Thus all 5 bombs are detonated.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= bombs.length &lt;= 100</code></li>
  <li><code>bombs[i].length == 3</code></li>
  <li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution :

<strong>Logical Thinking</strong>
<p>Firstly, create the directed graph by the relationship of the ditance of any pair of bombs and their ranges. Then, greedily check each bomb such that if we start from that bomb, how many bombs can be finally detonated. For the checking of each bomb, we can use <strong>Breadth-First Search</strong>.</p>


<strong>C++</strong>

```
//  Topic   : 2101. Detonate the Maximum Bombs (https://leetcode.com/problems/detonate-the-maximum-bombs/)
//  Author  : YCX
//  Time    : O((V + E) * V)
//  Space   : O(V + E)


class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 0;
        unordered_map<int, vector<int>> denote;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int c = within(bombs, i, j);
                if (c == 0)
                {
                    denote[i].push_back(j);
                    denote[j].push_back(i);
                }
                else if (c == 1)
                    denote[i].push_back(j);
                else if (c == 2)
                    denote[j].push_back(i);
            }
        for (int i = 0; i < n; i++)
            ans = max<int>(ans, bfs(denote, i, n));
        return ans;
    }
    
private: 
    int within(vector<vector<int>>& bombs, int i, int j)
    {
        long long dx = bombs[i][0] - bombs[j][0], dy = bombs[i][1] - bombs[j][1], r1 = bombs[i][2], r2 = bombs[j][2];
        long long dist = dx * dx + dy * dy, dr1 = r1 * r1, dr2 = r2 * r2;
        if (dist <= dr1 && dist <= dr2)
            return 0;
        else if (dist <= dr1 && dist > dr2)
            return 1;
        else if (dist > dr1 && dist <= dr2)
            return 2;
        else
            return 3;
    }
    
    int bfs(unordered_map<int, vector<int>>& denote, int i, int& n)
    {
        int ans = 0;
        vector<int> visited(n, 0);
        visited[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            ans++;
            for (auto& j : denote[k])
                if (visited[j] == 0)
                {
                    visited[j] = 1;
                    q.push(j);
                }
        }
        return ans;
    }
};
```