# [1812. Determine Color of a Chessboard Square](https://leetcode.com/problems/determine-color-of-a-chessboard-square/)


## Description:

<p>You are given coordinates, a string that represents the coordinates of a square of the chessboard. Below is a chessboard for your reference.</p>

<br/>![ex](https://assets.leetcode.com/uploads/2021/02/19/screenshot-2021-02-20-at-22159-pm.png)

<p>Return <em><code>true</code> if the square is white, and <code>false</code> if the square is black.</em></p>

<p>The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first, and the number second.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> coordinates = "a1"
<strong>Output:</strong> false
<strong>Explanation:</strong> From the chessboard above, the square with coordinates "a1" is black, so return false.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> coordinates = "h3"
<strong>Output:</strong> true
<strong>Explanation:</strong> From the chessboard above, the square with coordinates "h3" is white, so return true.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> coordinates = "c7"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>coordinates.length == 2</code></li>
    <li><code>'a' &lt;= coordinates[0] &lt;= 'h'</code></li>
    <li><code>'1' &lt;= coordinates[1] &lt;= '8'</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>According to the figure, the following cells are white:</p>

<ul>
	<li>Odd row (1-indexed) and even column (a-indexed)</li>
	<li>Even row and odd column</li>
</ul>

<p>so, we can directly obtain the color of the square cell according to its coordinates.</p>


<strong>C++</strong>

```
//  Topic   : 1812. Determine Color of a Chessboard Square
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a';
        int y = coordinates[1] - '0';
        return ((x + y) % 2 == 0);
    }
};
```