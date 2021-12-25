# [2089. Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/)


## Description:

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and a target element <code>target</code>.</p>

<p>A <strong>target index</strong> is an index <code>i</code> such that <code>nums[i] == target</code>.</p>

<p>Return <em>a list of the target indices of <code>nums</code> after sorting <code>nums</code> in <strong>non-decreasing</strong> order.</em> If there are no target indices, return <em>an <strong>empty</strong> list</em>. The returned list must be sorted in <strong>increasing</strong> order.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,5,2,3], target = 2
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> 
After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,5,2,3], target = 3
<strong>Output:</strong> [3]
<strong>Explanation:</strong> 
After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,5,2,3], target = 5
<strong>Output:</strong> [4]
<strong>Explanation:</strong> 
After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,5,2,3], target = 4
<strong>Output:</strong> []
<strong>Explanation:</strong> 
There are no elements in nums with value 4.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 100</code></li>
  <li><code>1 &lt;= nums[i], target &lt;= 100</code></li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p>Just <strong>sort</strong> the whole array.</p>


<strong>C++</strong>

```
//  Topic   : 2089. Find Target Indices After Sorting Array (https://leetcode.com/problems/find-target-indices-after-sorting-array/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(1)


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] == target)
                ans.push_back(i);
        return ans;
    }
};
```


## Solution 2: [Improved]

<strong>Logical Thinking</strong>
<p>Actually, we don't need to sort the whole array. Instead, if there are <code>lt</code> elements smaller than <code>target</code>, the target indices should begin with <code>lt</code>. Suppose there are <code>eq</code> elements equal to <code>target</code>, the target indices should be <code>[lt, lt + eq)</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2089. Find Target Indices After Sorting Array (https://leetcode.com/problems/find-target-indices-after-sorting-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size(), lt = 0, eq = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
                eq++;
            else if (nums[i] < target)
                lt++;
        }
        for (int j = lt; j < lt + eq; j++)
            ans.push_back(j);
        return ans;
    }
};
```