# [2027. Minimum Moves to Convert String](https://leetcode.com/problems/minimum-moves-to-convert-string/)


## Description: 

<p>You are given a string <code>s</code> consisting of <code>n</code> characters which are either <code>'X'</code> or <code>'O'</code>.</p>
<p>A <strong>move</strong> is defined as selecting <strong>three consecutive characters</strong> of <code>s</code> and converting them to <code>'O'</code>. Note that if a move is applied to the character <code>'O'</code>, it will stay the <strong>same</strong>.</p>
<p>Return the <em><strong>minimum</strong> number of moves required</em> so that all the characters of <code>s</code> are converted to <code>'O'</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "XXX"
<strong>Output:</strong> 1
<strong>Explanation:</strong> XXX -> OOO
We select all the 3 characters and convert them in one move.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "XXOX"
<strong>Output:</strong> 2
<strong>Explanation:</strong> XXOX -> OOOX -> OOOO
We select the first 3 characters in the first move, and convert them to 'O'.
Then we select the last 3 characters and convert them so that the final string contains all 'O's.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "OOOO"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no 'X's in s to convert.
</pre>


## Constraints:

<ul>
  <li><code>3 &lt;= s.length &lt;= 1000</code></li>
  <li><code>s[i] is either 'X' or 'O'.</code></li>
</ul>


## Solution: 

<strong>Logical Thinking</strong>
<p>First, we need to reduce the original input string to the smallest substring that is needed to be processed, i.e. we should ignore the <code>'O'</code>s on both sides of the string <code>s</code> until we meet the first <code>'X'</code>s at <code>l</code> and <code>r</code> respectively. Within the substring between <code>l</code> and <code>r</code>, each time we meet an <code>'X'</code>, the answer is increased by 1 and the index <code>l</code> goes forward by 3; otherwise, <code>l</code> goes forward by 1.</p>


<strong>C++</strong>

```
//  Topic   : 2027. Minimum Moves to Convert String (https://leetcode.com/problems/minimum-moves-to-convert-string/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length(), l = 0, r = n - 1, ans = 0;
        while (r >= 0 && s[r] == 'O')
            r--;
        while (l <= r)
        {
            if (s[l] == 'O')
                l++;
            else
            {
                ans += 1;
                l += 3;
            }
        }
        return ans;
    }
};
```
