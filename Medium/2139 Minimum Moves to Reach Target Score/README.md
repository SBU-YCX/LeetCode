# [2139. Minimum Moves to Reach Target Score](https://leetcode.com/problems/minimum-moves-to-reach-target-score/)


## Description:

<p>You are playing a game with integers. You start with the integer <code>1</code> and you want to reach the integer <code>target</code>.</p>

<p>In one move, you can either:</p>

<ul>
    <li><strong>Increment</strong> the current integer by one (i.e., <code>x = x + 1</code>).</li>
    <li><strong>Double</strong> the current integer (i.e., <code>x = 2 * x</code>).</li>
</ul>

<p>You can use the <strong>increment</strong> operation <strong>any</strong> number of times, however, you can only use the <strong>double</strong> operation <strong>at most</strong> <code>maxDoubles</code> times.</p>

<p>Given the two integers <code>target</code> and <code>maxDoubles</code>, return <em>the minimum number of moves needed to reach <code>target</code> starting with <code>1</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> target = 5, maxDoubles = 0
<strong>Output:</strong> 4
<strong>Explanation:</strong> Keep incrementing by 1 until you reach target.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> target = 19, maxDoubles = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> Initially, x = 1
Increment 3 times so x = 4
Double once so x = 8
Increment once so x = 9
Double again so x = 18
Increment once so x = 19
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> target = 10, maxDoubles = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong> Initially, x = 1
Increment once so x = 2
Double once so x = 4
Increment once so x = 5
Double again so x = 10
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
    <li><code>0 &lt;= maxDoubles &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can start from <code>target</code> and go back to <code>1</code>, we can always do the division first except:</p>

<ul>
    <li>the current <code>x</code> is odd</li>
    <li>we have done the division <code>maxDoubles</code> times</li>
</ul> 

<p>We can take an example to illustrate the reason for which we always consider division first. Suppose <code>x == 2 * y == 4 * z</code> and <code>maxDoubles == 1</code>, if we do the division first, we only need <code>1 + z</code> operations from <code>x</code> to <code>z</code>; otherwise, we need <code>1 + y == 1 + 2 * z</code> operations, which is more than the first case.</p>


<strong>C++</strong>

```
//  Topic   : 2139. Minimum Moves to Reach Target Score
//  Author  : YCX
//  Time    : O(logN)
//  Space   : O(1)


class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target != 1)
        {
            if (maxDoubles == 0)
            {
                ans += (target - 1);
                break;
            }
            if (target % 2 == 1)
            {
                target -= 1;
                ans++;
            }
            else
            {
                target /= 2;
                ans++;
                maxDoubles--;
            }
        }
        return ans;
    }
};
```