# [2021. Brightest Position on Street](https://leetcode.com/problems/brightest-position-on-street/)


## Description:

<p>A perfectly straight street is represented by a number line. The street has street lamp(s) on it and is represented by a 2D integer array <code>lights</code>. Each <code>lights[i] = [position<sub>i</sub>, range<sub>i</sub>]</code> indicates that there is a street lamp at position <code>position<sub>i</sub></code> that lights up the area from <code>[position<sub>i</sub> - range<sub>i</sub>, position<sub>i</sub> + range<sub>i</sub>]</code> (<strong>inclusive</strong>).</p>

<p>The <strong>brightness</strong> of a position <code>p</code> is defined as the number of street lamp that light up the position <code>p</code>.</p>

<p>Given <code>lights</code>, return <em>the <strong>brightest</strong> position on the street. If there are multiple brightest positions, return the <strong>smallest</strong> one.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/09/28/image-20210928155140-1.png)
<pre>
<strong>Input:</strong> lights = [[-3,2],[1,2],[3,3]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
The first street lamp lights up the area from [(-3) - 2, (-3) + 2] = [-5, -1].
The second street lamp lights up the area from [1 - 2, 1 + 2] = [-1, 3].
The third street lamp lights up the area from [3 - 3, 3 + 3] = [0, 6].

Position -1 has a brightness of 2, illuminated by the first and second street light.
Positions 0, 1, 2, and 3 have a brightness of 2, illuminated by the second and third street light.
Out of all these positions, -1 is the smallest, so return it.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> lights = [[1,0],[0,1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
The first street lamp lights up the area from [1 - 0, 1 + 0] = [1, 1].
The second street lamp lights up the area from [0 - 1, 0 + 1] = [-1, 1].

Position 1 has a brightness of 2, illuminated by the first and second street light.
Return 1 because it is the brightest position on the street.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> lights = [[1,2]]
<strong>Output:</strong> -1
<strong>Explanation:</strong>
The first street lamp lights up the area from [1 - 2, 1 + 2] = [-1, 3].

Positions -1, 0, 1, 2, and 3 have a brightness of 1, illuminated by the first street light.
Out of all these positions, -1 is the smallest, so return it.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= lights.length &lt;= 10<sup>5</sup></code></li>
    <li><code>lights[i].length == 2</code></li>
    <li><code>-10<sup>8</sup> &lt;= position<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
    <li><code>0 &lt;= range<sub>i</sub> &lt;= 10<sup>8</sup></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Go through the whole array, make each <code>lights[i] = [position<sub>i</sub> - range<sub>i</sub>, position<sub>i</sub> + range<sub>i</sub>]</code>, and find the total interval <code>[min(position<sub>i</sub> - range<sub>i</sub>), max(position<sub>i</sub> + range<sub>i</sub>)]</code> with brightness. <strong>Sort</strong> the array according to their left boundaries. Then, greedly check each position <code>t</code>, using a <strong>heap</strong> sorted by each light's right boundary. Specifically, for each <code>t</code>, pop out all the lights with <code>position<sub>i</sub> + range<sub>i</sub> &lt; t</code>, then push all the lights <code>position<sub>i</sub> - range<sub>i</sub> == t</code> into the heap, then the size of heap is the brightness of current <code>t</code>.</p>


<strong>C++</strong>

```
//  Topic   ：2021. Brightest Position on Street (https://leetcode.com/problems/brightest-position-on-street/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        int n = lights.size(), s = 0, t = 0, k = INT_MIN, ans = 0, bright = 0;
        for (int i = 0; i < n; i++)
        {
            s = lights[i][0] - lights[i][1];
            t = lights[i][0] + lights[i][1];
            lights[i][0] = s;
            lights[i][1] = t;
            k = max<int>(k, t);
            ans = min<int>(ans, s);
        }
        sort(lights.begin(), lights.end());
        s = 0, t = ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (; t <= k;)
        {
            t = lights[s][0];
            while (!pq.empty() && pq.top() < t)
                pq.pop();
            while (s < n && lights[s][0] == t)
            {
                pq.push(lights[s][1]);
                s++;
            }
            int m = pq.size();
            if (m > bright)
            {
                bright = m;
                ans = t;
            }
            if (s == n)
                break;
        }
        return ans;
    }
};
```