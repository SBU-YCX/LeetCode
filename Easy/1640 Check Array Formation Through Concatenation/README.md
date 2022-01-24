# [1640. Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/)


## Description:

<p>You are given an array of <strong>distinct</strong> integers <code>arr</code> and an array of integer arrays <code>pieces</code>, where the integers in <code>pieces</code> are <strong>distinct</strong>. Your goal is to form <code>arr</code> by concatenating the arrays in <code>pieces</code> <strong>in any order</strong>. However, you are <strong>not</strong> allowed to reorder the integers in each array <code>pieces[i]</code>.</p>

<p>Return <em><code>true</code> if it is possible to form the array <code>arr</code> from <code>pieces</code>.</em> Otherwise, return <em><code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> arr = [15,88], pieces = [[88],[15]]
<strong>Output:</strong> true
<strong>Explanation:</strong> Concatenate [15] then [88]
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> arr = [49,18,16], pieces = [[16,18,49]]
<strong>Output:</strong> false
<strong>Explanation:</strong> Even though the numbers match, we cannot reorder pieces[0].
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
<strong>Output:</strong> true
<strong>Explanation:</strong> Concatenate [91] then [4,64] then [78]
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= pieces.length &lt;= arr.length &lt;= 100</code></li>
    <li><code>sum(pieces[i].length) == arr.length</code></li>
    <li><code>1 &lt;= pieces[i].length &lt;= arr.length</code></li>
    <li><code>1 &lt;= arr[i], pieces[i][j] &lt;= 100</code></li>
    <li>The integers in <code>arr</code> are <strong>distinct</strong>.</li>
    <li>The integers in <code>pieces</code> are <strong>distinct</strong> (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since all integers in <code>pieces</code> are distinct, we can use the first integer of <code>pieces[i]</code> as a key and build a <strong>hash table</strong>. Then traverse the whole array <code>arr</code>, for each integer, find out whether it is a first value of any <code>pieces[i]</code>, and see if we can concate that array here.</p>


<strong>C++</strong>

```
//  Topic   : 1640. Check Array Formation Through Concatenation
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(M)


class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> ht;
        int n = arr.size(), m = pieces.size();
        for (int i = 0; i < m; i++)
            ht[pieces[i][0]] = i;
        for (int i = 0; i < n;)
        {
            if (!ht.count(arr[i]))
                return false;
            int j = ht[arr[i]];
            for (int k = 0; k < pieces[j].size();)
            {
                if (arr[i] == pieces[j][k])
                {
                    i++;
                    k++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
```