# [1619. Mean of Array After Removing Some Elements](https://leetcode.com/problems/mean-of-array-after-removing-some-elements/)


## Description:

<p>Given an integer array <code>arr</code>, return <em>the mean of the remaining integers after removing the smallest <code>5%</code> and the largest <code>5%</code> of the elements.</em></p>

<p>Answers within <code>10<sup>-5</sup></code> of the <strong>actual answer</strong> will be considered accepted.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
<strong>Output:</strong> 2.00000
<strong>Explanation:</strong> After erasing the minimum and the maximum values of this array, all elements are equal to 2, so the mean is 2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
<strong>Output:</strong> 4.00000
<strong>Explanation:</strong>
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
<strong>Output:</strong> 4.77778
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>20 &lt;= arr.length &lt;= 1000</code></li>
    <li><code>arr.length</code> is a <strong>multiple</strong> of <code>20</code>.</li>
    <li><code>0 &lt;= arr[i] &lt;= 10<sup>5</sup></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Sort</strong> the array and calculate the sum within the required range.</p>


<strong>C++</strong>

```
//  Topic   : 1619. Mean of Array After Removing Some Elements
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(1ogN)


class Solution {
public:
    double trimMean(vector<int>& arr) {
        int m = arr.size();
        int n = m / 20;
        double ans = 0;
        sort(arr.begin(), arr.end());
        for (int i = n; i < m - n; i++)
            ans += arr[i];
        return ans / (m - 2 * n);
    }
};
```