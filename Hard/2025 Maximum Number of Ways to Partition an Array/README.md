# [2025. Maximum Number of Ways to Partition an Array](https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/)


## Description:

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code>. The number of ways to <strong>partition</strong> <code>nums</code> is the number of <code>pivot</code> indices that satisfy both conditions:</p>

<ul>
    <li><code>1 &lt;= pivot &lt; n</code></li>
    <li><code>nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]</code></li>
</ul>

<p>You are also given an integer <code>k</code>. You can choose to change the value of <strong>one</strong> element of <code>nums</code> to <code>k</code>, or to leave the array <strong>unchanged</strong>.</p>

<p>Return <em>the <strong>maximum</strong> possible number of ways to <strong>partition</strong> <code>nums</code> to satisfy both conditions after changing <strong>at most</strong> one element.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [2,-1,2], k = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> One optimal approach is to change nums[0] to k. The array becomes [3,-1,2].
There is one way to partition the array:
- For pivot = 2, we have the partition [3,-1 | 2]: 3 + -1 == 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [0,0,0], k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The optimal approach is to leave the array unchanged.
There are two ways to partition the array:
- For pivot = 1, we have the partition [0 | 0,0]: 0 == 0 + 0.
- For pivot = 2, we have the partition [0,0 | 0]: 0 + 0 == 0.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14], k = -33
<strong>Output:</strong> 4
<strong>Explanation:</strong> One optimal approach is to change nums[2] to k. The array becomes [22,4,-33,-20,-15,15,-16,7,19,-10,0,-13,-14].
There are four ways to partition the array.
</pre>


## Constraints:

<ul>
    <li><code>n == nums.length</code></li>
    <li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>-10<sup>5</sup> &lt;= k, nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>According to the description, we need to find such indices that the difference between left part and right part of the array is <code>0</code>, i.e., <code>diff[pivot] = (nums[0] + nums[1] + ... + nums[pivot - 1]) - (nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]) == 0</code>. If we replace <code>nums[i]</code> with <code>k</code>, <code>diff[1]</code> to <code>diff[i]</code> decrease by <code>d</code> while <code>diff[i + 1]</code> to <code>diff[n - 1]</code> increase by <code>d</code>, where <code>d == k - nums[i]</code>. Now, if we still want to find <code>pivot</code> to make <code>diff[pivot]</code> to be <code>0</code> after replacement, we can instead find such <code>pivot</code> in the original array <code>diff</code> such that <code>diff[pivot] == d</code> when <code> 1 &lt;= pivot &lt;= i</code> or <code>diff[pivot] == -d</code> when <code>i + 1 &lt;= pivot &lt;= n - 1</code>. Since we need to count the number of such <code>pivot</code>, we can use a <strong>hash table</strong> to store the frequencies of values in <code>diff</code>.</p>


<strong>C++</strong>

```
// Topic     : 2025. Maximum Number of Ways to Partition an Array (https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2025%20Maximum%20Number%20of%20Ways%20to%20Partition%20an%20Array)
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        long m = accumulate(nums.begin(), nums.end(), 0L), l = 0, r = 0, d = 0;
        unordered_map<long, int> L, R;
        for (int i = 0; i < n - 1; i++)
        {
            l += nums[i];
            r = m - l;
            R[l - r]++;
        }
        ans = R[0];
        l = 0;
        for (int i = 0; i < n; i++)
        {
            l += nums[i];
            r = m - l;
            d = k - nums[i];
            ans = max<int>(ans, L[d] + R[-d]);
            L[l - r]++;
            R[l - r]--;
        }
        return ans;
    }
};
```
