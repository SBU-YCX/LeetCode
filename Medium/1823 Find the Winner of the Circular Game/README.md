# [1823. Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)

## Description:

<p>There are <code>n</code> friends that are playing a game. The friends are sitting in a circle and are numbered from <code>1</code> to <code>n</code> in <strong>clockwise order</strong>. More formally, moving clockwise from the <code>i<sup>th</sup></code> friend brings you to the <code>(i+1)<sup>th</sup></code> friend for <code>1 &lt;= i &lt; n</code>, and moving clockwise from the <code>n<sup>th</sup></code> friend brings you to the <code>1<sup>st</sup></code> friend.</p>

<p>The rules of the game are as follows:</p>
<ol>
    <li><strong>Start</strong> at the <code>1<sup>st</sup></code> friend.</li>
    <li>Count the next <code>k</code> friends in the clockwise direction <strong>including</strong> the friend you started at. The counting wraps around the circle and may count some friends more than once.</li>
    <li>The last friend you counted leaves the circle and loses the game.</li>
    <li>If there is still more than one friend in the circle, go back to step <code>2</code> <strong>starting</strong> from the friend <strong>immediately clockwise</strong> of the friend who just lost and repeat.</li>
    <li>Else, the last friend in the circle wins the game.</li>
</ol>
<p>Given the number of friends, <code>n</code>, and an integer <code>k</code>, return <em>the winner of the game.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> n = 5, k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> n = 6, k = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= k &lt;= n &lt;= 500</code></li>
</ul>


## Solution1:

<strong>Logical Thinking</strong>
<p>It is a typical [Josephus problem](https://en.wikipedia.org/wiki/Josephus_problem), and we can solve it using recursion. Specifically, if <code>f[i - 1]</code> leaves at the <code>(i - 1)<sup>th</sup></code> round, then at the <code>i<sup>th</sup></code> round, the id of the friend who should leave is <code>(f[i - 1] + k) mod n</code>. The edge case is, when <code>n == 1</code>, then the remaining one should be friend <code>0</code> (0-indexed).</p>


<strong>C++</strong>

```
//  Topic   ：1823. Find the Winner of the Circular Game (https://leetcode.com/problems/find-the-winner-of-the-circular-game/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = findAns(n, k) + 1;
        return ans;
    }
    
private: 
    int findAns(int n, int k) {
        if (n == 1)
            return 0;
        return (findAns(n - 1, k) + k) % n;
    }
};
```


## Solution2: (Improved)

<strong>Logical Thinking</strong>
<p>When <code>k</code> is small and <code>n</code> is large, we will waste a lot of time counting them one by one, instead, we can let Friend <code>k</code>, <code>2 * k</code>, ..., <code><lfloor>n / k<rfloor> * k</code> leave at one step until the remaining number of friends is smaller than <code>k</code>, formally:</p>
\Huge
\begin{align*}
x&=1\\
x+y&=2\\
P&=\begin{bmatrix}p_1\\p_2\end{bmatrix}
\end{align*}

<strong>C++</strong>

```
//  Topic   ：1823. Find the Winner of the Circular Game (https://leetcode.com/problems/find-the-winner-of-the-circular-game/)
//  Author  : YCX
//  Time    : O(K * logN)
//  Space   : O(1)


class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = findAns(n, k) + 1;
        return ans;
    }
    
private: 
    int findAns(int n, int k) {
        if (n == 1)
            return 0;
        return (findAns(n - 1, k) + k) % n;
    }
};
```