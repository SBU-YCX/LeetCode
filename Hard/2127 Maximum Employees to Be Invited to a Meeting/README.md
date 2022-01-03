# [2127. Maximum Employees to Be Invited to a Meeting](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/)


## Description:

<p>A company is organizing a meeting and has a list of <code>n</code> employees, waiting to be invited. They have arranged for a large <strong>circular</strong> table, capable of seating <strong>any number</strong> of employees.</p>

<p>The employees are numbered from <code>0</code> to <code>n - 1</code>. Each employee has a <strong>favorite</strong> person and they will attend the meeting <strong>only if</strong> they can sit next to their favorite person at the table. The favorite person of an employee is <strong>not</strong> themself.</p>

<p>Given a <strong>0-indexed</strong> integer array <code>favorite</code>, where <code>favorite[i]</code> denotes the favorite person of the <code>i<sup>th</sup></code> employee, return <em>the <strong>maximum number of employees</strong> that can be invited to the meeting.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/12/14/ex1.png)
<pre>
<strong>Input:</strong> favorite = [2,2,1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> favorite = [1,2,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/12/14/ex2.png)
<pre>
<strong>Input:</strong> favorite = [3,0,1,4,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
</pre>


## Constraints:

<ul>
    <li><code>n == favorite.length</code></li>
    <li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= favorite[i] &lt;= n - 1</code></li>
    <li><code>favorite[i] != i</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>There are two cases:</p>

<ul>
    <li>If <code>favorite[a] == b, favorite[b] == c, ..., favorite[k] == a</code>, all the employees forms a cycle, so we need to find the largest cycle in this directed graph. Specifically, for each connected component in the graph, we can use a vector <code>num</code> to keep the number of employees in the path from a random source <code>i</code> to <code>j</code>, also another vector <code>visited</code> is used to indicate whether an employee in this path. So, if <code>favorite[j] == k</code> and <code>visited[k] == true</code>, <code>k</code> appears in the past and we find a cycle with the size as <code>num[j] - num[k] + 1</code>.</li>
    <li>If <code>favorite[a] == b, favorite[b] == a</code>, they are satisfied with each other, so we can assign any other employees whoever wants to sit next to them, just like two "arms", we just need to find the longest paths to <code>a</code> and <code>b</code>. Then, the ends of these two arms are also satisfied but they are not required to sit next to each other, therefore, we can add another such an structure to the table, and so on.</li>
</ul>

<p>No matter which case, we can use <strong>depth-first search</strong> to traverse the whole graph.</p>


<strong>C++</strong>

```
// Topic     : 2127. Maximum Employees to Be Invited to a Meeting (https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2071%20Maximum%20Number%20of%20Tasks%20You%20Can%20Assign)
// Time      : O(N) 
// Space     : O(N)


class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size(), ans1 = 0, ans2 = 0;
        vector<bool> visited(n, false), inpath(n, false);
        vector<int> num(n, 0);
        unordered_map<int, vector<int>> nxt;
        for (int i = 0; i < n; i++)
            nxt[favorite[i]].push_back(i);
        for (int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            int k = 1;
            dfs1(nxt, favorite, i, k, n, num, visited, inpath, ans1);
        }
        for (int i = 0; i < n; i++)
            if (i == favorite[favorite[i]] && i < favorite[i])
                ans2 += dfs2(nxt, favorite, i) + dfs2(nxt, favorite, favorite[i]);
        return max<int>(ans1, ans2);
    }
    
private:
    void dfs1(unordered_map<int, vector<int>>& nxt, vector<int>& favorite, int i, int& k, int& n, vector<int>& num, vector<bool>& visited, vector<bool>& inpath, int& ans)
    {
        visited[i] = inpath[i] = true;
        num[i] = k++;
        int j = favorite[i];
        if (!visited[j])
            dfs1(nxt, favorite, j, k, n, num, visited, inpath, ans);
        if (inpath[j])
            ans = max<int>(ans, num[i] - num[j] + 1);
        inpath[i] = false;
    }
    
    int dfs2(unordered_map<int, vector<int>>& nxt, vector<int>& favorite, int i)
    {
        int ans = 1;
        for (auto& j : nxt[i])
            if (j != favorite[i])
                ans = max<int>(ans, dfs2(nxt, favorite, j) + 1);
        return ans;
    }
};
```
