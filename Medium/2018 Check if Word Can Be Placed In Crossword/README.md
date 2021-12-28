# [2018. Check if Word Can Be Placed In Crossword](https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/)


## Description:

<p>You are given an <code>m x n</code> matrix <code>board</code>, representing the <strong>current</strong> state of a crossword puzzle. The crossword contains lowercase English letters (from solved words), <code>' '</code> to represent any <strong>empty</strong> cells, and <code>'#'</code> to represent any <strong>blocked</strong> cells.</p>

<p>A word can be placed <strong>horizontally</strong> (left to right <strong>or</strong> right to left) or <strong>vertically</strong> (top to bottom <strong>or</strong> bottom to top) in the board if:</p>

<ul>
    <li>It does not occupy a cell containing the character <code>'#'</code>.</li>
    <li>The cell each letter is placed in must either be <code>' '</code> (empty) or <strong>match</strong> the letter already on the <code>board</code>.</li>
    <li>There must not be any empty cells <code>' '</code> or other lowercase letters <strong>directly left or right</strong> of the word if the word was placed <strong>horizontally</strong>.</li>
    <li>There must not be any empty cells <code>' '</code> or other lowercase letters <strong>directly above or below</strong> the word if the word was placed <strong>vertically</strong>.</li>
<ul>

<p>Given a string <code>word</code>, return <em><code>true</code> if word can be placed in <code>board</code>, or <code>false</code> <strong>otherwise</strong>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/04/crossword-ex1-1.png)
<pre>
<strong>Input:</strong> board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The word "abc" can be placed as shown above (top to bottom).
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/10/04/crossword-ex2-1.png)
<pre>
<strong>Input:</strong> board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
It is impossible to place the word because there will always be a space/letter above or below it.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/10/04/crossword-ex3-1.png)
<pre>
<strong>Input:</strong> board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
<strong>Output:</strong> true
<strong>Explanation:</strong>
The word "ca" can be placed as shown above (right to left). 
</pre>


## Constraints:

<ul>
    <li><code>m == board.length</code></li>
    <li><code>n == board[i].length</code></li>
    <li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
    <li><code>board[i][j]</code> will be <code>' '</code>, <code>'#'</code>, or a lowercase English letter.</li>
    <li><code>1 &lt;= word.length &lt;= max(m, n)</code></li>
    <li><code>word</code> will contain only lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the filling process.</p>


<strong>C++</strong>

```
//  Topic   ：2018. Check if Word Can Be Placed In Crossword (https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(M * N)


class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> boardT(n, vector<char>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                boardT[j][i] = board[i][j];
        string rword = string(word.rbegin(), word.rend());
        return check(board, word) || check(board, rword) || check(boardT, word) || check(boardT, rword);
    }
    
private: 
    bool check(vector<vector<char>>& board, string& word)
    {
        int m = board.size(), n = board[0].size(), l = word.length();
        vector<vector<int>> matched(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (j == 0 || board[i][j - 1] == '#' || matched[i][j - 1] != -1)
                {
                    int k = (j == 0) ? 0 : (matched[i][j - 1] + 1);
                    if (board[i][j] == ' ' || board[i][j] == word[k])
                    {
                        if (k == l - 1)
                        {
                            if (j == n - 1 || board[i][j + 1] == '#')
                                return true;
                        }
                        else
                            matched[i][j] = k;
                    }
                }
        return false;
    }
    
};
```