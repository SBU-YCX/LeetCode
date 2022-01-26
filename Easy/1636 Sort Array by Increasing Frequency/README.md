# [1636. Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/)


## Description:

<p>Given an array of integers <code>nums</code>, sort the array in <strong>increasing</strong> order based on the frequency of the values. If multiple values have the same frequency, sort them in <strong>decreasing</strong> order.</p>

<p>Return <em>the sorted array.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,2,2,2,3]
<strong>Output:</strong> [3,1,1,2,2,2]
<strong>Explanation:</strong> '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,3,1,3,2]
<strong>Output:</strong> [1,3,3,2,2]
<strong>Explanation:</strong> '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [-1,1,-6,4,5,-6,1,4,1]
<strong>Output:</strong> [5,-1,4,4,-6,-6,1,1,1]
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 100</code></li>
    <li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Sort</strong> the array, traverse it from right to left, count the frequency of each value and use it as a key to build a <strong>hash table</strong>. After the traversal, all the values are stored in the hash table by their frequencies, and for each frequency, the values are in decresing order.</p>


<strong>C++</strong>

```
//  Topic   : 1636. Sort Array by Increasing Frequency
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, vector<int>> freq;
        sort(nums.begin(), nums.end());
        int m = nums.size() - 1; 
        for (int i = m - 1; i >= 0; i--)
            if (nums[i] != nums[i + 1])
            {
                int f = m - i;
                freq[f].push_back(nums[i + 1]);
                m = i;
            }
        freq[m + 1].push_back(nums[0]);
        vector<int> ans;
        map<int, vector<int>>::iterator iter = freq.begin();
        while (iter != freq.end())
        {
            for (int j = 0; j < iter->second.size(); j++)
                for (int k = 0; k < iter->first; k++)
                    ans.push_back(iter->second[j]);
            iter++;
        }
        return ans;
    }
};
```