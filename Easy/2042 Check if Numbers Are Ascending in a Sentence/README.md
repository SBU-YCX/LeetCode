# [2042. Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/)


## Description:

<p>A sentence is a list of <strong>tokens</strong> separated by a <strong>single</strong> space with no leading or trailing spaces. Every token is either a <strong>positive number</strong> consisting of digits <code>0-9</code> with no leading zeros, or a <strong>word</strong> consisting of lowercase English letters.</p>
<ul>
  <li>For example, <code>"a puppy has 2 eyes 4 legs"</code> is a sentence with seven tokens: <code>"2"</code> and <code>"4"</code> are numbers and the other tokens such as <code>"puppy"</code> are words.</li>
</ul>
<p>Given a string <code>s</code> representing a sentence, you need to check if <strong>all</strong> the numbers in <code>s</code> are <strong>strictly increasing</strong> from left to right (i.e., other than the last number, <strong>each</strong> number is <strong>strictly smaller</strong> than the number on its <strong>right</strong> in <code>s</code>).</p>
<p>Return <em><code>true</code> if so, or <code>false</code> otherwise.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/09/30/example1.png)</br>
<pre>
<strong>Input:</strong> s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
<strong>Output:</strong> true
<strong>Explanation:</strong> The numbers in s are: 1, 3, 4, 6, 12.
They are strictly increasing from left to right: 1 < 3 < 4 < 6 < 12.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "hello world 5 x 5"
<strong>Output:</strong> false
<strong>Explanation:</strong> The numbers in s are: 5, 5. They are not strictly increasing. 
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/09/30/example3.png)</br>
<pre>
<strong>Input:</strong> s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
<strong>Output:</strong> false
<strong>Explanation:</strong> The numbers in s are: 7, 51, 50, 60. They are not strictly increasing. 
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> s = "4 5 11 26"
<strong>Output:</strong> true
<strong>Explanation:</strong> The numbers in s are: 4, 5, 11, 26.
They are strictly increasing from left to right: 4 < 5 < 11 < 26. 
</pre>


## Constraints:

<ul>
  <li><code>3 &lt;= s.length &lt;= 200</code></li>
  <li><code>s</code> consists of lowercase English letters, spaces, and digits from <code>0</code> to <code>9</code>, inclusive.</li>
  <li>The number of tokens in <code>s</code> is between <code>2</code> and <code>100</code>, inclusive.</li>
  <li>The tokens in <code>s</code> are separated by a single space.</li>
  <li>There are at least <strong>two</strong> numbers in <code>s</code>.</li>
  <li>Each number in <code>s</code> is a <strong>positive</strong> number <strong>less</strong> than <code>100</code>, with no leading zeros.</li>
  <li><code>s</code> contains no leading or trailing spaces.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Greedily</strong> checking each word while keeping track of the previous number <code>p</code>, if the current word represents a number <code>q</code>, check whether it is larger than <code>p</code> and update <code>p</code> with <code>q</code>.</p>


<strong>C++</strong>

```
//  Topic   : 2042. Check if Numbers Are Ascending in a Sentence (https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool areNumbersAscending(string s) {
        s += " ";
        int i = 0, n = s.length(), p = 0;
        while (i < n)
        {
            int j = s.find(' ', i);
            string num = s.substr(i, j - i);
            bool isNum = true;
            for (auto k : num)
                if (k > '9' || k < '0')
                {
                    isNum = false;
                    break;
                }
            if (isNum)
            {
                int q = stoi(num);
                if (q <= p)
                    return false;
                p = q;
            }
            i = j + 1;
        }
        return true;
    }
};
```
