# [2075. Decode the Slanted Ciphertext](https://leetcode.com/problems/decode-the-slanted-ciphertext/)


## Description:

<p>A string <code>originalText</code> is encoded using a <strong>slanted transposition cipher</strong> to a string <code>encodedText</code> with the help of a matrix having a <strong>fixed number of rows</strong> <code>rows</code>.</p>

<p><code>originalText</code> is placed first in a top-left to bottom-right manner.</p>

<br/>![original](https://assets.leetcode.com/uploads/2021/11/07/exa11.png)</br>

<p>The blue cells are filled first, followed by the red cells, then the yellow cells, and so on, until we reach the end of <code>originalText</code>. The arrow indicates the order in which the cells are filled. All empty cells are filled with <code>' '</code>. The number of columns is chosen such that the rightmost column will <strong>not be empty</strong> after filling in <code>originalText</code>.</p>

<p><code>encodedText</code> is then formed by appending all characters of the matrix in a row-wise fashion.</p>

<br>![encoded](https://assets.leetcode.com/uploads/2021/11/07/exa12.png)

<p>The characters in the blue cells are appended first to <code>encodedText</code>, then the red cells, and so on, and finally the yellow cells. The arrow indicates the order in which the cells are accessed.</p>

<p>For example, if <code>originalText = "cipher"</code> and <code>rows = 3</code>, then we encode it in the following manner:</p>

<br>![ex1](https://assets.leetcode.com/uploads/2021/10/25/desc2.png)

<p>The blue arrows depict how <code>originalText</code> is placed in the matrix, and the red arrows denote the order in which <code>encodedText</code> is formed. In the above example, <code>encodedText = "ch ie pr"</code>.</p>

<p>Given the encoded string <code>encodedText</code> and number of rows <code>rows</code>, return <em>the original string <code>originalText</code>.</em></p>

<p><strong>Note:</strong> <code>originalText</code> <strong>does not</strong> have any trailing spaces <code>' '</code>. The test cases are generated such that there is only one possible <code>originalText</code>.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> encodedText = "ch   ie   pr", rows = 3
<strong>Output:</strong> "cipher"
<strong>Explanation:</strong> This is the same example described in the problem description.
</pre>

<strong>Example 2:</strong>
<br>![ex2](https://assets.leetcode.com/uploads/2021/10/26/exam1.png)
<pre>
<strong>Input:</strong> encodedText = "iveo    eed   l te   olc", rows = 4
<strong>Output:</strong> "i love leetcode"
<strong>Explanation:</strong> The figure above denotes the matrix that was used to encode originalText. 
The blue arrows show how we can find originalText from encodedText.
</pre>

<strong>Example 3:</strong>
<br>![ex3](https://assets.leetcode.com/uploads/2021/10/26/eg2.png)
<pre>
<strong>Input:</strong> encodedText = "coding", rows = 1
<strong>Output:</strong> "coding"
<strong>Explanation:</strong> Since there is only 1 row, both originalText and encodedText are the same.
</pre>

<strong>Example 4:</strong>
<br>![ex4](https://assets.leetcode.com/uploads/2021/10/26/exam3.png)
<pre>
<strong>Input:</strong> encodedText = " b  ac", rows = 2
<strong>Output:</strong> " abc"
<strong>Explanation:</strong> originalText cannot have trailing spaces, but it may be preceded by one or more spaces.
</pre>


## Constraints:

<ul>
  <li><code>0 &lt;= encodedText.length &lt;= 10<sup>6</sup></code></li>
  <li><code>encodedText</code> consists of lowercase English letters and <code>' '</code> only.</li>
  <li><code>encodedText</code> is a valid encoding of some <code>originalText</code> that <strong>does not</strong> have trailing spaces.</li>
  <li><code>1 &lt;= rows &lt;= 1000</code></li>
  <li>The testcases are generated such that there is <strong>only one</strong> possible <code>originalText</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Actually, from the figure, we know that for the <code>i<sup>th</sup></code> row, the string starts from the <code>i<sup>th</sup></code> column. As the string length <code>l</code> and the rows number <code>m</code> are given, we know the total columns number is <code>n = l / m</code>. So we can iterate along the first row, and for each column index, add the characters one-by-one to the result string in the right-down direction. Finally, right-most white spaces need to be removed.</p>

 
<strong>C++</strong>

```
//  Topic   ：2075. Decode the Slanted Ciphertext (https://leetcode.com/problems/decode-the-slanted-ciphertext/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(NN)


class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l = encodedText.length(), m = rows, n = l / m, k = 0;
        string ans = "";
        for (int c = 0; c < n; c++)
            for (int r = c; r < l; r += (n + 1))
                ans += encodedText[r];
        int p = ans.length() - 1;
        while (p >= 0 && ans[p] == ' ')
            p--;
        return ans.substr(0, p + 1);
    }
};
```
