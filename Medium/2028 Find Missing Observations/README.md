# [2028. Find Missing Observations](https://leetcode.com/problems/find-missing-observations/)


## Description:

<p>You have observations of <code>n + m</code> <strong>6-sided</strong> dice rolls with each face numbered from <code>1</code> to <code>6</code>. <code>n</code> of the observations went missing, and you only have the observations of <code>m</code> rolls. Fortunately, you have also calculated the <strong>average value</strong> of the <code>n + m</code> rolls.</p>
<p>You are given an integer array <code>rolls</code> of length <code>m</code> where <code>rolls[i]</code> is the value of the <code>i<sup>th</sup></code> observation. You are also given the two integers <code>mean</code> and <code>n</code>.</p>
<p>Return <em>an array of length <code>n</code> containing the missing observations such that the <strong>average value</strong> of the <code>n + m</code> rolls is <strong>exactly</strong> <code>mean</code>.</em> If there are multiple valid answers, return <em>any of them</em>. If no such array exists, return <em>an empty array</em>.</p>
<p>The <strong>average value</strong> of a set of <code>k</code> numbers is the sum of the numbers divided by <code>k</code>.</p>
<p>Note that <code>mean</code> is an integer, so the sum of the <code>n + m</code> rolls should be divisible by <code>n + m</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> rolls = [3,2,4,3], mean = 4, n = 2
<strong>Output:</strong> [6,6]
<strong>Explanation:</strong> The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> rolls = [1,5,6], mean = 3, n = 4
<strong>Output:</strong> [2,3,2,2]
<strong>Explanation:</strong> The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> rolls = [1,2,3,4], mean = 6, n = 4
<strong>Output:</strong> []
<strong>Explanation:</strong> It is impossible for the mean to be 6 no matter what the 4 missing rolls are.
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> rolls = [1], mean = 3, n = 1
<strong>Output:</strong> [5]
<strong>Explanation:</strong> The mean of all n + m rolls is (1 + 5) / 2 = 3.
</pre>


## Constraints:

<ul>
  <li><code>m == rolls.length</code></li>
  <li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= rolls[i], mean &lt;= 6</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>First, from <code>m</code>, <code>n</code> and <code>mean</code>, we can get the total sum of all rolls <code>mean * (m + n)</code>. We are also told the array <code>rolls</code> and the sum of <code>m</code> observations can be calculated, which in turn can help us get the sum <code>t</code> of <code>n</code> missing observations. If <code>t</code> is larger than <code>6 * n</code> or smaller than <code>n</code>, there is no possible answer, otherwise, we try to assign the values of these <code>n</code> observations as evenly as possible, so we initially distribute <code>t / n</code> to each observation, and for the first <code>t % n</code> observations, we give them <code>1</code> more. </p>


<strong>C++</strong>

```
//  Topic   ：2028. Find Missing Observations (https://leetcode.com/problems/find-missing-observations/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), t = mean * (m + n);
        for (int i = 0; i < m; i++)
            t -= rolls[i];
        if (t > n * 6 || t < n)
            return {};
        vector<int> ans (n, 0);
        int d = t / n, r = t % n;
        for (int i = 0; i < n; i++)
        {
            ans[i] = d;
            if (i < r)
                ans[i] += 1;
        }
        return ans;
    }
};
```
