# [1748. Sum of Unique Elements](https://leetcode.com/problems/sum-of-unique-elements/)


## Description:

<p>You are given an integer array <code>nums</code>. The unique elements of an array are the elements that appear <strong>exactly once</strong> in the array.</p>

<p>Return <em>the <strong>sum</strong> of all the unique elements of <code>nums</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The unique elements are [1,3], and the sum is 4.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,1,1,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no unique elements, and the sum is 0.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 15
<strong>Explanation:</strong> The unique elements are [1,2,3,4,5], and the sum is 15.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 100</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a <strong>hash table</strong> to count the frequency of each value.</p>


<strong>C++</strong>

```
//  Topic   : 1748. Sum of Unique Elements
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto& i : nums)
            freq[i]++;
        int ans = 0;
        for (auto& p : freq)
            if (p.second == 1)
                ans += p.first;
        return ans;
    }
};
```