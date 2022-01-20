# [1752. Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)


## Description:

<p>Given an array <code>nums</code>, return <em><code>true</code> if the array was originally sorted in non-decreasing order, then rotated <strong>some</strong> number of positions (including zero). Otherwise, return <code>false</code>.</em></p>

<p>There may be <strong>duplicates</strong> in the original array.</p>

<p><strong>Note:</strong> An array <code>A</code> rotated by <code>x</code> positions results in an array <code>B</code> of the same length such that <code>A[i] == B[(i+x) % A.length]</code>, where <code>%</code> is the modulo operation.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [3,4,5,1,2]
<strong>Output:</strong> true
<strong>Explanation:</strong> [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,1,3,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no sorted array once rotated that can make nums.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> true
<strong>Explanation:</strong> [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 100</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Compare all the adjacent pairs <code>nums[i - 1]</code> and <code>nums[i]</code>, where <code>nums[i] < nums[i - 1]</code> can appear at most once. Don't forget to compare <code>nums[0]</code> and <code>nums[nums.size() - 1]</code> since they may be adjacent in the original non-decreasing array.</p>


<strong>C++</strong>

```
//  Topic   : 1752. Check if Array Is Sorted and Rotated
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool check(vector<int>& nums) {
        bool end = false;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1])
            {
                if (end)
                    return false;
                end = true;
            }
        if (end && nums[nums.size() - 1] > nums[0])
            return false;
        return true;
    }
};
```