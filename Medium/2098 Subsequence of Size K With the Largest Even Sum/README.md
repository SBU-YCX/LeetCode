# [2098. Subsequence of Size K With the Largest Even Sum](https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum/)


## Description:

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. Find the <strong>largest even sum</strong> of any subsequence of <code>nums</code> that has a length of <code>k</code>.

<p>Return <em>this sum, or <code>-1</code> if such a sum does not exist.</em></p>

<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [4,1,5,3,1], k = 3
<strong>Output:</strong> 12
<strong>Explanation:</strong> 
The subsequence with the largest possible even sum is [4,5,3]. It has a sum of 4 + 5 + 3 = 12.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,3,5], k = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
No subsequence of nums with length 1 has an even sum.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= k &lt;= nums.length<code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the problem asks us to find the subsequence, so the order doesn't matter and we need to put larger elements in our final subsequence. Besides, we know that in order to get an even sum, the final subsequence can only contains even number of odd elements. Therefore, we separately store even elements and odd elements into two vectors <code>odd</code> and <code>even</code>, then <strong>sort</strong> them from large to small. To reduce the complexity of calculating the sum, we apply <strong>prefix sum</strong> to both vectors. Each time, we pick even number <code>i + 1</code> (<code>i</code> is the index) of odd elements and <code>k - i - 1</code> even elements from left to right, and calculate the sum <code>even[(k - i - 1) - 1] + odd[i]</code>. After checking all the combinations, we get the largest sum.</p>


<strong>C++</strong>

```
//  Topic   : 2098. Subsequence of Size K With the Largest Even Sum (https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum/)
//  Author  : YCX
//  Time    : O(NlogN + N)
//  Space   : O(N)


class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        vector<long long> odd, even;
        for (auto& i : nums)
        {
            if (i % 2)
                odd.push_back(i);
            else
                even.push_back(i);
        }
        int m = odd.size(), n = even.size();
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());
        for (int i = 1; i < m; i++)
            odd[i] += odd[i - 1];
        for (int i = 1; i < n; i++)
            even[i] += even[i - 1];
        long long ans = -1;
        if (n >= k)
            ans = even[k - 1];
        if (m >= k && !(k % 2))
            ans = max<long long>(ans, odd[k - 1]);
        for (int i = 1; i < m; i += 2)
            if (i > k - 2 - n && i <= k - 2)
                ans = max<long long>(ans, even[k - i - 2] + odd[i]);
        return ans;
    }
};
```