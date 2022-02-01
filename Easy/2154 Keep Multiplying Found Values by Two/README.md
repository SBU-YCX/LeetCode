# [2154. Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two/)


## Description:

<p>You are given an array of integers <code>nums</code>. You are also given an integer <code>original</code> which is the first number that needs to be searched for in nums.</p>

<p>You then do the following steps:</p>

<ol>
    <li>If <code>original</code> is found in <code>nums</code>, <strong>multiply</strong> it by two (i.e., set <code>original = 2 * original</code>).</li>
    <li>Otherwise, <strong>stop</strong> the process.</li>
    <li><strong>Repeat</strong> this process with the new number as long as you keep finding the number.</li>
</ol>

<p>Return <em>the <strong>final</strong> value of <code>original</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [5,3,6,1,12], original = 3
<strong>Output:</strong> 24
<strong>Explanation:</strong> 
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [2,7,9], original = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
- 4 is not found in nums. Thus, 4 is returned.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
    <li><code>1 &lt;= nums[i], original &lt;= 1000</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a <strong>hash table</strong> to keep the occurance of each element in the array, then <strong>simulate</strong> the mutiplication process and see if the result exists in the hash table.</p>


<strong>C++</strong>

```
//  Topic   : 2154. Keep Multiplying Found Values by Two
//  Author  : YCX
//  Time    : O(logM) [M is the maximum value]
//  Space   : O(N)


class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> v(1001, 0);
        for (auto& i: nums)
            v[i] = 1;
        while (original <= 1000 && v[original] == 1)
            original *= 2;
        return original;
    }
};
```
