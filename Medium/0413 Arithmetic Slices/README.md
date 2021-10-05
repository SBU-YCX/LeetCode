# [413. Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/)


## Description:

<p>An integer array is called arithmetic if it consists of <strong>at least three elements</strong> and if the difference between any two consecutive elements is the same.</p>
<ul>
    <li>For example, <code>[1,3,5,7,9]</code>, <code>[7,7,7,7]</code>, and <code>[3,-1,-5,-9]</code> are arithmetic sequences.</li>
</ul>
<p>Given an integer array <code>nums</code>, return the number of arithmetic <strong>subarrays</strong> of <code>nums</code>.</p>
<p>A <strong>subarray</strong> is a contiguous subsequence of the array.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 5000</code></li>
  <li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution1:

<strong>Logical Thinking</strong>
<p>We can use dynamic programming to solve this problem, for each index <code>i</code>, we count the number of arithmetic subarrays ending at <code>nums[i]</code>, i.e. if <code>nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]</code>, the number of subarrays is larger than the number of subarrays ending at <code>nums[i - 1]</code> by <code>1</code>. The final answer is the total sum of the number of arithmetic subarrays ending at each index.</p>


<strong>C++</strong>

```
//  Topic   ：413. Arithmetic Slices (https://leetcode.com/problems/arithmetic-slices/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> res(n, 0);
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                res[i] = res[i - 1] + 1;
            ans += res[i];
        }
        return ans;
    }
};
```


## Solution2: (Improved)

<strong>Logical Thinking</strong>
<p>To improve the performance, we can use a single variable instead of an array.</p>


<strong>C++</strong>

```
//  Topic   ：413. Arithmetic Slices (https://leetcode.com/problems/arithmetic-slices/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size(), len = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                len += 1;
                ans += len;
            }
            else
                len = 0;
        }
        return ans;
    }
};
```