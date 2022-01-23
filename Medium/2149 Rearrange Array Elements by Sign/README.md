# [2149. Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/)


## Description:

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of <strong>even</strong> length consisting of an <strong>equal</strong> number of positive and negative integers.</p>

<p>You should <strong>rearrange</strong> the elements of <code>nums</code> such that the modified array follows the given conditions:</p>

<ol>
    <li>Every <strong>consecutive pair</strong> of integers have <strong>opposite signs</strong>.</li>
    <li>For all integers with the same sign, the <strong>order</strong> in which they were present in <code>nums</code> is <strong>preserved</strong>.</li>
    <li>The rearranged array begins with a positive integer.</li>
</ol>

<p>Return <em>the modified array after rearranging the elements to satisfy the aforementioned conditions.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [3,1,-2,-5,2,-4]
<strong>Output:</strong> [3,-2,1,-5,2,-4]
<strong>Explanation:</strong> 
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [-1,1]
<strong>Output:</strong> [1,-1]
<strong>Explanation:</strong> 
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
    <li><code>nums.length</code> is <strong>even</strong></li>
    <li><code>1 &lt;= |nums[i]| &lt;= 10<sup>5</sup></code></li>
    <li><code>nums</code> consists of <strong>equal</strong> number of positive and negative integers.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use <strong>two pointers</strong> <code>i</code> and <code>j</code> to point to positive elements and negative elements, move both of them from left to right and add the corresponding elements to the answer array alternatively.</p>


<strong>C++</strong>

```
//  Topic   : 2149. Rearrange Array Elements by Sign
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> ans(n, 0);
        for (int k = 0; k < n; k += 2)
        {
            while (i < n && nums[i] < 0)
                i++;
            ans[k] = nums[i];
            i++;
            while (j < n && nums[j] > 0)
                j++;
            ans[k + 1] = nums[j];
            j++;
        }
        return ans;
    }
};
```