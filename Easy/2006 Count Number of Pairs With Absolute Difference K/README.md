# [2006. Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/)


## Description:

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of pairs <code>(i, j)</code> where <code>i &lt; j</code> such that <code>|nums[i] - nums[j]| == k</code>.</em></p>

<p>The value of <code>|x|</code> is defined as:</p>

<ul>
    <li><code>x</code> if <code>x &gt;= 0</code>.</li>
    <li><code>-x</code> if <code>x &lt; 0</code>.</li>
</ul>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,2,1], k = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,3], k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no pairs with an absolute difference of 3.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [3,2,1,5,4], k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 200</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 100</code></li>
    <li><code>1 &lt;= k &lt;= 99</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using a <code>hash table</code> to store the frequencies of values which has occured before <code>i<sup>th</sup></code> element, for each element <code>nums[i]</code>, we only need to count the number of values <code>nums[i] - k</code> and <code>nums[i] + k</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2006. Count Number of Pairs With Absolute Difference K
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> f;
        for (int i = 0; i < n; i++)
        {
            ans += (f[nums[i] - k] + f[nums[i] + k]);
            f[nums[i]]++;
        }
        return ans;
    }
};
```
