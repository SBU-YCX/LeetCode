# [448. Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)


## Description:

<p>Given an array <code>nums</code> of <code>n</code> integers where <code>nums[i]</code> is in the range <code>[1, n]</code>, return <em>an array of all the integers in the range <code>[1, n]</code> that do not appear in <code>nums</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [4,3,2,7,8,2,3,1]
<strong>Output:</strong> [5,6]
<strong>Explanation:</strong> 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [2]
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>n == nums.length</code></li>
  <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= nums[i] &lt;= n</code></li>
</ul>


## Solution1:

<strong>Logical Thinking</strong>
<p>Using a hash table to store the existing values, then traverse from <code>1</code> to <code>n</code>, if the value <code>i</code> is not in the hash table, it is the disappeared value. It takes <code>O(n)</code> time to raverse the whole <code>[1, n]</code>, but the value searching in the hash table will cost <code>O(n)</code> in the worst case.</p>


<strong>C++</strong> 

```
//  Topic   ：448. Find All Numbers Disappeared in an Array (https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
//  Author  : YCX
//  Time    : O(N) average, O(N^2) worst
//  Space   : O(N)


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> appear;
        for (int i = 0; i < n; i++)
            appear[nums[i]] = 1;
        for (int i = 1; i <= n; i++)
            if (!appear.count(i))
                ans.push_back(i);
        return ans;
    }
};
```


## Solution2:

<strong>Logical Thinking</strong>
<p>Sorting <code>nums</code> first, which cost <code>O(nlogn)</code> time. Traverse the array <code>[1, n]</code> and use a pointer <code>i</code> for <code>nums</code>, if there is no such an <code>i</code> that makes <code>nums[i] == j</code>, the value <code>j</code> is disappeared.</p>

<strong>C++</strong>

```
//  Topic   ：448. Find All Numbers Disappeared in an Array (https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
//  Author  : YCX
//  Time    : O(N * logN)
//  Space   : O(N)


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == n || j < nums[i])
                ans.push_back(j);
            else
                while (i < n && j == nums[i])
                    i++;
        }
        return ans;
    }
};
```


## Solution3:

<strong>Logical Thinking</strong>
<p>Among the constraints, we are told that <code>1 &lt;= nums[i] &lt;= n</code>, which means all values are positive and covered by the indices of the array. We can solve it by flipping the elements. For each element <code>nums[i]</code>, if <code>nums[abs(nums[i]) - 1]</code> is positive, then we will flip <code>nums[abs(nums[i]) - 1]</code> to negative. After flipping, if an element is still positive, the index of that element is the one we want.</p>

<strong>C++</strong>

```
//  Topic   ：448. Find All Numbers Disappeared in an Array (https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                ans.push_back(i + 1);
        return ans;
    }
};
```