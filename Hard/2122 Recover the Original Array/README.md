# [2122. Recover the Original Array](https://leetcode.com/problems/recover-the-original-array/)


## Description:

<p>Alice had a <strong>0-indexed</strong> array <code>arr</code> consisting of <code>n</code> <strong>positive</strong> integers. She chose an arbitrary <strong>positive integer</strong> <code>k</code> and created two new <strong>0-indexed</strong> integer arrays <code>lower</code> and <code>higher</code> in the following manner:</p>

<ul>
    <li><code>lower[i] = arr[i] - k</code>, for every index <code>i</code> where <code>0 &lt;= i &lt; n</code></li>
    <li><code>higher[i] = arr[i] + k</code>, for every index <code>i</code> where <code>0 &lt;= i &lt; n</code></li>
</ul>

<p>Unfortunately, Alice lost all three arrays. However, she remembers the integers that were present in the arrays <code>lower</code> and <code>higher</code>, but not the array each integer belonged to. Help Alice and recover the original array.</p>

<p>Given an array <code>nums</code> consisting of <code>2n</code> integers, where <strong>exactly</strong> <code>n</code> of the integers were present in <code>lower</code> and the remaining in <code>higher</code>, return <em>the <strong>original</strong> array <code>arr</code>.</em> In case the answer is not unique, return <em><strong>any</strong> valid array.</em></p>

<p><strong>Note:</strong> The test cases are generated such that there exists <strong>at least one</strong> valid array <code>arr</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [2,10,6,4,8,12]
<strong>Output:</strong> [3,7,11]
<strong>Explanation:</strong> 
If arr = [3,7,11] and k = 1, we get lower = [2,6,10] and higher = [4,8,12].
Combining lower and higher gives us [2,6,10,4,8,12], which is a permutation of nums.
Another valid possibility is that arr = [5,7,9] and k = 3. In that case, lower = [2,4,6] and higher = [8,10,12]. 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,3,3]
<strong>Output:</strong> [2,2]
<strong>Explanation:</strong> 
If arr = [2,2] and k = 1, we get lower = [1,1] and higher = [3,3].
Combining lower and higher gives us [1,1,3,3], which is equal to nums.
Note that arr cannot be [1,3] because in that case, the only possible way to obtain [1,1,3,3] is with k = 0.
This is invalid since k must be positive. 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [5,435]
<strong>Output:</strong> [220]
<strong>Explanation:</strong> 
The only possible combination is arr = [220] and k = 215. Using them, we get lower = [5] and higher = [435].
</pre>


## Constraints:

<ul>
    <li><code>2 * n == nums.length</code></li>
    <li><code>1 &lt;= n &lt;= 1000</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
    <li>The test cases are generated such that there exists <strong>at least one</strong> valid array <code>arr</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>For this problem, we <strong>greedily</strong> try all possible <code>k</code>s. To do this, we <strong>sort</strong> <code>nums</code>, count and save the frequency of each value in a <strong>hash table</strong> <code>m</code>. Then, we try all differences <code>d = nums[i] - nums[0]</code> for <code>i &gt; 0</code>. The difference needs to be even, i.e. <code>d % 2 == 0</code>, since <code>d == 2 * k</code>. During checking, for each element <code>low</code> in <code>nums</code>, see if we can find the corresponding <code>high = low + d</code>. If so, we need to reduce the frequency of <code>high</code> as well as <code>low</code>, i.e. <code>m[high] -= m[low] && m[low] = 0</code>, since <code>high</code> is already assigned to vector <code>higher</code> and don't need to consider it as a potential element of <code>lower</code>. If we cannot find the pair <code>(low, high)</code>, the current <code>d</code> is not the one we need. </p>


<strong>C++</strong>

```
// Topic     : 2122. Recover the Original Array (https://leetcode.com/problems/recover-the-original-array/)
// Author    : YCX
// Time      : O(NlogN + N^2)
// Space     : O(N)


class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (auto& i : nums)
            mp[i]++;
        int k, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            k = nums[i] - nums[0];
            if (k % 2)
                continue;
            if (success(k, mp, nums, n))
                break;
        }
        k /= 2;
        vector<int> ans;
        for (auto& low : nums)
        {
            if (mp[low] == 0)
                continue;
            int arr = low + k, high = low + 2 * k;
            mp[high] -= mp[low];
            while (mp[low])
            {
                ans.push_back(arr);
                mp[low]--;
            }
        }
        return ans;
    }
    
private:
    bool success(int k, unordered_map<int, int>& mp, vector<int>& nums, int& n)
    {
        int l = 0;
        auto mq = mp;
        for (auto& low : nums)
        {
            if (mq[low] == 0)
                continue;
            int high = low + k;
            if (!mq.count(high) || mq[high] < mq[low])
                return false;
            l += (2 * mq[low]);
            mq[high] -= mq[low];
            mq[low] = 0;
        }
        return (l == n);
    }
};
```
