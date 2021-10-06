# [442. Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)


## Description:

<p>Given an integer array <code>nums</code> of length <code>n</code> where all the integers of nums are in the range <code>[1, n]</code> and each integer appears <strong>once</strong> or <strong>twice</strong>, return <em>an array of all the integers that appears <strong>twice</strong>.</em></p>
<p>You must write an algorithm that runs in <code>O(n)</code> time and uses only constant extra space.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [4,3,2,7,8,2,3,1]
<strong>Output:</strong> [2,3]
<strong>Explanation:</strong> 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,2]
<strong>Output:</strong> [1]
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> []
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>n == nums.length</code></li>
  <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= nums[i] &lt;= n</code></li>
  <li>Each element in <code>nums</code> appears once or twice</li>
</ul>


## Solution1:

<strong>Logical Thinking</strong>
<p>It is obvious to use a hash table to store the existing values, if the new value <code>nums[i]</code> is already in the hash table, it appears twice. It takes <code>O(n)</code> time to raverse the whole <code>nums</code>, but the value searching in the hash table will cost <code>O(n)</code> in the worst case.</p>


<strong>C++</strong> 

```
//  Topic   ：442. Find All Duplicates in an Array (https://leetcode.com/problems/find-all-duplicates-in-an-array/)
//  Author  : YCX
//  Time    : O(N) average, O(N^2) worst
//  Space   : O(N)


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (freq[nums[i]] == 1)
                ans.push_back(nums[i]);
            else
                freq[nums[i]] = 1;
        }
        return ans;
    }
};
```


## Solution2:

<strong>Logical Thinking</strong>
<p>Another idea is to sort <code>nums</code> first, which cost <code>O(nlogn)</code> time. If the adjacent two values are the same <code>nums[i] == nums[i - 1]</code>, the value is the one we need, and the traversal of the whole array uses <code>O(n)</code> time.</p>

<strong>C++</strong>

```
//  Topic   ：442. Find All Duplicates in an Array (https://leetcode.com/problems/find-all-duplicates-in-an-array/)
//  Author  : YCX
//  Time    : O(N * logN)
//  Space   : O(N)


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for (int i = 1; i < n; i++)
            if (nums[i] == nums[i - 1])
                ans.push_back(nums[i]);
        return ans;
    }
};
```


## Solution3:

<strong>Logical Thinking</strong>
<p>Among the constraints, we are told that <code>1 &lt;= nums[i] &lt;= n</code>, which means all values are positive and covered by the indices of the array. Besides, since each element appears once or twice, we can solve it by flipping the elements. If the element <code>nums[i]</code> appears once, after flipping <code>nums[abs(nums[i]) - 1]</code> will makes <code>nums[abs(nums[i]) - 1]</code> become negative; If the element <code>nums[i]</code> appears twice, after flipping <code>nums[abs(nums[i]) - 1]</code>, it is still positive. So, the problem becomes that finding the indices of positive elements after flipping.</p>

<strong>C++</strong>

```
//  Topic   ：442. Find All Duplicates in an Array (https://leetcode.com/problems/find-all-duplicates-in-an-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            nums[abs(nums[i]) - 1] *= -1;
            if (nums[abs(nums[i]) - 1] > 0)
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};
```