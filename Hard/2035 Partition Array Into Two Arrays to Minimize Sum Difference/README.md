# [2035. Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)


## Description:

<p>You are given an integer array <code>nums</code> of <code>2 * n</code> integers. You need to partition <code>nums</code> into <strong>two</strong> arrays of length <code>n</code> to <strong>minimize the absolute difference</strong> of the <strong>sums</strong> of the arrays. To partition <code>nums</code>, put each element of <code>nums</code> into <strong>one</strong> of the two arrays.</p>

<p>Return <em>the <strong>minimum</strong> possible absolute difference.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/02/ex1.png)
<pre>
<strong>Input:</strong> nums = [3,9,7,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [-36,36]
<strong>Output:</strong> 72
<strong>Explanation:</strong> One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
</pre>

<strong>Example 3:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/02/ex3.png)
<pre>
<strong>Input:</strong> nums = [2,-1,0,4,-2,-9]
<strong>Output:</strong> 0
<strong>Explanation:</strong> One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= n &lt;= 15</code></li>
    <li><code>nums.length == 2 * n</code></li>
    <li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>This problem asks us to pick <code>n</code> elements from <code>2 * n</code> elements, if we do this with brute-force, we will get TLE. Instead, we can reduce the search space, specifically, we divide the whole array <code>nums</code> into two parts <code>l</code> and <code>r</code>. Then, if we choose <code>k</code> elements in <code>l</code> (using <code>d1</code> to store the difference, if <code>i<sup>th</sup></code> element is chosen, <code>d1 += l[i]</code>, else, <code>d1 -= l[i]</code>), we need <code>n - k</code> ones in <code>r</code> (similar using <code>d2</code>) to make the absolute difference as close to <code>0</code> as possible. The searching process in <code>r</code> can be done with <strong>binary search</strong> as we store the all possible differences in a <strong>hash table</strong> according to the number of chosen elements.</p>


<strong>C++</strong>

```
// Topic     : 2035. Partition Array Into Two Arrays to Minimize Sum Difference (https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2030%20Smallest%20K-Length%20Subsequence%20With%20Occurrences%20of%20a%20Letter)
// Time      : O(2^Nlog(2^N))
// Space     : O(2^N)


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        vector<int> l(nums.begin(), nums.begin() + m), r(nums.begin() + m, nums.end());
        vector<vector<int>> val(m + 1);
        for (int i = 0; i < (1 << m); i++)
        {
            int d = 0, k = __builtin_popcount(i);
            for (int j = 0; j < m; j++)
                d += (i & (1 << j)) ? l[j] : -l[j];
            val[k].push_back(d);
        }
        for (auto& v : val)
            sort(v.begin(), v.end());
        int ans = INT_MAX;
        for (int i = 0; i < (1 << m); i++)
        {
            int d = 0, k = m - __builtin_popcount(i);
            for (int j = 0; j < m; j++)
                d += (i & (1 << j)) ? r[j] : -r[j];
            auto iter = lower_bound(val[k].begin(), val[k].end(), -d);
            if (iter != val[k].begin())
                ans = min<int>(ans, abs(d + *prev(iter)));
            if (iter != val[k].end())
                ans = min<int>(ans, abs(d + *iter));
        }
        return ans;
    }
};
```
