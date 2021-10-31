# [2032. Two Out of Three](https://leetcode.com/problems/two-out-of-three/)


## Description:

<p>Given three integer arrays <code>nums1</code>, <code>nums2</code>, and <code>nums3</code>, return <em>a <strong>distinct</strong> array containing all the values that are present in <strong>at least two</strong> out of the three arrays. You may return the values in <strong>any</strong> order.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
<strong>Output:</strong> [3,2]
<strong>Explanation:</strong> The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
<strong>Output:</strong> [2,3,1]
<strong>Explanation:</strong> The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
<strong>Output:</strong> []
<strong>Explanation:</strong> No value is present in at least two arrays.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums1.length, nums2.length, nums3.length &lt;= 100</code></li>
  <li><code>1 &lt;= nums1[i], nums2[j], nums3[k] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using a <strong>Hash Table</strong> <code>m</code> to store the appearance of each element in each array. Since there may be duplicate elements in an array, we use a <strong>Bit Mask</strong> to keep this infomation, such that a bit is set to be <code>1</code> if the key value exist in the corresponding array. Then, we only need to check the keys in the map and see whether the value is <code>"101"</code>, <code>"110"</code>, <code>"011"</code> or <code>"111"</code></p>


<strong>C++</strong>

```
//  Topic   : 2032. Two Out of Three (https://leetcode.com/problems/two-out-of-three/)
//  Author  : YCX
//  Time    : O(N = N1 + N2 + N3)
//  Space   : O(N = N1 + N2 + N3)


class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int n1 = nums1.size(), n2 = nums2.size(), n3 = nums3.size(); 
        unordered_map<int, string> m;
        for (int i = 0; i < n1; i++)
        {
            if (m.count(nums1[i]) == 0)
                m[nums1[i]] = "001";
            else
                m[nums1[i]][2] = '1';
        }
        for (int i = 0; i < n2; i++)
        {
            if (m.count(nums2[i]) == 0)
                m[nums2[i]] = "010";
            else
                m[nums2[i]][1] = '1';
        }
        for (int i = 0; i < n3; i++)
        {
            if (m.count(nums3[i]) == 0)
                m[nums3[i]] = "100";
            else
                m[nums3[i]][0] = '1';
        }
        vector<int> ans;
        for (auto i : m)
            if (i.second == "101" || i.second == "110" || i.second == "011" || i.second == "111")
                ans.push_back(i.first);
        return ans;
    }
};
```
