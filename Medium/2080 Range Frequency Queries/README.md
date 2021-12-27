# [2080. Range Frequency Queries](https://leetcode.com/problems/range-frequency-queries/)


## Description:

<p>Design a data structure to find the <strong>frequency</strong> of a given value in a given subarray.</p>

<p>The <strong>frequency</strong> of a value in a subarray is the number of occurrences of that value in the subarray.</p>

<p>Implement the <code>RangeFreqQuery</code> class:</p>

<uL>
    <li><code>RangeFreqQuery(int[] arr)</code> Constructs an instance of the class with the given <strong>0-indexed</strong> integer array arr.</li>
    <li><code>int query(int left, int right, int value)</code> Returns the <strong>frequency</strong> of <code>value</code> in the subarray <code>arr[left...right]</code>.</li>
</uL>

<p>A <strong>subarray</strong> is a contiguous sequence of elements within an array. <code>arr[left...right]</code> denotes the subarray that contains the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> (<strong>inclusive</strong>).</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong>
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
<strong>Output:</strong> 
[null, 1, 2]
<strong>Explanation:</strong> 
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // return 1. The value 4 occurs 1 time in the subarray [33, 4]
rangeFreqQuery.query(0, 11, 33); // return 2. The value 33 occurs 2 times in the whole array.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= arr[i], value &lt;= 10<sup>4</sup></code></li>
    <li><code>0 &lt;= left &lt;= right &lt; arr.length</code></li>
    <li>At most <code>10<sup>5</sup></code> calls will be made to <code>query</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Store the indices of each value in a <stong>hash table</stong> <code>data</code>. For each value <code>v</code>, the indices in <code>data[v]</code> is sorted, so we can use <strong>binary search</strong> for each query with the help of <code>lower_bound()</code> and <code>higher_bound()</code> to find the boundaries of indices located within <code>[left, right]</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2080. Range Frequency Queries (https://leetcode.com/problems/range-frequency-queries/)
//  Author  : YCX
//  Time    : O(logN) for query()
//            O(N) for RangeFreqQuery()
//  Space   : O(N)


class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++)
            data[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        int l = lower_bound(data[value].begin(), data[value].end(), left) - data[value].begin();
        int r = upper_bound(data[value].begin(), data[value].end(), right) - data[value].begin();
        return (r - l);
    }
    
private: 
    unordered_map<int, vector<int>> data;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
```