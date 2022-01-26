# [1608. Special Array With X Elements Greater Than or Equal X](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/)


## Description:

<p>You are given an array <code>nums</code> of non-negative integers. <code>nums</code> is considered <strong>special</strong> if there exists a number <code>x</code> such that there are <strong>exactly</strong> <code>x</code> numbers in <code>nums</code> that are <strong>greater than or equal to</strong> <code>x</code>.</p>

<p>Notice that <code>x</code> <strong>does not</strong> have to be an element in <code>nums</code>.</p>

<p>Return <em><code>x</code> if the array is <strong>special</strong>, otherwise, return <code>-1</code>.</em> It can be proven that if <code>nums</code> is special, the value for <code>x</code> is <strong>unique</strong>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [3,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 values (3 and 5) that are greater than or equal to 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [0,0]
<strong>Output:</strong> -1
<strong>Explanation:</strong> No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [0,4,3,0,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 values that are greater than or equal to 3.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 100</code></li>
    <li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p><strong>Sort</strong> the array and check each index.</p>


<strong>C++</strong>

```
//  Topic   : 1608. Special Array With X Elements Greater Than or Equal X
//  Author  : YCX
//  Time    : O(NlogN + N)
//  Space   : O(logN)


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        if (nums[0] >= m)
            return m;
        if (nums[m - 1] < 0)
            return 0;
        for (int i = 1; i < m - 1; i++)
            if (nums[m - i] >= i && nums[m - i - 1] < i)
                return i;
        return -1;
    }
};
```


## Solution 2: [Improved]

<strong>Logical Thinking</strong>
<p>Use <strong>binary search</strong> to find the index.</p>


<strong>C++</strong>

```
//  Topic   : 1608. Special Array With X Elements Greater Than or Equal X
//  Author  : YCX
//  Time    : O(NlogN + logN)
//  Space   : O(logN)


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 1, n = nums.size(), r = n - 1;
        if (nums[0] >= n)
            return n;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[n - m] >= m && nums[n - m - 1] < m)
                return m;
            else if (nums[n - m - 1] >= m)
                l = m + 1;
            else 
                r = m - 1;
        }
        return -1;
    }
};
```