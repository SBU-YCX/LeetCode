# [1893. Check if All the Integers in a Range Are Covered](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/)


## Description:

<p>You are given a 2D integer array <code>ranges</code> and two integers <code>left</code> and <code>right</code>. Each <code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> represents an <strong>inclusive</strong> interval between <code>start<sub>i</sub></code> and <code>end<sub>i</sub></code>.</p>

<p>Return <em><code>true</code> if each integer in the inclusive range <code>[left, right]</code> is covered by <strong>at least one</strong> interval in <code>ranges</code>.</em> Return <em><code>false</code> otherwise.</em></p>

<p>An integer <code>x</code> is covered by an interval <code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> if <code>start<sub>i</sub> &lt;= x &lt;= end<sub>i</sub></code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
<strong>Output:</strong> true
<strong>Explanation:</strong> Every integer between 2 and 5 is covered:
- 2 is covered by the first range.
- 3 and 4 are covered by the second range.
- 5 is covered by the third range.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> ranges = [[1,10],[10,20]], left = 21, right = 21
<strong>Output:</strong> false
<strong>Explanation:</strong> 21 is not covered by any range.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= ranges.length &lt;= 50</code></li>
    <li><code>1 &lt;= start<sub>i</sub> <= end<sub>i</sub> &lt;= 50</code></li>
    <li><code>1 &lt;= left &lt;= right &lt;= 50</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the range of the problem is small, we can use <strong>prefix sum</strong> to calculate a occupation array <code>occupy</code>, and use <strong>line sweep</strong> to reduce the calculation time, then check each position between <code>left</code> and <code>right</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1893. Check if All the Integers in a Range Are Covered
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(M)


class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> occupy(52, 0);
        int n = ranges.size();
        for (int i = 0; i < ranges.size(); i++)
        {
            occupy[ranges[i][0]]++;
            occupy[ranges[i][1] + 1]--;
        }
        for (int i = 1; i <= right; i++)
        {
            occupy[i] += occupy[i - 1];
            if (i >= left && occupy[i] == 0)
                return false;
        }
        return true;
    }
};
```