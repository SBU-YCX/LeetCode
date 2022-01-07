# [1920. Build Array from Permutation](https://leetcode.com/problems/build-array-from-permutation/)


## Description:

<p>Given a <strong>zero-based permutation</strong> <code>nums</code> (<strong>0-indexed</strong>), build an array <code>ans</code> of the <strong>same length</strong> where <code>ans[i] = nums[nums[i]]</code> for each <code>0 &lt;= i &lt; nums.length</code> and return it.</p>

<p>A <strong>zero-based permutation</strong> <code>nums</code> is an array of <strong>distinct</strong> integers from <code>0</code> to <code>nums.length - 1</code> (<strong>inclusive</strong>).</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [0,2,1,5,3,4]
<strong>Output:</strong> [0,1,2,4,5,3]
<strong>Explanation:</strong> The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [5,0,1,2,3,4]
<strong>Output:</strong> [4,5,0,1,2,3]
<strong>Explanation:</strong> The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
    <li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
    <li>The elements in <code>nums</code> are <strong>distinct</strong>.</li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the process.</p>


<strong>C++</strong>

```
//  Topic   : 1920. Build Array from Permutation
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == i)
                ans.push_back(i);
            else
                ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};
```


## Solution 2: [Improved]

<strong>Logical Thinking</strong>
<p>We can also execute the operations directly on the original array. Since <code>0 &lt; nums[i] &lt; nums.length</code>, to make <code>nums[i]</code> keep both information of <code>nums[i]</code> and <code>nums[nums[i]]</code>, we can use <code>nums[i] = nums[i] + n * (nums[nums[i]] % n)</code>, i.e.</p>

<ul>
    <li><code>nums[i] % n</code> is the original value of <code>nums[i]</code></li>
    <li><code>nums[i] / n</code> is the value of <code>nums[nums[i]]</code></li>
</ul>


<strong>C++</strong>

```
//  Topic   : 1920. Build Array from Permutation
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums[i] += (n * (nums[nums[i]] % n));
        for (int i = 0; i < n; i++)
            nums[i] /= n;
        return nums;
    }
};
```