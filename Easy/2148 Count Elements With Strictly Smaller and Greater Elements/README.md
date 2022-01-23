# [2148. Count Elements With Strictly Smaller and Greater Elements](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/)


## Description:

<p>Given an integer array <code>nums</code>, return <em>the number of elements that have <strong>both</strong> a strictly smaller and a strictly greater element appear in <code>nums</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [11,7,2,15]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [-3,3,3,90]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 100</code></li>
    <li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p><strong>Sort</strong> the array, move a pointer <code>i</code> from left to right until <code>nums[i]</code> is not the minimum value, move another pointer <code>j</code> from right to left until <code>nums[j]</code> is not the maximum value. Then the answer is the number of elements between <code>i</code> and <code>j</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2148. Count Elements With Strictly Smaller and Greater Elements
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(logN)


class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && nums[i] == nums[0])
            i++;
        while (j >= 0 && nums[j] == nums[n - 1])
            j--;
        return max<int>(0, j - i + 1);
    }
};
```


## Solution 2: [Improved]

<strong>Logical Thinking</strong>
<p>Actually, there is no need to sort the array, we only need to find the minimum value and the maximum value in <code>O(N)</code> time.</p>


<strong>C++</strong>

```
//  Topic   : 2148. Count Elements With Strictly Smaller and Greater Elements
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countElements(vector<int>& nums) {
        auto [minv, maxv] = minmax_element(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] < *maxv && nums[i] > *minv)
                ans++;
        return ans;
    }
};
```
