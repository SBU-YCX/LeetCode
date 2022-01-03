# [2071. Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)


## Description:

<p>You have <code>n</code> tasks and <code>m</code> workers. Each task has a strength requirement stored in a <strong>0-indexed</strong> integer array <code>tasks</code>, with the <code>i<sup>th</sup></code> task requiring <code>tasks[i]</code> strength to complete. The strength of each worker is stored in a <strong>0-indexed</strong> integer array <code>workers</code>, with the <code>j<sup>th</sup></code> worker having <code>workers[j]</code> strength. Each worker can only be assigned to a <strong>single</strong> task and must have a strength <strong>greater than or equal</strong> to the task's strength requirement (i.e., <code>workers[j] &gt;= tasks[i]</code>).</p>

<p>Additionally, you have <code>pills</code> magical pills that will <strong>increase a worker's strength</strong> by <code>strength</code>. You can decide which workers receive the magical pills, however, you may only give each worker <strong>at most one</strong> magical pill.</p>

<p>Given the <strong>0-indexed</strong> integer arrays <code>tasks</code> and <code>workers</code> and the integers <code>pills</code> and <code>strength</code>, return <em>the <strong>maximum</strong> number of tasks that can be completed.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> tasks = [<strong>3</strong>,<strong>2</strong>,<strong>1</strong>], workers = [<strong>0</strong>,<strong>3</strong>,<strong>3</strong>], pills = 1, strength = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> tasks = [<strong>5</strong>,4], workers = [<strong>0</strong>,0,0], pills = 1, strength = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 >= 5)
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> tasks = [<strong>10</strong>,<strong>15</strong>,30], workers = [<strong>0</strong>,<strong>10</strong>,10,10,10], pills = 3, strength = 10
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 >= 10)
- Assign worker 1 to task 1 (10 + 10 >= 15)
The last pill is not given because it will not make any worker strong enough for the last task.
</pre>


## Constraints:

<ul>
    <li><code>n == tasks.length</code></li>
    <li><code>m == workers.length</code></li>
    <li><code>1 &lt;= n, m &lt;= 5 * 10<sup>4</sup></code></li>
    <li><code>0 &lt;= pills &lt;= m</code></li>
    <li><code>0 &lt;= tasks[i], workers[j], strength &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>For this problem, if we sort both <code>tasks</code> and <code>workers</code>, we actually want to assign <code>K</code> easiest tasks (i.e., <code>tasks[0], ..., tasks[K - 1]</code>) to <code>K</code> strongest workers (i.e., <code>workers[M - K], ..., workers[M - 1]</code>). To find the maximum <code>K</code>, we can use <strong>binary search</strong> between <code>0</code> and <code>min(M, N)</code>. To check whether a <code>K</code> meets the requirement, we can process the <code>K</code> tasks from hardest to easiest, and see if the strongest work can do the remaining hardest task:</p>

<ul>
    <li>If the worker <code>m - 1 - i</code> can do the task <code>i</code>, remove this task and worker</li>
    <li>If the worker <code>m - 1 - i</code> cannot do the task <code>i</code>
        <ul>
            <li>Find the weakest worker <code>m - 1 - j</code> that can do this task with the pill, remove this task and worker, decrease the number of pills</li>
            <li>If there are no pills left, we cannot assign <code>K</code> tasks</li>
        </ul>
    </li>
</ul>


<strong>C++</strong>

```
// Topic     : 2071. Maximum Number of Tasks You Can Assign (https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2081%20Sum%20of%20k-Mirror%20Numbers)
// Time      : O(logK * KlogK) where K = min(M, N) 
// Space     : O(K)


class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int l = 0, r = min<int>(tasks.size(), workers.size());
        while (l < r)
        {
            int m = (l + r + 1) / 2, k = 0;
            multiset<int> s(workers.end() - m, workers.end());
            for (int i = m - 1; i >= 0; i--)
            {
                auto j = prev(s.end());
                if (*j < tasks[i])
                {
                    j = s.lower_bound(tasks[i] - strength);
                    if (j == s.end() || ++k > pills)
                        break;
                }
                s.erase(j);
            }
            if (s.empty())
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
```
