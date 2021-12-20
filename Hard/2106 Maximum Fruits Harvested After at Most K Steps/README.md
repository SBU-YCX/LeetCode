# [2106. Maximum Fruits Harvested After at Most K Steps](https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/)


## Description:

<p>Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array <code>fruits</code> where <code>fruits[i] = [position<sub>i</sub>, amount<sub>i</sub>]</code> depicts <code>amount<sub>i</sub></code> fruits at the position <code>position<sub>i</sub></code>. <code>fruits</code> is already <strong>sorted</strong> by <code>positioni</code> in <strong>ascending order</strong>, and each <code>positioni</code> is <strong>unique</strong>.</p>

<p>You are also given an integer <code>startPos</code> and an integer <code>k</code>. Initially, you are at the position <code>startPos</code>. From any position, you can either walk to the <strong>left or right</strong>. It takes <strong>one step</strong> to move <strong>one unit</strong> on the x-axis, and you can walk <strong>at most</strong> <code>k</code> steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.</p>

<p>Return <em>the <strong>maximum total number</strong> of fruits you can harvest.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/11/21/1.png)
<pre>
<strong>Input:</strong> fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
<strong>Output:</strong> 9
<strong>Explanation:</strong> 
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/11/21/2.png)
<pre>
<strong>Input:</strong> fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
<strong>Output:</strong> 14
<strong>Explanation:</strong> 
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/11/21/3.png)
<pre>
<strong>Input:</strong> fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
You can move at most k = 2 steps and cannot reach any position with fruits.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
  <li><code>fruits[i].length == 2</code></li>
  <li><code>0 &lt;= startPos, positioni &lt;= 2 * 10<sup>5</sup></code></li>
  <li><code>position<sub>i-1</sub> &lt; position<sub>i</sub> for any i &gt; 0 (<strong>0-indexed</strong>)</code></li>
  <li><code>1 &lt;= amount<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= k &lt;= 2 * 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Clearly, if we only collect fruits on left side or right side of the starting position, the optimal path is going straight forward without any turning-backs. In further, if we hope to collect fruits on both sides, we need to make at most one turning in order to obtain the maximum number of fruits with a fixed number of steps. Therefore, we can use <strong>Sliding Windows</strong> to check every possible cases. Specifically, for each <code>position<sub>i</sub></code>, we try to find the corresponding boundry on the other side, i.e. <code>position<sub>j</sub></code>, where <code>position<sub>j</sub> &lt; startPos &lt; position<sub>i</sub></code> or <code>position<sub>i</sub> &lt; startPos &lt; position<sub>j</sub></code>, such that <code>abs(startPos - position<sub>j</sub>) + 2 * abs(position<sub>i</sub> - startPos) &lt;= k</code>. In order to make it more efficient, we can do the following two things:</p>
<ul>
    <li>Use <strong>Prefix Sum</strong> to pre-calculate the number of fruits up to <code>position<sub>i</sub></code> and distance to <code>startPos</code>.</li>
    <li>Define the variable <code>j</code> outside the loop, for each new <code>i</code>, only check the possible <code>j</code> based on the previous result to avoid redundant checking. For example, we get that <code>j<sub>prev</sub></code> is the boundary for <code>i</code>, then for <code>i - 1</code>, <code>j<sub>prev</sub></code> must meet the requirement, so we only need to check those <code>j &lt; j<sub>prev</sub></code>.</li>
</ul>


<strong>C++</strong>

```
// Topic     : 2106. Maximum Fruits Harvested After at Most K Steps (https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/)
// Author    : YCX
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size(), ans = 0, p = n + 1;
        vector<vector<int>> prefix(n + 1, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            if (fruits[i][0] >= startPos)
                p = min<int>(p, i + 1);
            prefix[i + 1][1] = prefix[i][1] + fruits[i][1];
            prefix[i + 1][0] = abs(startPos - fruits[i][0]);
        }
        int j = p - 1, l = p;
        for (int i = n; i >= p; i--)
        {
            int d = prefix[i][0], r = k - 2 * d, m = 0;
            if (d > k)
                continue;
            while (j > 0 && prefix[j][0] <= r)
                j--;
            m = prefix[i][1] - prefix[j][1];
            ans = max<int>(ans, m);
        }
        for (int i = 1; i < p; i++)
        {
            int d = prefix[i][0], r = k - 2 * d, m = 0;
            if (d > k)
                continue;
            while (l <= n && prefix[l][0] <= r)
                l++;
            m = prefix[l - 1][1] - prefix[i - 1][1];
            ans = max<int>(ans, m);
        }
        return ans;
    }
};
```
