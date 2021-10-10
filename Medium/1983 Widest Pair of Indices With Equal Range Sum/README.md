# [1983. Widest Pair of Indices With Equal Range Sum](https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/)


## Description:

<p>You are given an integer <code>length</code> and an array <code>updates</code> where <code>updates[i] = [startIdx<sub>i</sub>, endIdx<sub>i</sub>, inc<sub>i</sub>]</code>.</p>
<p>You have an array <code>arr</code> of length <code>length</code> with all zeros, and you have some operation to apply on <code>arr</code>. In the <code>i<sup>th</sup></code> operation, you should increment all the elements <code>arr[startIdx<sub>i</sub>], arr[startIdx<sub>i</sub> + 1], ..., arr[endIdx<sub>i</sub>]</code> by <code>inc<sub>i</sub></code>.</p>
<p>Return <em><code>arr</code> after applying all the <code>updates</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex](https://assets.leetcode.com/uploads/2021/03/27/rangeadd-grid.jpg)</br>
<pre>
<strong>Input:</strong> length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
<strong>Output:</strong> [-2,0,3,5,3]
<strong>Explanation:</strong>
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
<strong>Output:</strong> [0,-4,2,2,2,4,4,-4,-4,-4]
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= length &lt;= 10<sup>5</sup></code></li>
  <li><code>0 &lt;= updates.length &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= startIdx<sub>i</sub> &lt;= endIdx<sub>i</sub> &lt; length</code></li>
  <li><code>-1000 &lt;= inc<sub>i</sub> &lt;= 1000</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>If solving this problem by Brute-Force, we need <code>O(n)</code> for each update, which leads to a <code>O(mn)</code> time complexity in total. Alternatively, we can use <strong>Prefix Sum</strong> to improve the time complexity. Specifically, we know that Prefix Sum has iterates the <code>i<sup>th</sup></code> element based on the <code>(i - 1)<sup>th</sup></code> element, i.e. if we are told that an increment is done for <code>[a, b]</code>, we only need to give an increment at <code>a</code> and all the following elements will automatically complete the increment by Prefix Sum, and then give decrement at <code>b</code> in advance such that the elements outside <code>[a, b]</code> won't be affected, a kind of like the relationship between "acceleration" and "velocity". By doing so, we can give the corresponding "acceleration" to the begin and end index for each update, which costs <code>O(m)</code>, and run Prefix Sum once to complete the update for all the element, which costs <code>O(n)</code>, then the total complexity is <code>O(m + n)</code>.</p>


<strong>C++</strong>

```
// Topic     : 1983. Widest Pair of Indices With Equal Range Sum (https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/)
// Author    : YCX
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ans = 0;
        vector<int> presum1(n + 1, 0), presum2(n + 1, 0);
        unordered_map<int, int> diff;
        diff[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            presum1[i] = presum1[i - 1] + nums1[i - 1];
            presum2[i] = presum2[i - 1] + nums2[i - 1];
            int d = presum1[i] - presum2[i];
            if (diff.count(d) == 0)
                diff[d] = i;
            else
                ans = max<int>(ans, i - diff[d]);
        }
        return ans;
    }
};
```
