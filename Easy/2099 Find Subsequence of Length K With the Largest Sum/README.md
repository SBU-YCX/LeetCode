# [2099. Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)


## Description:

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. You want to find a <strong>subsequence</strong> of <code>nums</code> of length <code>k</code> that has the <strong>largest</strong> sum.</p>

<p>Return <em><strong>any</strong> such subsequence as an integer array of length <code>k</code></em>.</p>

<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [2,1,3,3], k = 2
<strong>Output:</strong> [3,3]
<strong>Explanation:</strong> 
The subsequence has the largest sum of 3 + 3 = 6.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [-1,-2,3,4], k = 3
<strong>Output:</strong> [-1,3,4]
<strong>Explanation:</strong> 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [3,4,3,3], k = 2
<strong>Output:</strong> [3,4]
<strong>Explanation:</strong> 
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
  <li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


## Solution 1 :

<strong>Logical Thinking</strong>
<p>Actually, since the goal is to find a subsequence insead of a subarray, what we only care about are the largest <code>k</code> elements in <code>nums</code>. So, we just need to <strong>Sort</strong> the array with reordering their indices as well, so as to keep the relative orders of reamining elements in the answer array. Finally, just push the largest <code>k</code> elements according to their indices.</p>


<strong>C++</strong>

```
//  Topic   : 2099. Find Subsequence of Length K With the Largest Sum (https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size(), m = n - k;
        vector<int> idx;
        for (int i = 0; i < n; i++)
            idx.push_back(i);
        sort(idx.begin(), idx.end(), [&nums](int a, int b) {return nums[a] > nums[b];});
        idx.resize(k);
        sort(idx.begin(), idx.end());
        vector<int> ans;
        for (auto& i : idx)
            ans.push_back(nums[i]);
        return ans;
    }
};
```


## Solution 2 :

<strong>Logical Thinking</strong>
<p>Since we only need the largest <code>k</code> elements, we don't need to sort the whole array, instead, we just need to split the whole <code>nums</code> into two parts. By using <strong>Quick Select</strong>, we can achieve it with <code>O(N)</code> instead of sorting with <code>O(NlogN)</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2099. Find Subsequence of Length K With the Largest Sum (https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)
//  Author  : YCX
//  Time    : O(N + KlogK)
//  Space   : O(N)


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size(), m = n - k;
        vector<int> idx;
        for (int i = 0; i < n; i++)
            idx.push_back(i);
        nth_element(idx.begin(), idx.begin() + k, idx.end(), [&nums](int a, int b) {return nums[a] > nums[b];});
        idx.resize(k);
        sort(idx.begin(), idx.end());
        vector<int> ans;
        for (auto& i : idx)
            ans.push_back(nums[i]);
        return ans;
    }
};
```
