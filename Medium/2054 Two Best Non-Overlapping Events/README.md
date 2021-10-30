# [2054. Two Best Non-Overlapping Events](https://leetcode.com/problems/two-best-non-overlapping-events/)


## Description:

<p>You are given a <strong>0-indexed</strong> 2D integer array of <code>events</code> where <code>events[i] = [startTime<sub>i</sub>, endTime<sub>i</sub>, value<sub>i</sub>]</code>. The <code>i<sup>th</sup></code> event starts at <code>startTime<sub>i</sub></code> and ends at <code>endTime<sub>i</sub></code>, and if you attend this event, you will receive a value of <code>value<sub>i</sub></code>. You can choose <strong>at most two non-overlapping</strong> events to attend such that the sum of their values is <strong>maximized</strong>.</p>
<p>Return <em>this <strong>maximum</strong> sum.</em></p>
<p>Note that the start time and end time is <strong>inclusive</strong>: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time <code>t</code>, the next event must start at or after <code>t + 1</code>.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/09/21/picture5.png)</br>
<pre>
<strong>Input:</strong> events = [[1,3,2],[4,5,2],[2,4,3]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/09/21/picture1.png)</br>
<pre>
<strong>Input:</strong> events = [[1,3,2],[4,5,2],[1,5,5]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Choose event 2 for a sum of 5.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/09/21/picture3.png)</br>
<pre>
<strong>Input:</strong> events = [[1,5,3],[1,5,1],[6,6,5]]
<strong>Output:</strong> 8
<strong>Explanation:</strong> Choose events 0 and 2 for a sum of 3 + 5 = 8.
</pre>


## Constraints:

<ul>
  <li><code>2 &lt;= events.length &lt;= 10<sup>5</sup></code></li>
  <li><code>events[i].length == 3</code></li>
  <li><code>1 &lt;= startTimei &lt;= endTimei &lt;= 10<sup>9</sup></code></li>
  <li><code>1 &lt;= valuei &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Firstly, <strong>sort</strong> <code>events</code> by their start times in an increasing order. Then for each event <code>i</code>, we check whether we can get the maximum sum by attending it. So, we need to find the maximum value <code>maxv</code> of the events on the left side of it which has no conflict with it, i.e. end time smaller than the start time of current event. We can use a <strong>heap</strong> to keep the events up to now by their end times increasing.</p>

 
<strong>C++</strong>

```
//  Topic   ：2054. Two Best Non-Overlapping Events (https://leetcode.com/problems/two-best-non-overlapping-events/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int m = events.size(), maxv = 0, ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto i : events)
        {
            while (!q.empty() && q.top().first < i[0])
            {
                maxv = max<int>(maxv, q.top().second);
                q.pop();
            }
            ans = max<int>(ans, maxv + i[2]);
            q.push({i[1], i[2]});
        }
        return ans;
    }
    
private: 
    struct cmp
    {
        bool operator() (pair<int, int>& a, pair<int, int>& b)
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
};
```
