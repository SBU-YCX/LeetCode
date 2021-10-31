# [2050. Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii/)


## Description:

<p>You are given an integer <code>n</code>, which indicates that there are <code>n</code> courses labeled from <code>1</code> to <code>n</code>. You are also given a 2D integer array <code>relations</code> where <code>relations[j] = [prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]</code> denotes that course <code>prevCourse<sub>j</sub></code> has to be completed <strong>before</strong> course <code>nextCourse<sub>j</sub></code> (prerequisite relationship). Furthermore, you are given a <strong>0-indexed</strong> integer array <code>time</code> where <code>time[i]</code> denotes how many <strong>months</strong> it takes to complete the <code>(i+1)<sup>th</sup></code> course.</p>
<p>You must find the <strong>minimum</strong> number of months needed to complete all the courses following these rules:</p>
<ul>
  <li>You may start taking a course at <strong>any time</strong> if the prerequisites are met.</li>
  <li><strong>Any number of courses</strong> can be taken at the <strong>same time</strong>.</li>
</ul>
<p>Return <em>the <strong>minimum</strong> number of months needed to complete all the courses.</em></p>
<p><strong>Note:</strong> The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/07/ex1.png)</br>
<pre>
<strong>Input:</strong> n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The figure above represents the given graph and the time required to complete each course. 
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/10/07/ex2.png)</br>
<pre>
<strong>Input:</strong> n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
<strong>Output:</strong> 12
<strong>Explanation:</strong> The figure above represents the given graph and the time required to complete each course.
You can start courses 1, 2, and 3 at month 0.
You can complete them after 1, 2, and 3 months respectively.
Course 4 can be taken only after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 = 7 months.
Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, i.e., after max(1,2,3,7) = 7 months.
Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months. 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
  <li><code>0 &lt;= relations.length &lt;= min(n * (n - 1) / 2, 5 * 10<sup>4</sup>)</code></li>
  <li><code>relations[j].length == 2</code></li>
  <li><code>1 &lt;= prevCourse<sub>j</sub>, nextCourse<sub>j</sub> &lt;= n</code></li>
  <li><code>prevCourse<sub>j</sub> != nextCourse<sub>j</sub></code></li>
  <li>All the pairs <code>[prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]</code> are <strong>unique</strong>.</li>
  <li><code>time.length == n</code></li>
  <li><code>1 &lt;= time[i] &lt;= 10<sup>4</sup></code></li>
  <li>The given graph is a directed acyclic graph.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>This problem belongs to the <strong>Topological Sort Problems</strong>, so we need to know the next courses and number of previous courses of a given course from <code>relations</code>. Specifically, we use a vector <code>prev</code> to count the number of previous courses and a map <code>next</code> to keep track of the next courses in a vector for each course. Then, the courses without prerequisite will be pushed into a heap <code>pq</code>. Until <code>pq</code> is empty, pop the earliest ended course <code>i</code> out, whose end time is <code>end</code>, and decrease the previous courses' number <code>prev[j]</code> of its next courses <code>j <in> next[i]</code> by <code>1</code>. If <code>prev[j]</code> becomes <code>0</code>, which means all the prerequisite courses of it are completed, push <code>j</code> into <code>pq</code> and update its expected end time as <code>end + time[j]</code>. The answer is the maximum of all the end times.</p>


<strong>C++</strong>

```
// Topic     : 2050. Parallel Courses III (https://leetcode.com/problems/parallel-courses-iii/)
// Author    : YCX
// Time      : O(M + N)
// Space     : O(M + N)


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m = relations.size(), k = 0, ans = 0;
        vector<int> prev(n, 0);
        unordered_map<int, vector<int>> next;
        for (int i = 0; i < m; i++)
        {
            next[relations[i][0]].push_back(relations[i][1]);
            prev[relations[i][1] - 1]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
            if (prev[i] == 0)
                pq.push({time[i], i + 1});
        while (!pq.empty())
        {
            int end = pq.top().first;
            int course = pq.top().second;
            pq.pop();
            ans = max<int>(ans, end);
            for (auto i : next[course])
            {
                prev[i - 1]--;
                if (prev[i - 1] == 0)
                    pq.push({time[i - 1] + end, i});
            }
        }
        return ans;
    }
};
```
