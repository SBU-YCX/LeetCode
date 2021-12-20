# [2103. Rings and Rods](https://leetcode.com/problems/rings-and-rods/)


## Description:

<p>There are <code>n</code> rings and each ring is either red, green, or blue. The rings are distributed <strong>across ten rods</strong> labeled from <code>0</code> to <code>9</code>.</p>

<p>You are given a string <code>rings</code> of length <code>2n</code> that describes the <code>n rings that are placed onto the rods. Every two characters in <code>rings</code> forms a <strong>color-position pair</strong> that is used to describe each ring where:</p>
<ul>
    <li>The <strong>first</strong> character of the <code>i<sup>th</sup></code> pair denotes the <code>i<sup>th</sup></code> ring's <strong>color</strong> (<code>'R'</code>, <code>'G'</code>, <code>'B'</code>).</li>
    <li>The <strong>second</strong> character of the <code>i<sup>th</sup></code> pair denotes the <strong>rod</strong> that the <code>i<sup>th</sup></code> ring is placed on (<code>'0'</code> to <code>'9'</code>).</li>
</ul>
<p>For example, <code>"R3G2B1"</code> describes <code>n == 3</code> rings: a red ring placed onto the rod labeled 3, a green ring placed onto the rod labeled 2, and a blue ring placed onto the rod labeled 1.</p>

<p>Return <em>the number of rods that have <strong>all three colors</strong> of rings on them.</em></p>


## Examples:

<strong>Example 1:</strong>
<br>![ex1](https://assets.leetcode.com/uploads/2021/11/23/ex1final.png)
<pre>
<strong>Input:</strong> rings = "B0B6G0R6R0R6G9"
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.
</pre>

<strong>Example 2:</strong>
<br>![ex2](https://assets.leetcode.com/uploads/2021/11/23/ex2final.png)
<pre>
<strong>Input:</strong> rings = "B0R0G0R9R0B0G0"
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
- The rod labeled 0 holds 6 rings with all colors: red, green, and blue.
- The rod labeled 9 holds only a red ring.
Thus, the number of rods with all three colors is 1.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> rings = "G4"
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
Only one ring is given. Thus, no rods have all three colors.
</pre>


## Constraints:

<ul>
  <li><code>rings.length == 2 * n</code></li>
  <li><code>1 &lt;= n &lt;= 100</code></li>
  <li><code>rings[i]</code> where <code>i</code> is even is either <code>'R'</code>, <code>'G'</code>, or <code>'B'</code> (<strong>0-indexed</strong>).</li>
  <li><code>rings[i]</code> where <code>i</code> is odd is a digit from <code>'0'</code> to <code>'9'</code> (<strong>0-indexed</strong>).</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We use a <strong>Hash Table</strong> to keep a record of the colors of rings on each rod. Since we only care about the color types, we use a <strong>bitmask</strong> for each rod to represent whether a color appears. </p>


<strong>C++</strong>

```
//  Topic   : 2103. Rings and Rods (https://leetcode.com/problems/rings-and-rods/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length(), m = n / 2, ans = 0;
        unordered_map<int, string> rr;
        for (int i = 0; i < n; i += 2)
        {
            char c = rings[i];
            int p = rings[i + 1] - '0';
            if (!rr.count(p))
                rr[p] = "000";
            if (c == 'B')
                rr[p][0] = '1';
            else if (c == 'G')
                rr[p][1] = '1';
            else
                rr[p][2] = '1';
        }
        for (auto k : rr)
            if (k.second == "111")
                ans++;
        return ans;
    }
};
```
