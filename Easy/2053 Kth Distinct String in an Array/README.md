# [2053. Kth Distinct String in an Array](https://leetcode.com/problems/kth-distinct-string-in-an-array/)


## Description:

<p>A <strong>distinct string</strong> is a string that is present only <strong>once</strong> in an array.</p>
<p>Given an array of strings <code>arr</code>, and an integer <code>k</code>, return the <code>k<sup>th</sup></code> <strong>distinct string</strong> present in arr. If there are <strong>fewer</strong> than <code>k</code> distinct strings, return an <strong>empty string</strong> <code>""</code>.</p>
<p>Note that the strings are considered in the <strong>order in which they appear</strong> in the array.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> arr = ["d","b","c","b","c","a"], k = 2
<strong>Output:</strong> "a"
<strong>Explanation:</strong> 
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> arr = ["aaa","aa","a"], k = 1
<strong>Output:</strong> "aaa"
<strong>Explanation:</strong> 
All strings in arr are distinct, so the 1st string "aaa" is returned.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> arr = ["a","b","a"], k = 3
<strong>Output:</strong> ""
<strong>Explanation:</strong> 
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= k &lt;= arr.length &lt;= 1000</code></li>
  <li><code>1 &lt;= arr[i].length &lt;= 5</code></li>
  <li><code>arr[i]</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using a <strong>map</strong> <code>m</code> to store the frequency of every string in the array. Then, go through the whole array, if the string appears once, <code>k</code> decreases by <code>1</code>, when <code>k</code> becomes <code>0</code>, we find the target.</p>


<strong>C++</strong>

```
//  Topic   : 2053. Kth Distinct String in an Array (https://leetcode.com/problems/kth-distinct-string-in-an-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for (auto i : arr)
            m[i]++;
        for (auto i : arr)
            if (m[i] == 1)
            {
                k--;
                if (k == 0)
                    return i;
            }
        return "";
    }
};
```
