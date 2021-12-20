# [2111. Minimum Operations to Make the Array K-Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)


## Description:

<p>You are given a <strong>0-indexed</strong> array <code>arr</code> consisting of <code>n</code> positive integers, and a positive integer <code>k</code>.</p>

<p>The array <code>arr</code> is called <strong>K-increasing</strong> if <code>arr[i-k] &lt;= arr[i]</code> holds for every index <code>i</code>, where <code>k &lt;= i &lt;= n - 1</code>.</p>
<ul>
    <li>For example, <code>arr = [4, 1, 5, 2, 6, 2]</code> is K-increasing for <code>k = 2</code> because:</li>
        <ul>
            <li><code>arr[0] &lt;= arr[2] (4 &lt;= 5)</code></li>
            <li><code>arr[1] &lt;= arr[3] (1 &lt;= 2)</code></li>
            <li><code>arr[2] &lt;= arr[4] (5 &lt;= 6)</code></li>
            <li><code>arr[3] &lt;= arr[5] (2 &lt;= 2)</code></li>
        </ul>
    <li>However, the same arr is not K-increasing for <code>k = 1</code> (because <code>arr[0] &gt; arr[1]</code>) or <code>k = 3</code> (because <code>arr[0] &gt; arr[3]</code>).</li>
</ul>
<p>In one <strong>operation</strong>, you can choose an index <code>i</code> and <strong>change</strong> <code>arr[i]</code> into <strong>any</strong> positive integer.

<p>Return <em>the <strong>minimum number of operations</strong> required to make the array K-increasing for the given <code>k</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> arr = [5,4,3,2,1], k = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
For k = 1, the resultant array has to be non-decreasing.
Some of the K-increasing arrays that can be formed are [5,6,7,8,9], [1,1,1,1,1], [2,2,3,4,4]. All of them require 4 operations.
It is suboptimal to change the array to, for example, [6,7,8,9,10] because it would take 5 operations.
It can be shown that we cannot make the array K-increasing in less than 4 operations.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> arr = [4,1,5,2,6,2], k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
This is the same example as the one in the problem description.
Here, for every index i where 2 &lt;= i &lt;= 5, arr[i-2] &lt;= arr[i].
Since the given array is already K-increasing, we do not need to perform any operations.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> arr = [4,1,5,2,6,2], k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Indices 3 and 5 are the only ones not satisfying arr[i-3] &lt;= arr[i] for 3 &lt;= i &lt;= 5.
One of the ways we can make the array K-increasing is by changing arr[3] to 4 and arr[5] to 5.
The array will now be [4,1,5,4,6,5].
Note that there can be other ways to make the array K-increasing, but none of them require less than 2 operations.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= arr[i], k &lt;= arr.length</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can decompose the problem into <code>k</code> subproblems, i.e. we need the subsequences with indices <code>{0, k, 2k, 3k, ...}</code>, <code>{1, k + 1, 2k + 1, 3k + 1, ...}</code>, ... increasing separately. For each subsequence, we only need to find the longest increasing subsequence. In order to do that, we can use a vector <code>ordered</code> and for each element in the subsequence, we use <strong>Binary Search</strong> to find the position that it should be in <code>ordered</code>. After go through the whole subsequence, we got the longest one with the lenght equal to the size of <code>ordered</code>. Finally, the answer is the difference between the total number of elements and the sum of lengths of longest increasing subsequence of each group.</p>


<strong>C++</strong>

```
// Topic     : 2111. Minimum Operations to Make the Array K-Increasing (https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)
// Author    : YCX
// Time      : O(NlogN)
// Space     : O(N)


class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < k; i++)
        {
            vector<int> ordered;
            for (int j = i; j < n; j += k)
            {
                if(ordered.size() == 0 || ordered.back() <= arr[j])
                    ordered.push_back(arr[j]);
                else
                    *upper_bound(ordered.begin(), ordered.end(), arr[j]) = arr[j];
            }
            ans += ordered.size();
        }
        return (n - ans);
    }
};
```
