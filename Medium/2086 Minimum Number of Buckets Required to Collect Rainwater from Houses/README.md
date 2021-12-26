# [2086. Minimum Number of Buckets Required to Collect Rainwater from Houses](https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/)


## Description:

<p>You are given a <strong>0-indexed</strong> string <code>street</code>. Each character in <code>street</code> is either <code>'H'</code> representing a house or <code>'.'</code> representing an empty space.</p>

<p>You can place buckets on the <strong>empty spaces</strong> to collect rainwater that falls from the adjacent houses. The rainwater from a house at index <code>i</code> is collected if a bucket is placed at index <code>i - 1</code> <strong>and/or</strong> index <code>i + 1</code>. A single bucket, if placed adjacent to two houses, can collect the rainwater from <strong>both</strong> houses.</p>

<p>Return <em>the <strong>minimum</strong> number of buckets needed so that for <strong>every</strong> house, there is <strong>at least</strong> one bucket collecting rainwater from it, or <code>-1</code> if it is impossible.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> street = "H..H"
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
We can put buckets at index 1 and index 2.
"H..H" -> "HBBH" ('B' denotes where a bucket is placed).
The house at index 0 has a bucket to its right, and the house at index 3 has a bucket to its left.
Thus, for every house, there is at least one bucket collecting rainwater from it.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> street = ".H.H."
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
We can put a bucket at index 2.
".H.H." -> ".HBH." ('B' denotes where a bucket is placed).
The house at index 1 has a bucket to its right, and the house at index 3 has a bucket to its left.
Thus, for every house, there is at least one bucket collecting rainwater from it.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> street = ".HHH."
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
There is no empty space to place a bucket to collect the rainwater from the house at index 2.
Thus, it is impossible to collect the rainwater from all the houses.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= street.length &lt;= 10<sup>5</sup></code></li>
    <li><code>street[i]</code> is either <code>'H'</code> or <code>'.'</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>When we add buckets, some positions have priority, that is <code>"H.H"</code> should be filled first, i.e. for the case <code>".H.H."</code>, we can use minimum number of buckets if we put it in the middle empty space. So, we can use <strong>two pass</strong> for this problem.</p>

<ul>
    <li>The first time, we go through the whole string and fill the empty spaces in the pattern <code>"H.H"</code>;</li>
    <li>The second time, find the spaces adjacent to the remaining houses, i.e. <code>".H"</code> or <code>"H."</code>;</li>
</ul>

<p>After two passes, if there are still houses left, we cannot find such a solution to assign a bucket for each house.</p>


<strong>C++</strong>

```
//  Topic   : 2086. Minimum Number of Buckets Required to Collect Rainwater from Houses (https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.length(), ans = 0;
        for (int i = 0; i < n - 2; i++)
            if (street[i] == 'H' && street[i + 1] == '.' && street[i + 2] == 'H')
            {
                ans++;
                street[i] = 'X';
                street[i + 1] = 'B';
                street[i + 2] = 'X';
            }
        for (int i = 0; i < n; i++)
            if (street[i] == 'H')
            {
                if (i > 0 && street[i - 1] == '.')
                {
                    ans++;
                    street[i] = 'X';
                    street[i - 1] = 'B';
                }
                else if (i < n - 1 && street[i + 1] == '.')
                {
                    ans++;
                    street[i] = 'X';
                    street[i + 1] = 'B';
                }
            }
        for (int i = 0; i < n; i++)
            if (street[i] == 'H')
                return -1;
        return ans;
    }
};
```