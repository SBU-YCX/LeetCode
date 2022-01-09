# [2134. Minimum Swaps to Group All 1's Together II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)


## Description:

<p>A <strong>swap</strong> is defined as taking two <strong>distinct</strong> positions in an array and swapping the values in them.</p>

<p>A <strong>circular</strong> array is defined as an array where we consider the <strong>first</strong> element and the <strong>last</strong> element to be <strong>adjacent</strong>.</p>

<p>Given a <strong>binary circular</strong> array <code>nums</code>, return <em>the minimum number of swaps required to group all <code>1</code>'s present in the array together at <strong>any location</strong>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [0,1,0,1,1,0,0]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [0,1,1,1,0,0,1,1,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,0,0,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
    <li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Suppose there are <code>k</code> <code>1</code>'s in <code>nums</code> and we want to group them together, so we can check each <strong>sliding window</strong> with size <code>k</code> and count the number of <code>1</code>'s within it, then the number of <code>0</code>'s is the number of swaps needed since we can directly swap the <code>0</code> with any <code>1</code> outside the window.</p>


<strong>C++</strong>

```
//  Topic   : 2134. Minimum Swaps to Group All 1's Together II
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        int l = 1, s = accumulate(nums.begin(), nums.begin() + k, 0), ans = k - s;
        while (l < n)
        {
            s -= nums[l - 1];
            s += nums[(l + k - 1) % n];
            ans = min<int>(ans, k - s);
            l++;
        }
        return ans;
    }
};
```
