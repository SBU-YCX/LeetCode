# [1909. Remove One Element to Make the Array Strictly Increasing](https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/)


## Description:

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, return <em><code>true</code> if it can be made <strong>strictly increasing</strong> after removing <strong>exactly one</strong> element, or <code>false</code> otherwise. If the array is already strictly increasing, return <code>true</code>.</em></p>

<p>The array <code>nums</code> is <strong>strictly increasing</strong> if <code>nums[i - 1] &lt; nums[i]</code> for each index (<code>1 &lt;= i &lt; nums.length</code>).</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,10,5,7]
<strong>Output:</strong> true
<strong>Explanation:</strong> 
By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,3,1,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> 
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> false
<strong>Explanation:</strong> 
The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= nums.length &lt;= 1000</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p>Firstly, we can separate the whole array into several strictly increasing groups, according to the group number:</p>

<ul>
    <li>If there are only <code>1</code> group, the original array is already strictly increasing</li>
    <li>If there are more than <code>3</code> groups, we cannot make the whole array increasing by removing only one element</li>
    <li>If there are <code>2</code> groups, we have two options: removing the last element of the first group or removing the first element of the second group, check each of them</li> 
</ul>


<strong>C++</strong>

```
//  Topic   : 1909. Remove One Element to Make the Array Strictly Increasing
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> groups;
        groups.push_back({nums[0]});
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                groups[groups.size() - 1].push_back(nums[i]);
            else
                groups.push_back({nums[i]});
        }
        if (groups.size() > 2)
            return false;
        else if (groups.size() == 1)
            return true;
        else
        {
            int a = groups[0].size(), b = groups[1].size();
            if (a == 1 || b == 1)
                return true;
            else
            {
                if (groups[0][a - 2] < groups[1][0] || groups[0][a - 1] < groups[1][1])
                    return true;
                else
                    return false;
            }
        }
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