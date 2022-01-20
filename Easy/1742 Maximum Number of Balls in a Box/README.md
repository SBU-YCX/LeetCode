# [1742. Maximum Number of Balls in a Box](https://leetcode.com/problems/maximum-number-of-balls-in-a-box/)


## Description:

<p>You are working in a ball factory where you have <code>n</code> balls numbered from <code>lowLimit</code> up to <code>highLimit</code> <strong>inclusive</strong> (i.e., <code>n == highLimit - lowLimit + 1</code>), and an infinite number of boxes numbered from <code>1</code> to <code>infinity</code>.</p>

<p>Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball number <code>321</code> will be put in the box number <code>3 + 2 + 1 = 6</code> and the ball number <code>10</code> will be put in the box number <code>1 + 0 = 1</code>.</p>

<p>Given two integers <code>lowLimit</code> and <code>highLimit</code>, return <em>the number of balls in the box with the most balls.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> lowLimit = 1, highLimit = 10
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
Box 1 has the most number of balls with 2 balls.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> lowLimit = 5, highLimit = 15
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
Boxes 5 and 6 have the most number of balls with 2 balls in each.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> lowLimit = 19, highLimit = 28
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
Box 10 has the most number of balls with 2 balls.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= lowLimit &lt;= highLimit &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since <code>highLimit &lt; 10<sup>5</sup></code>, the maximum possible number of the box is <code>9 + 9 + 9 + 9 + 9 = 45</code>, so we use a vector to store the counts.</p>

<p><strong>Note: </strong> it is faster than map, and use less memory</p>

<strong>C++</strong>

```
//  Topic   : 1742. Maximum Number of Balls in a Box
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> count(46, 0);
        for (int i = lowLimit; i <= highLimit; i++)
            count[box(i)] += 1;
        int ans = 0;
        for (int j = 1; j <= 45; j++)
            ans = max<int>(ans, count[j]);
        return ans;
    }
    
    int box(int ball) {
        int ans = 0;
        while (ball != 0)
        {
            ans += (ball % 10);
            ball /= 10;
        }
        return ans;
    }
};
```