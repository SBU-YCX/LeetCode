# [2104. Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)


## Description:

<p>You are given an integer array<code>nums</code>. The <strong>range</strong> of a subarray of <code>nums</code> is the difference between the largest and smallest element in the subarray.</p>

<p>Return <em>the <strong>sum of all</strong> subarray ranges of <code>nums</code>.</em></p>

<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,3,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [4,-2,-3,4,1]
<strong>Output:</strong> 59
<strong>Explanation:</strong> 
The sum of all subarray ranges of nums is 59.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
  <li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution :

<strong>Logical Thinking</strong>
<p>We can spllit the problem into two parts, the difference between sum of all maximums and sum of all minimums. For each subproblem, we can use <strong>Monotonic Stack</strong> twice (forward and backword) to find the interval that the value is a optimum (minimum or maximum), and in turn to find the number of subarrays within this interval.</p>


<strong>C++</strong>

```
//  Topic   : 2104. Sum of Subarray Ranges (https://leetcode.com/problems/sum-of-subarray-ranges/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long maxsum = 0, minsum = 0;
        vector<int> maxr(n, n), minr(n, n);
        stack<int> maxs, mins;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!maxs.empty() && nums[maxs.top()] < nums[i])
                maxs.pop();
            while (!mins.empty() && nums[mins.top()] > nums[i])
                mins.pop();
            if (maxs.empty())
                maxr[i] = n - i;
            else
                maxr[i] = maxs.top() - i;
            if (mins.empty())
                minr[i] = n - i;
            else
                minr[i] = mins.top() - i;
            maxs.push(i);
            mins.push(i);
        }
        while (!maxs.empty())
            maxs.pop();
        while (!mins.empty())
            mins.pop();
        for (int i = 0; i < n; i++)
        {
            while (!maxs.empty() && nums[maxs.top()] <= nums[i])
                maxs.pop();
            while (!mins.empty() && nums[mins.top()] >= nums[i])
                mins.pop();
            if (maxs.empty())
                maxsum += (long long)nums[i] * (maxr[i] * (i + 1));
            else
                maxsum += (long long)nums[i] * (maxr[i] * (i - maxs.top()));
            if (mins.empty())
                minsum += (long long)nums[i] * (minr[i] * (i + 1));
            else
                minsum += (long long)nums[i] * (minr[i] * (i - mins.top()));
            maxs.push(i);
            mins.push(i);
        }
        return (maxsum - minsum);
    }
};
```