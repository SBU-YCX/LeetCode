# [1566. Detect Pattern of Length M Repeated K or More Times](https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/)


## Description:

<p>Given an array of positive integers <code>arr</code>, find a pattern of length <code>m</code> that is repeated <code>k</code> or more times.</p>

<p>A <strong>pattern</strong> is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times <strong>consecutively</strong> without overlapping. A pattern is defined by its length and the number of repetitions.</p>

<p>Return <em><code>true</code> if there exists a pattern of length <code>m</code> that is repeated <code>k</code> or more times, otherwise return <code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> arr = [1,2,4,4,4,4], m = 1, k = 3
<strong>Output:</strong> true
<strong>Explanation:</strong> The pattern (4) of length 1 is repeated 4 consecutive times. Notice that pattern can be repeated k or more times but not less.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> The pattern (1,2) of length 2 is repeated 2 consecutive times. Another valid pattern (2,1) is also repeated 2 times.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> arr = [1,2,1,2,1,3], m = 2, k = 3
<strong>Output:</strong> false
<strong>Explanation:</strong> The pattern (1,2) is of length 2 but is repeated only 2 times. There is no pattern of length 2 that is repeated 3 or more times.
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= arr.length &lt;= 100</code></li>
    <li><code>1 &lt;= arr[i] &lt;= 100</code></li>
    <li><code>1 &lt;= m &lt;= 100</code></li>
    <li><code>2 &lt;= k &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the repeated patterns are consecutive, i.e., <code>arr[i] == arr[i + m] == arr[i + 2 * m] == ...</code>, so we need to count the number of consecutive such pairs that <code>arr[i] == arr[i + m]</code>, which should appear <code>m * (k - 1)</code> times.</p>


<strong>C++</strong>

```
//  Topic   : 1566. Detect Pattern of Length M Repeated K or More Times
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int c = 0, n = arr.size();
        for (int i = 0; i < n - m; i++)
        {
            if (arr[i] != arr[i + m])
                c = 0;
            else
                c++;
            if (c == m * (k - 1))
                return true;
        }
        return false;
    }
};
```
