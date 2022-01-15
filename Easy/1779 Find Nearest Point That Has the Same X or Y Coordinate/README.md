# [1779. Find Nearest Point That Has the Same X or Y Coordinate](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/)


## Description:

<p>You are given two integers, <code>x</code> and <code>y</code>, which represent your current location on a Cartesian grid: <code>(x, y)</code>. You are also given an array <code>points</code> where each <code>points[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> represents that a point exists at <code>(a<sub>i</sub>, b<sub>i</sub>)</code>. A point is <strong>valid</strong> if it shares the same x-coordinate or the same y-coordinate as your location.</p>

<p>Return <em>the index (<strong>0-indexed</strong>) of the <strong>valid</strong> point with the smallest <strong>Manhattan distance</strong> from your current location.</em> If there are multiple, return <em>the valid point with the <strong>smallest</strong> index.</em> If there are no valid points, return <em><code>-1</code>.</em></p>

<p>The <strong>Manhattan distance</strong> between two points <code>(x<sub>1</sub>, y<sub>1</sub>)</code> and <code>(x<sub>2</sub>, y<sub>2</sub>)</code> is <code>abs(x<sub>1</sub> - x<sub>2</sub>) + abs(y<sub>1</sub> - y<sub>2</sub>)</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> x = 3, y = 4, points = [[3,4]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The answer is allowed to be on the same location as your current location.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> x = 3, y = 4, points = [[2,3]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no valid points.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= points.length &lt;= 10<sup>4</sup></code></li>
    <li><code>points[i].length == 2</code></li>
    <li><code>1 &lt;= x, y, a<sub>i</sub>, b<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Check each point.</p>


<strong>C++</strong>

```
//  Topic   : 1779. Find Nearest Point That Has the Same X or Y Coordinate
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int dist, n = points.size(), ans = 2e4, ans_coord = -1;
        for (int i = 0; i < n; i++)
        {
            if (points[i][0] == x)
            {
                dist = abs(points[i][1] - y);
                if (dist < ans)
                {
                    ans = dist;
                    ans_coord = i;
                }
            }
            if (points[i][1] == y)
            {
                dist = abs(points[i][0] - x);
                if (dist < ans)
                {
                    ans = dist;
                    ans_coord = i;
                }
            }
        }
        return ans_coord;
    }
};
```