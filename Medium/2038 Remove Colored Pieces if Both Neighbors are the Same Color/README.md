# [2038. Remove Colored Pieces if Both Neighbors are the Same Color](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/)


## Description:

<p>There are <code>n</code> pieces arranged in a line, and each piece is colored either by <code>'A'</code> or by <code>'B'</code>. You are given a string <code>colors</code> of length <code>n</code> where <code>colors[i]</code> is the color of the <code>i<sup>th</sup></code> piece.</p>
<p>Alice and Bob are playing a game where they take <strong>alternating turns</strong> removing pieces from the line. In this game, Alice moves <strong>first</strong>.</p>
<ul>
  <li>Alice is only allowed to remove a piece colored <code>'A'</code> if <strong>both its neighbors</strong> are also colored <code>'A'</code>. She is <strong>not allowed</strong> to remove pieces that are colored <code>'B'</code>.</li>
  <li>Bob is only allowed to remove a piece colored <code>'B'</code> if <strong>both its neighbors</strong> are also colored <code>'B'</code>. He is <strong>not allowed</strong> to remove pieces that are colored <code>'A'</code>.</li>
  <li>Alice and Bob <strong>cannot</strong> remove pieces from the edge of the line.</li>
  <li>If a player cannot make a move on their turn, that player <strong>loses</strong> and the other player <strong>wins</strong>.</li>
</ul>
<p>Assuming Alice and Bob play optimally, return <em><code>true</code> if Alice wins, or return <code>false</code> if Bob wins.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> colors = "AAABABB"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
AAABABB -> AABABB
Alice moves first.
She removes the second 'A' from the left since that is the only 'A' whose neighbors are both 'A'.

Now it's Bob's turn.
Bob cannot make a move on his turn since there are no 'B's whose neighbors are both 'B'.
Thus, Alice wins, so return true.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> colors = "AA"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
Alice has her turn first.
There are only two 'A's and both are on the edge of the line, so she cannot move on her turn.
Thus, Bob wins, so return false.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> colors = "ABBBBBBBAAA"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
ABBBBBBBAAA -> ABBBBBBBAA
Alice moves first.
Her only option is to remove the second to last 'A' from the right.

ABBBBBBBAA -> ABBBBBBAA
Next is Bob's turn.
He has many options for which 'B' piece to remove. He can pick any.

On Alice's second turn, she has no more pieces that she can remove.
Thus, Bob wins, so return false.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= colors.length &lt;= 10<sup>5</sup></code></li>
  <li><code>colors</code> consists of only the letters <code>'A'</code> and <code>'B'</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Actually, we only need to go through the whole line and count the numbers of <code>'A'</code> and <code>'B'</code> whose neighbors are the same as themselves. If such <code>'A'</code>s are more, Alice wins; otherwise, Bob wins.</p>

 
<strong>C++</strong>

```
//  Topic   ：2038. Remove Colored Pieces if Both Neighbors are the Same Color (https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length(), nA = 0, nB = 0, l = 0;
        for (int r = 1; r <= n; r++)
        {
            if (r == n || colors[r] != colors[l])
            {
                if (colors[l] == 'A')
                    nA += max<int>(r - l - 2, 0);
                else
                    nB += max<int>(r - l - 2, 0);
                l = r;
            }
        }
        return nA > nB;
    }
};
```
