# [2044. Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)


## Description:

<p>Given an integer array <code>nums</code>, find the <strong>maximum</strong> possible <strong>bitwise OR</strong> of a subset of <code>nums</code> and return the <strong>number of different non-empty subsets</strong> with the maximum bitwise OR.</p>
<p>An array <code>a</code> is a <strong>subset</strong> of an array <code>b</code> if <code>a</code> can be obtained from <code>b</code> by deleting some (possibly zero) elements of <code>b</code>. Two subsets are considered <strong>different</strong> if the indices of the elements chosen are different.</p>
<p>The bitwise OR of an array <code>a</code> is equal to <code>a[0] OR a[1] OR ... OR a[a.length - 1]</code> (<strong>0-indexed</strong>).</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,2,2]
<strong>Output:</strong> 7
<strong>Explanation:</strong> All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [3,2,1,5]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 16</code></li>
  <li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>The maximum bitwise-or result is the bitwise-or of the whole array since it guarantees the corresponding bit is set to be <code>1</code> only if any element has <code>1</code> on that bit. So we can use a <strong>hash table</strong> to keep track of the number for bitwise-or of each subset.</p>

 
<strong>C++</strong>

```
//  Topic   ：2044. Count Number of Maximum Bitwise-OR Subsets (https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)
//  Author  : YCX
//  Time    : O(M * N) [M is the maximum bitwise-or result]
//  Space   : O(M)


class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxv = 0;
        for (auto i : nums)
            maxv |= i;
        unordered_map<int, int> ways;
        ways[0] = 1;
        for (auto i : nums)
        {
            unordered_map<int, int> subways;
            for (auto j : ways)
                subways[j.first | i] += j.second;
            for (auto j : subways)
                ways[j.first] += j.second;
        }
        return ways[maxv];
    }
};
```
