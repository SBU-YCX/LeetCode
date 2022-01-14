# [1822. Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/)


## Description:

<p>There is a function <code>signFunc(x)</code> that returns:</p>

<ul>
    <li><code>1</code> if <code>x</code> is positive.</li>
    <li><code>-1</code> if <code>x</code> is negative.</li>
    <li><code>0</code> if <code>x</code> is equal to <code>0</code>.</li>
</ul>

<p>You are given an integer array <code>nums</code>. Let <code>product</code> be the product of all values in the array <code>nums</code>.</p>

<p>Return <em><code>signFunc(product)</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [-1,-2,-3,-4,3,2,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The product of all values in the array is 144, and signFunc(144) = 1
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,5,0,2,-3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The product of all values in the array is 0, and signFunc(0) = 0
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [-1,1,-1,1,-1]
<strong>Output:</strong> -1
<strong>Explanation:</strong> The product of all values in the array is -1, and signFunc(-1) = -1
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
    <li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>If there is a <code>0</code>, the product must be <code>0</code>. If there are <strong>odd</strong> number of negative elements, the product must be negative; otherwise, the product will be positive if there are <strong>even</strong> number of negative elements. So we need to <strong>count</strong> the number of negative elements in <code>nums</code> and see whether it is odd.</p>


<strong>C++</strong>

```
//  Topic   : 1822. Sign of the Product of an Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int arraySign(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                return 0;
            else if (nums[i] < 0)
                num += 1;
        }
        if (num % 2 == 0)
            return 1;
        else
            return -1;
    }
};
```