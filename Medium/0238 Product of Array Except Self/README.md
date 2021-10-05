# [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)


## Description:

<p>Given an integer array <code>nums</code>, return <em>an array <code>answer</code> such that <code>answer[i]</code> is equal to the product of all the elements of <code>nums</code> except <code>nums[i]</code>.</em></p>
<p>The product of any prefix or suffix of <code>nums</code> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</p>
<p>You must write an algorithm that runs in <code>O(n)</code> time and without using the division operation.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> [24,12,8,6]
<strong>Explanation:</strong>
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [-1,1,0,-3,3]
<strong>Output:</strong> [0,0,9,0,0]
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
  <li><code>-30 &lt;= nums[i] &lt;= 30</code></li>
  <li>The product of any prefix or suffix of nums is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>To calculate the product of all elements except <code>nums[i]</code>, we can separately calculate the prefix product and suffix product of it, i.e. we only need to traverse <code>nums</code> forward and backward, and use an extra variable <code>prod</code> to keep a record of the prefix / suffix product before / after <code>nums[i]</code> for each traversal.</p>


<strong>C++</strong>

```
//  Topic   ：238. Product of Array Except Self (https://leetcode.com/problems/product-of-array-except-self/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prod = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= prod;
            prod *= nums[i];
        }
        return ans;
    }
};
```