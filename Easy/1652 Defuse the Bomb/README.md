# [1652. Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/)


## Description:

<p>You have a bomb to defuse, and your time is running out! Your informer will provide you with a <strong>circular</strong> array <code>code</code> of length of <code>n</code> and a key <code>k</code>.</p>

<p>To decrypt the code, you must replace every number. All the numbers are replaced <strong>simultaneously</strong>.</p>

<ul>
    <li>If <code>k &gt; 0</code>, replace the <code>i<sup>th</sup></code> number with the sum of the <strong>next</strong> <code>k</code> numbers.</li>
    <li>If <code>k &lt; 0</code>, replace the <code>i<sup>th</sup></code> number with the sum of the <strong>previous</strong> <code>k</code> numbers.</li>
    <li>If <code>k == 0</code>, replace the <code>i<sup>th</sup></code> number with <code>0</code>.</li>
</ul>

<p>As <code>code</code> is circular, the next element of <code>code[n-1]</code> is <code>code[0]</code>, and the previous element of <code>code[0]</code> is <code>code[n-1]</code>.</p>

<p>Given the <strong>circular</strong> array <code>code</code> and an integer key <code>k</code>, return <em>the decrypted code to defuse the bomb!</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> code = [5,7,1,4], k = 3
<strong>Output:</strong> [12,10,16,13]
<strong>Explanation:</strong> Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> code = [1,2,3,4], k = 0
<strong>Output:</strong> [0,0,0,0]
<strong>Explanation:</strong> When k is zero, the numbers are replaced by 0. 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> code = [2,4,9,3], k = -2
<strong>Output:</strong> [12,5,6,13]
<strong>Explanation:</strong> The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
</pre>


## Constraints:

<ul>
    <li><code>n == code.length</code></li>
    <li><code>1 &lt;= n &lt;= 100</code></li>
    <li><code>1 &lt;= code[i] &lt;= 100</code></li>
    <li><code>-(n - 1) &lt;= k &lt;= n - 1</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>First, using <strong>sliding window</strong> to calculate the sum for each window of size <code>abs(k)</code>, i.e., <code>sum[i] = code[i] + ... + code[(i + abs(k) - 1) % n] = sum[i - 1] - code[i - 1] + code[(i + abs(k) - 1) % n]</code>, then, we can do the replacement by finding the corresponding index with modulation, specifically</p>

<ul>
    <li>if <code>k &gt; 0</code>, <code>ans[i] = sum[(i + 1) % n]</code></li>
    <li>if <code>k &lt; 0</code>, <code>ans[i] = sum[(i + k + n) % n]</code></li>
    <li>if <code>k == 0</code>, <code>ans[i] = 0</code></li>
</ul>


<strong>C++</strong>

```
//  Topic   : 1652. Defuse the Bomb
//  Author  : YCX
//  Time    : O(N + K)
//  Space   : O(N)


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int m = code.size();
        vector<int> sum(m, 0);
        for (int i = 0; i < abs(k); i++)
            sum[0] += code[i];
        for (int j = 1; j < m; j++)
            sum[j] = (sum[j - 1] - code[j - 1] + code[(j - 1 + abs(k)) % m]);
        for (int i = 0; i < m; i++)
        {
            if (k > 0)
                ans.push_back(sum[(i + 1) % m]);
            else if (k < 0)
                ans.push_back(sum[(m + i + k) % m]);
            else
                ans.push_back(0);
        }
        return ans;
    }
};
```
