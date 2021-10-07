# [1442. Count Triplets That Can Form Two Arrays of Equal XOR](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)


## Description:

<p>Given an array of integers <code>arr</code>.</p>
<p>We want to select three indices <code>i</code>, <code>j</code> and <code>k</code> where <code>(0 &lt;= i &lt; j &lt;= k &lt; arr.length)</code>.</p>
<p>Let's define a and b as follows:</p>
<ul>
  <li><code>a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]</code></li>
  <li><code>b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]</code></li>
</ul>
<p>Note that <strong>^</strong> denotes the <strong>bitwise-xor</strong> operation.</p>
<p>Return <em>the number of triplets (<code>i</code>, <code>j</code> and <code>k</code>) Where <code>a == b</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> arr = [2,3,1,6,7]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> arr = [1,1,1,1,1]
<strong>Output:</strong> 10
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> arr = [2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> arr = [1,3,5,7,9]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>

<strong>Example 5:</strong>
<pre>
<strong>Input:</strong> arr = [7,11,12,9,5,2,7,17,22]
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= arr.length &lt;= 300</code></li>
  <li><code>1 &lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>From the requirements and the properties of <code>xor</code>, we know that if <code>a == b</code>, we have <code>arr[i] ^ arr[i + 1] ^ ... ^ arr[k - 1] ^ arr[k] == 0</code>. Therefore, the problem becomes that finding such an interval <code>[i, k]</code> that the result of <code>xor</code> of elements within it is <code>0</code>, and each idx except the <code>i</code> can be regarded as <code>j</code>, i.e. the number of triplets for a given <code>[i, k]</code> is <code>k - i</code>. To effectively calculate the <code>xor</code> result for a given interval, we can use <strong>Prefix Sum</strong> to store the result up to <code>i</code> as <code>prexor[i]</code> in an array.</p>


<strong>C++</strong>

```
// Topic     : 1442. Count Triplets That Can Form Two Arrays of Equal XOR (https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)
// Author    : YCX
// Time      : O(N^2)
// Space     : O(N)


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int> prexor(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prexor[i] = prexor[i - 1] ^ arr[i - 1];
        for (int i = 1; i <= n; i++)
            for (int k = i + 1; k <= n; k++)
                if (prexor[k] == prexor[i - 1])
                    ans += (k - i);
        return ans;
    }
};
```