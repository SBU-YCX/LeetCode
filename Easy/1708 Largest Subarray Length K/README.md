# [1708. Largest Subarray Length K](https://leetcode.com/problems/largest-subarray-length-k/)


## Description:

<p>An array <code>A</code> is larger than some array <code>B</code> if for the first index <code>i</code> where <code>A[i] != B[i]</code>, <code>A[i] &gt; B[i]</code>.</p>

<p>For example, consider <code>0</code>-indexing:</p>

<ul>
    <li><code>[1,3,2,4] &gt; [1,2,2,4]</code>, since at index <code>1</code>, <code>3 &gt; 2</code>.</li>
    <li><code>[1,4,4,4] &lt; [2,1,1,1]</code>, since at index <code>0</code>, <code>1 &lt; 2</code>.</li>
</ul>

<p>A subarray is a contiguous subsequence of the array.</p>

<p>Given an integer array <code>nums</code> of <strong>distinct</strong> integers, return <em>the <strong>largest</strong> subarray of <code>nums</code> of length <code>k</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,4,5,2,3], k = 3
<strong>Output:</strong> [5,2,3]
<strong>Explanation:</strong> The subarrays of size 3 are: [1,4,5], [4,5,2], and [5,2,3].
Of these, [5,2,3] is the largest.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,4,5,2,3], k = 4
<strong>Output:</strong> [4,5,2,3]
<strong>Explanation:</strong> The subarrays of size 4 are: [1,4,5,2], and [4,5,2,3].
Of these, [4,5,2,3] is the largest.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,4,5,2,3], k = 1
<strong>Output:</strong> [5]
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
    <li>All the integers of <code>nums</code> are <strong>unique</strong>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since all the elements are unique, we only need to find the maximum value and its index between <code>[0, n - k]</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1708. Largest Subarray Length K
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        auto i = max_element(nums.begin(), nums.end() - k + 1);
        return vector<int>(i, i + k);
    }
};
```