# [2070. Most Beautiful Item for Each Query](https://leetcode.com/problems/most-beautiful-item-for-each-query/)


## Description:

<p>You are given a 2D integer array <code>items</code> where <code>items[i] = [price<sub>i</sub>, beauty<sub>i</sub>]</code> denotes the <strong>price</strong> and <strong>beauty</strong> of an item respectively.</p>

<p>You are also given a <strong>0-indexed</strong> integer array <code>queries</code>. For each <code>queries[j]</code>, you want to determine the <strong>maximum beauty</strong> of an item whose <strong>price</strong> is <strong>less than or equal to</strong> <code>queries[j]</code>. If no such item exists, then the answer to this query is <code>0</code>.</p>

<p>Return <em>an array <code>answer</code> of the same length as <code>queries</code> where <code>answer[j]</code> is the answer to the <code>j<sup>th</sup></code> query.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
<strong>Output:</strong> [2,4,5,5,6,6]
<strong>Explanation:</strong> 
- For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
- For queries[1]=2, the items which can be considered are [1,2] and [2,4]. 
  The maximum beauty among them is 4.
- For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
  The maximum beauty among them is 5.
- For queries[4]=5 and queries[5]=6, all items can be considered.
  Hence, the answer for them is the maximum beauty of all items, i.e., 6.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
<strong>Output:</strong> [4]
<strong>Explanation:</strong> 
The price of every item is equal to 1, so we choose the item with the maximum beauty 4. 
Note that multiple items can have the same price and/or beauty.  
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> items = [[10,1000]], queries = [5]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> 
No item has a price less than or equal to 5, so no item can be chosen.
Hence, the answer to the query is 0.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= items.length, queries.length &lt;= 10<sup>5</sup></code></li>
  <li><code>items[i].length == 2</code></li>
  <li><code>1 &lt;= pricei, beautyi, queries[j] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>For this problem, we need to find the maximum beauty of an item whose price is less than or equal to <code>queries[j]</code> for each <code>j</code>, if we directly check them one-by-one, the time complexity is <code>O(M * N)</code>. To improve it, we can first <strong>sort</strong> both <code>items</code> and <code>queries</code> such that for a pair <code>[i, j]</code>, if <code>items[i][0] &lt;= queries[j]</code>, the maximum beauty <code>maxv = max(items[k][1]), k &lt;= i</code> can be used and we don't need to check the pairs <code>[p, q]</code> where <code>p &lt; i</code> and <code>q &gt; j</code>, then the checking process will only take <code>O(M + N)</code> time. So the total time complexity is reduced to <code>O(NlogN + MlogM + M + N)</code>.</p>

 
<strong>C++</strong>

```
//  Topic   ：2070. Most Beautiful Item for Each Query (https://leetcode.com/problems/most-beautiful-item-for-each-query/)
//  Author  : YCX
//  Time    : O(NlogN + MlogM + M + N)
//  Space   : O(M)


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size(), m = items.size(), k = 0, maxv = 0;
        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < n; i++)
            idx[queries[i]].push_back(i);
        sort(items.begin(), items.end());
        sort(queries.begin(), queries.end());
        vector<int> ans(n, 0);
        for (auto lim : queries)
        {
            while (k < m && items[k][0] <= lim)
            {
                maxv = max<int>(maxv, items[k][1]);
                k++;
            }
            for (auto j : idx[lim])
                ans[j] = maxv;
        }
        return ans;
    }
};
```
