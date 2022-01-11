# [1880. Check if Word Equals Summation of Two Words](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/)


## Description:

<p>The <strong>letter value</strong> of a letter is its position in the alphabet <strong>starting from 0</strong> (i.e. <code>'a' -> 0</code>, <code>'b' -> 1</code>, <code>'c' -> 2</code>, etc.).</p>

<p>The <strong>numerical value</strong> of some string of lowercase English letters <code>s</code> is the <strong>concatenation</strong> of the <strong>letter values</strong> of each letter in <code>s</code>, which is then <strong>converted</strong> into an integer.</p>

<ul>
    <li>For example, if <code>s = "acb"</code>, we concatenate each letter's letter value, resulting in <code>"021"</code>. After converting it, we get <code>21</code>.</li>
</ul>

<p>You are given three strings <code>firstWord</code>, <code>secondWord</code>, and <code>targetWord</code>, each consisting of lowercase English letters <code>'a'</code> through <code>'j'</code> <strong>inclusive</strong>.</p>

<p>Return <em><code>true</code> if the <strong>summation</strong> of the <strong>numerical values</strong> of <code>firstWord</code> and <code>secondWord</code> equals the <strong>numerical value</strong> of <code>targetWord</code>, or <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> firstWord = "acb", secondWord = "cba", targetWord = "cdb"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The numerical value of firstWord is "acb" -> "021" -> 21.
The numerical value of secondWord is "cba" -> "210" -> 210.
The numerical value of targetWord is "cdb" -> "231" -> 231.
We return true because 21 + 210 == 231.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> firstWord = "aaa", secondWord = "a", targetWord = "aab"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aab" -> "001" -> 1.
We return false because 0 + 0 != 1.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aaaa" -> "0000" -> 0.
We return true because 0 + 0 == 0.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= firstWord.length, secondWord.length, targetWord.length &lt;= 8</code></li>
    <li><code>firstWord</code>, <code>secondWord</code>, and <code>targetWord</code> consist of lowercase English letters from <code>'a'</code> to <code>'j'</code> <strong>inclusive</strong>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Convert each word to its numerical value and check if the values satisfy the condition.</p>


<strong>C++</strong>

```
//  Topic   : 1880. Check if Word Equals Summation of Two Words
//  Author  : YCX
//  Time    : O(N1 + N2 + N3)
//  Space   : O(1)


class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < firstWord.length(); i++)
            a = a * 10 + (firstWord[i] - 'a');
        for (int j = 0; j < secondWord.length(); j++)
            b = b * 10 + (secondWord[j] - 'a');
        for (int k = 0; k < targetWord.length(); k++)
            c = c * 10 + (targetWord[k] - 'a');
        return (a + b == c);
    }
};
```