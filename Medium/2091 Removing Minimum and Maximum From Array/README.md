# [2091. Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)


## Description:

<p>You are given a <strong>0-indexed</strong> array of <strong>distinct</strong> integers <code>nums</code>.</p>

<p>There is an element in <code>nums</code> that has the <strong>lowest</strong> value and an element that has the <strong>highest</strong> value. We call them the <strong>minimum</strong> and <strong>maximum</strong> respectively. Your goal is to remove <strong>both</strong> these elements from the array.

<p>A <strong>deletion</strong> is defined as either removing an element from the <strong>front</strong> of the array or removing an element from the <strong>back</strong> of the array.

<p>Return <em>the <strong>minimum</strong> number of deletions it would take to remove <strong>both</strong> the minimum and maximum element from the array.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [2,<strong>10</strong>,7,5,4,<strong>1</strong>,8,6]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [0,<strong>-4</strong>,<strong>19</strong>,1,8,-2,-3,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
The minimum element in the array is nums[1], which is -4.
The maximum element in the array is nums[2], which is 19.
We can remove both the minimum and maximum by removing 3 elements from the front.
This results in only 3 deletions, which is the minimum number possible.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [<strong>101</strong>]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
There is only one element in the array, which makes it both the minimum and maximum element.
We can remove it with 1 deletion.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
    <li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
    <li>The integers in nums are <strong>distinct</strong>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can find the indices <code>minidx</code> and <code>maxidx</code> of minimum and maximum by <code>minmax_element()</code>, suppose <code>minidx &lt; maxidx</code>, there are only three cases: </p>

<ul>
    <li>Remove all elements from the front, the number of deletions is <code>maxidx + 1</code>;</li>
    <li>Remove all elements from the back, the number of deletions is <code>n - minidx</code>;</li>
    <li>Remove all elements from both sides, the number of deletions is <code>(minidx + 1) + (n - maxidx)</code>;</li>
</ul>

<p>The answer is the minmum number among the above three.</p>


<strong>C++</strong>

```
//  Topic   : 2091. Removing Minimum and Maximum From Array (https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto [miniter, maxiter] = minmax_element(nums.begin(), nums.end());
        int minidx = miniter - nums.begin();
        int maxidx = maxiter - nums.begin();
        int n = nums.size();
        if (minidx > maxidx)
            swap(minidx, maxidx);
        int ans = min<int>(minidx + 1 + n - maxidx, min<int>(maxidx + 1, n - minidx));
        return ans;
    }
};
```