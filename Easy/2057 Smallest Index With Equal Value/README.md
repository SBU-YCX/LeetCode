# [2057. Smallest Index With Equal Value](https://leetcode.com/problems/smallest-index-with-equal-value/)


## Description:

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, return <em>the <strong>smallest</strong> index <code>i</code> of <code>nums</code> such that <code>i mod 10 == nums[i]</code>, or <code>-1</code> if such index does not exist.</em></p>
<p><code>x mod y</code> denotes the <strong>remainder</strong> when <code>x</code> is divided by <code>y</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [0,1,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
i=0: 0 mod 10 = 0 == nums[0].
i=1: 1 mod 10 = 1 == nums[1].
i=2: 2 mod 10 = 2 == nums[2].
All indices have i mod 10 == nums[i], so we return the smallest index 0.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [4,3,2,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
i=0: 0 mod 10 = 0 != nums[0].
i=1: 1 mod 10 = 1 != nums[1].
i=2: 2 mod 10 = 2 == nums[2].
i=3: 3 mod 10 = 3 != nums[3].
2 is the only index which has i mod 10 == nums[i].
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3,4,5,6,7,8,9,0]
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
No index satisfies i mod 10 == nums[i].
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> nums = [2,1,3,5,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
1 is the only index with i mod 10 == nums[i].
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 100</code></li>
  <li><code>0 &lt;= nums[i] &lt;= 9</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Just go through the whole array <code>nums</code> and check each element.</p>


<strong>C++</strong>

```
//  Topic   : 2057. Smallest Index With Equal Value (https://leetcode.com/problems/smallest-index-with-equal-value/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (i % 10 == nums[i])
                return i;
        return -1;
    }
};
```
