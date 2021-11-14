# [2076. Process Restricted Friend Requests](https://leetcode.com/problems/process-restricted-friend-requests/)


## Description:

<p>You are given an integer <code>n</code> indicating the number of people in a network. Each person is labeled from <code>0</code> to <code>n - 1</code>.</p>

<p>You are also given a <strong>0-indexed</strong> 2D integer array <code>restrictions</code>, where <code>restrictions[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> means that person <code>x<sub>i</sub></code> and person <code>y<sub>i</sub></code> <strong>cannot</strong> become <strong>friends</strong>, either <strong>directly</strong> or <strong>indirectly</strong> through other people.</p>

<p>Initially, no one is friends with each other. You are given a list of friend requests as a <strong>0-indexed</strong> 2D integer array <code>requests</code>, where <code>requests[j] = [u<sub>j</sub>, v<sub>j</sub>]</code> is a friend request between person <code>u<sub>j</sub></code> and person <code>v<sub>j</sub></code>.</p>

<p>A friend request is <strong>successful</strong> if <code>u<sub>j</sub></code> and <code>v<sub>j</sub></code> can be <strong>friends</strong>. Each friend request is processed in the given order (i.e., <code>requests[j]</code> occurs before <code>requests[j + 1]</code>), and upon a successful request, <code>u<sub>j</sub></code> and <code>v<sub>j</sub></code> <strong>become direct friends</strong> for all future friend requests.</p>

<p>Return <em>a <strong>boolean array</strong> <code>result, where each <code>result[j]</code> is <code>true</code> if the <code>j<sup>th</sup></code> friend request is <strong>successful</strong> or <code>false</code> if it is not.</em></p>

<p><strong>Note:</strong> If <code>u<sub>j</sub></code> and <code>v<sub>j</sub></code> are already direct friends, the request is still <strong>successful</strong>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]
<strong>Output:</strong> [true,false]
<strong>Explanation:</strong> 
Request 0: Person 0 and person 2 can be friends, so they become direct friends. 
Request 1: Person 2 and person 1 cannot be friends since person 0 and person 1 would be indirect friends (1--2--0).
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 3, restrictions = [[0,1]], requests = [[1,2],[0,2]]
<strong>Output:</strong> [true,false]
<strong>Explanation:</strong> 
Request 0: Person 1 and person 2 can be friends, so they become direct friends.
Request 1: Person 0 and person 2 cannot be friends since person 0 and person 1 would be indirect friends (0--2--1).
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> n = 5, restrictions = [[0,1],[1,2],[2,3]], requests = [[0,4],[1,2],[3,1],[3,4]]
<strong>Output:</strong> [true,false,true,false]
<strong>Explanation:</strong> 
Request 0: Person 0 and person 4 can be friends, so they become direct friends.
Request 1: Person 1 and person 2 cannot be friends since they are directly restricted.
Request 2: Person 3 and person 1 can be friends, so they become direct friends.
Request 3: Person 3 and person 4 cannot be friends since person 0 and person 1 would be indirect friends (0--4--3--1).
</pre>


## Constraints:

<ul>
  <li><code>2 &lt;= n &lt;= 1000</code></li>
  <li><code>0 &lt;= restrictions.length &lt;= 1000</code></li>
  <li><code>restrictions[i].length == 2</code></li>
  <li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= n - 1</code></li>
  <li><code>xi != yi</code></li>
  <li><code>1 &lt;= requests.length &lt;= 1000</code></li>
  <li><code>requests[j].length == 2</code></li>
  <li><code>0 &lt;= u<sub>j</sub>, v<sub>j</sub> &lt;= n - 1</code></li>
  <li><code>u<sub>j</sub> != v<sub>j</sub></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the friendship in this problem includes direct and indirect friends, we can use <strong>Union-Find</strong> to check the friendship between two people. Specifically, for each <code>requests[i]</code>, we find the groups of two people <code>requests[i][0]</code> and <code>requests[i][1]</code>, if the request is successful, these two groups merge into one, so we need to check whether any pair in <code>restrictions</code> share the same two groups, i.e. they will become friends.</p>

<p><strong>Note:</strong> when using loops and key word <code>auto</code>, try to use <code>auto&</code>, since it is passed by reference and the original data is directly used. Otherwise, if using <code>auto</code>, only the value is passed and each time a new variable is created and assigned with the value of original data, it is time consuming.</p>


<strong>C++</strong>

```
// Topic     : 2076. Process Restricted Friend Requests (https://leetcode.com/problems/process-restricted-friend-requests/)
// Author    : YCX
// Time      : O(M * N)
// Space     : O(N)


class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        int m = restrictions.size();
        vector<vector<int>> root(n, vector<int>(2, 1));
        for (int i = 0; i < n; i++)
            root[i][0] = i;
        vector<bool> ans;
        for (auto& r : requests)
        {
            int rt1 = find(root, r[0]), rt2 = find(root, r[1]);
            if (rt1 == rt2)
                ans.push_back(true);
            else if (check(restrictions, root, rt1, rt2))
            {
                ans.push_back(true);
                uni(root, rt1, rt2);
            }
            else
                ans.push_back(false);
        }
        return ans;
    }
    
private: 
    int find(vector<vector<int>>& root, int node)
    {
        if (root[node][0] == node)
            return node;
        return root[node][0] = find(root, root[node][0]);
    }
    
    void uni(vector<vector<int>>& root, int rt1, int rt2)
    {
        if (root[rt1][1] > root[rt2][1])
            root[rt2][0] = rt1;
        else if (root[rt1][1] < root[rt2][1])
            root[rt1][0] = rt2;
        else
        {
            root[rt1][0] = rt2;
            root[rt2][1]++;
        }
    }
    
    bool check(vector<vector<int>>& restrictions, vector<vector<int>>& root, int rt1, int rt2)
    {
        for (auto& r : restrictions)
        {
            int p1 = find(root, r[0]), p2 = find(root, r[1]);
            if (p1 == rt1 && p2 == rt2 || p1 == rt2 && p2 == rt1)
                return false;
        }
        return true;
    }
};
```
