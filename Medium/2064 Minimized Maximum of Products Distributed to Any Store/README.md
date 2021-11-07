# [2064. Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)


## Description:

<p>You are given an integer <code>n</code> indicating there are <code>n</code> specialty retail stores. There are <code>m</code> product types of varying amounts, which are given as a <strong>0-indexed</strong> integer array <code>quantities</code>, where <code>quantities[i]</code> represents the number of products of the <code>i<sup>th</sup></code> product type.</p>

<p>You need to distribute <strong>all products</strong> to the retail stores following these rules:</p>

A store can only be given <strong>at most one product type</strong> but can be given <strong>any</strong> amount of it.
After distribution, each store will be given some number of products (possibly <code>0</code>). Let <code>x</code> represent the maximum number of products given to any store. You want <code>x</code> to be as small as possible, i.e., you want to <strong>minimize</strong> the <strong>maximum</strong> number of products that are given to any store.
<p>Return <em>the minimum possible <code>x</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 6, quantities = [11,6]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 7, quantities = [15,10,10]
<strong>Output:</strong> 5
<strong>Explanation:</strong> One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> n = 1, quantities = [100000]
<strong>Output:</strong> 100000
<strong>Explanation:</strong>  The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.
</pre>


## Constraints:

<ul>
  <li><code>m == quantities.length</code></li>
  <li><code>1 &lt;= m &lt;= n &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= quantities[i] <= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>This problem can be solved by <strong>binary search</strong>. Each time we choose a value as the possible maximum number of products given to the store and see if all the products can be separated to <code>m</code> stores, where <code>m &lt; n</code>.</p>

 
<strong>C++</strong>

```
//  Topic   ：2064. Minimized Maximum of Products Distributed to Any Store (https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)
//  Author  : YCX
//  Time    : O(N * logM) [M is the maximum value of the array, <= 1e5]
//  Space   : O(1)


class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int r = *max_element(quantities.begin(), quantities.end()), l = 1, ans;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (ok(quantities, m, n))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    
private: 
    bool ok(vector<int>& quantities, int maxv, int n)
    {
        int m = 0, i = 0, j = quantities.size();
        while (i < j)
        {
            m += quantities[i] / maxv;
            if (quantities[i] % maxv)
                m++;
            i++;
        }
        return (m <= n);
    }
};
```
