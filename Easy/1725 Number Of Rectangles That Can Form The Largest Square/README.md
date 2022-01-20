# [1725. Number Of Rectangles That Can Form The Largest Square](https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/)


## Description:

<p>You are given an array <code>rectangles</code> where <code>rectangles[i] = [l<sub>i</sub>, w<sub>i</sub>]</code> represents the <code>i<sup>th</sup></code> rectangle of length <code>l<sub>i</sub></code> and width <code>w<sub>i</sub></code>.</p>

<p>You can cut the <code>i<sup>th</sup></code> rectangle to form a square with a side length of <code>k</code> if both <code>k &lt;= l<sub>i</sub></code> and <code>k &lt;= w<sub>i</sub></code>. For example, if you have a rectangle <code>[4,6]</code>, you can cut it to get a square with a side length of at most <code>4</code>.</p>

<p>Let <code>maxLen</code> be the side length of the <strong>largest</strong> square you can obtain from any of the given rectangles.</p>

<p>Return <em>the <strong>number</strong> of rectangles that can make a square with a side length of <code>maxLen</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> rectangles = [[5,8],[3,9],[5,12],[16,5]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The largest squares you can get from each rectangle are of lengths [5,3,5,5].
The largest possible square is of length 5, and you can get it out of 3 rectangles.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> rectangles = [[2,3],[3,7],[4,3],[3,7]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= rectangles.length &lt;= 1000</code></li>
    <li><code>rectangles[i].length == 2</code></li>
    <li><code>1 &lt;= l<sub>i</sub>, w<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
    <li><code>l<sub>i</sub> != w<sub>i</sub></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a variable <code>maxs</code> to represent the largest side length up to now, check each element and update <code>maxs</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1725. Number Of Rectangles That Can Form The Largest Square
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size(), maxs = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            int side = min<int>(rectangles[i][0], rectangles[i][1]);
            if (side > maxs)
            {
                maxs = side;
                ans = 1;
            }
            else if (side == maxs)
                ans++;
        }
        return ans;
    }
};
```