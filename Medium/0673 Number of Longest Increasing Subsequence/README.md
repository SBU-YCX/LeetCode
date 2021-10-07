# [673. Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)


## Description:

<p>Given an integer array <code>nums</code>, return <em>the number of longest increasing subsequences.</em></p>
<p><strong>Notice</strong> that the sequence has to be <strong>strictly</strong> increasing.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,3,5,4,7]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,2,2,2,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 2000</code></li>
  <li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>It is a typical <strong>Dynamic Programming</strong> problem. For each <code>nums[i]</code>, make <code>ans[i] = max(ans[j] + 1)</code> for all <code>j &lt; i && nums[j] < nums[i]</code>, and count all the ways to make <code>ans[j] + 1 == ans[i]</code>, which is stored in another array.</p>


<strong>C++</strong>

```
// Topic     : 673. Number of Longest Increasing Subsequence (https://leetcode.com/problems/number-of-longest-increasing-subsequence/)
// Author    : YCX
// Time      : O(N ^ 2)
// Space     : O(N)


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<vector<int>> ans(n, vector<int>(2, 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
                if (nums[j] < nums[i])
                {
                    if (ans[j][0] + 1 > ans[i][0])
                    {
                        ans[i][0] = ans[j][0] + 1;
                        ans[i][1] = ans[j][1];
                    }
                    else if (ans[j][0] + 1 == ans[i][0])
                        ans[i][1] += ans[j][1];
                }
            res = max<int>(res, ans[i][0]);
        }
        int ans_n = 0;
        for (int i = 0; i < n; i++)
            if (ans[i][0] == res)
                ans_n += ans[i][1];
        return ans_n;
    }
};
```
