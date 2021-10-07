# [1310. XOR Queries of a Subarray](https://leetcode.com/problems/xor-queries-of-a-subarray/)


## Description:

<p>Given the array <code>arr</code> of positive integers and the array <code>queries</code> where <code>queries[i] = [L<sub>i</sub>, R<sub>i</sub>]</code>, for each query <code>i</code> compute the <strong>XOR</strong> of elements from <code>L<sub>i</sub></code> to <code>R<sub>i</sub></code> (that is, <code>arr[L<sub>i</sub>] <strong>xor</strong> arr[L<sub>i</sub>+1] <strong>xor</strong> ... <strong>xor</strong> arr[R<sub>i</sub>]</code>). Return <em>an array containing the result for the given <code>queries</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
<strong>Output:</strong> [2,7,14,8] 
<strong>Explanation:</strong>
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
<strong>Output:</strong> [8,0,4,4]
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
  <li><code>1 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
  <li><code>1 &lt;= queries.length &lt;= 3 * 10<sup>4</sup></code></li>
  <li><code>queries[i].length == 2</code></li>
  <li><code>0 &lt;= queries[i][0] &lt;= queries[i][1] &lt; arr.length</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can utilize the <strong>Prefix Sum</strong> algorithm to calculate the XOR results from <code>0</code> to <code>i</code> and store them in an array <code>prexor</code> through one pass of <code>arr</code>. For the operation <strong>XOR</strong>, we know that if <code>a xor b == c</code>, then <code>a == b xor c</code>, so for each <code>[L<sub>i</sub>, R<sub>i</sub>]</code>, the result is <code>prexor[L<sub>i</sub>] xor prexor[R<sub>i</sub> + 1]</code>.</p>


<strong>C++</strong>

```
// Topic     : 1310. XOR Queries of a Subarray (https://leetcode.com/problems/xor-queries-of-a-subarray/)
// Author    : YCX
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        vector<int> prexor(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prexor[i] = prexor[i - 1] ^ arr[i - 1];
        vector<int> ans;
        for (int i = 0; i < m; i++)
            ans.push_back(prexor[queries[i][1] + 1] ^ prexor[queries[i][0]]);
        return ans;
    }
};
```