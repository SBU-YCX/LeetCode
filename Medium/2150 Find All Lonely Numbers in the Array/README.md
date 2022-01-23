# [2150. Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/)


## Description:

<p>You are given an integer array <code>nums</code>. A number <code>x</code> is <strong>lonely</strong> when it appears only <strong>once</strong>, and no <strong>adjacent</strong> numbers (i.e. <code>x + 1</code> and <code>x - 1</code>) appear in the array.</p>

<p>Return <em><strong>all</strong> lonely numbers in <code>nums</code>.</em> You may return the answer in <strong>any order</strong>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [10,6,5,8]
<strong>Output:</strong> [10,8]
<strong>Explanation:</strong>
- 10 is a lonely number since it appears exactly once and 9 and 11 does not appear in nums.
- 8 is a lonely number since it appears exactly once and 7 and 9 does not appear in nums.
- 5 is not a lonely number since 6 appears in nums and vice versa.
Hence, the lonely numbers in nums are [10, 8].
Note that [8, 10] may also be returned.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,3,5,3]
<strong>Output:</strong> [1,5]
<strong>Explanation:</strong> 
- 1 is a lonely number since it appears exactly once and 0 and 2 does not appear in nums.
- 5 is a lonely number since it appears exactly once and 4 and 6 does not appear in nums.
- 3 is not a lonely number since it appears twice.
Hence, the lonely numbers in nums are [1, 5].
Note that [5, 1] may also be returned.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Sort</strong> the array, find all such <code>nums[i]</code> that</p>

<ul>
    <li><code>nums[i] != nums[i - 1] && nums[i] != nums[i - 1] + 1</code></li>
    <li><code>nums[i] != nums[i + 1] && nums[i] != nums[i + 1] - 1</code></li>
</ul>


<strong>C++</strong>

```
//  Topic   : 2150. Find All Lonely Numbers in the Array
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && (nums[i] == nums[i - 1] || nums[i] == nums[i - 1] + 1))
                continue;
            if (i < n - 1 && (nums[i] == nums[i + 1] || nums[i] == nums[i + 1] - 1))
                continue;
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
```