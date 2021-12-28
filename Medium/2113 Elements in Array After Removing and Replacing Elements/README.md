# [2113. Elements in Array After Removing and Replacing Elements](https://leetcode.com/problems/elements-in-array-after-removing-and-replacing-elements/)


## Description:

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. Initially on minute <code>0</code>, the array is unchanged. Every minute, the <strong>leftmost</strong> element in <code>nums</code> is removed until no elements remain. Then, every minute, one element is appended to the <strong>end</strong> of <code>nums</code>, in the order they were removed in, until the original array is restored. This process repeats indefinitely.</p>

<ul>
    <li>For example, the array <code>[0,1,2]</code> would change as follows: <code>[0,1,2] → [1,2] → [2] → [] → [0] → [0,1] → [0,1,2] → [1,2] → [2] → [] → [0] → [0,1] → [0,1,2] → ...</code></li>
</p>

<p>You are also given a 2D integer array <code>queries</code> of size <code>n</code> where <code>queries[j] = [time<sub>j</sub>, index<sub>j</sub>]</code>. The answer to the <code>j<sup>th</sup></code> query is:</p>

<ul>
    <li><code>nums[index<sub>j</sub>]</code> if <code>index<sub>j</sub> &lt; nums.length</code> at minute <code>time<sub>j</sub></code></li>
    <li><code>-1</code> if <code>index<sub>j</sub> &gt;= nums.length</code> at minute <code>time<sub>j</sub></code></li>
</ul>

<p>Return an integer array ans of size n where ans[j] is the answer to the jth query.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [0,1,2], queries = [[0,2],[2,0],[3,2],[5,0]]
<strong>Output:</strong> [2,2,-1,0]
<strong>Explanation:</strong> 
Minute 0: [0,1,2] - All elements are in the nums.
Minute 1: [1,2]   - The leftmost element, 0, is removed.
Minute 2: [2]     - The leftmost element, 1, is removed.
Minute 3: []      - The leftmost element, 2, is removed.
Minute 4: [0]     - 0 is added to the end of nums.
Minute 5: [0,1]   - 1 is added to the end of nums.

At minute 0, nums[2] is 2.
At minute 2, nums[0] is 2.
At minute 3, nums[2] does not exist.
At minute 5, nums[0] is 0.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2], queries = [[0,0],[1,0],[2,0],[3,0]]
<strong>Output:</strong> [2,-1,2,-1]
<strong>Explanation:</strong> 
Minute 0: [2] - All elements are in the nums.
Minute 1: []  - The leftmost element, 2, is removed.
Minute 2: [2] - 2 is added to the end of nums.
Minute 3: []  - The leftmost element, 2, is removed.

At minute 0, nums[0] is 2.
At minute 1, nums[0] does not exist.
At minute 2, nums[0] is 2.
At minute 3, nums[0] does not exist.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 100</code></li>
    <li><code>0 &lt;= nums[i] &lt;= 100</code></li>
    <li><code>n == queries.length</code></li>
    <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>queries[j].length == 2</code></li>
    <li><code>0 &lt;= time<sub>j</sub> &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= index<sub>j</sub> &lt; nums.length</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>By observation, we notice that the pattern of the array <code>nums</code> is repeated every <code>2 * n</code> minutes. Within a period, <code>nums</code> will be empty at time <code>n</code>, so: </p>

<ul>
    <li>During the first half, every minute the elements will move left by <code>1</code>, so the corresponding index of the answer is <code>queries[i][1] + queries[i][0]</code>.</li>
    <li>During the second half, if only <code>queries[i][1] &lt;= queries[i][0] - (n + 1)</code>, we can obtain the integer <code>nums[queries[i][1]]</code>.</li>
</ul>


<strong>C++</strong>

```
//  Topic   ：2113. Elements in Array After Removing and Replacing Elements (https://leetcode.com/problems/elements-in-array-after-removing-and-replacing-elements/)
//  Author  : YCX
//  Time    : O(M)
//  Space   : O(1)


class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int t = queries[i][0] % (2 * n);
            if (t <= n)
            {
                int j = queries[i][1] + t;
                if (j >= n)
                    ans.push_back(-1);
                else
                    ans.push_back(nums[j]);
            }
            else
            {
                int j = queries[i][1], k = t - n - 1;
                if (j > k)
                    ans.push_back(-1);
                else
                    ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};
```
