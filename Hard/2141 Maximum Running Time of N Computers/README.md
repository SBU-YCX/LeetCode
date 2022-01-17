# [2141. Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/)


## Description:

<p>You have <code>n</code> computers. You are given the integer <code>n</code> and a <strong>0-indexed</strong> integer array <code>batteries</code> where the <code>i<sup>th</sup></code> battery can <strong>run</strong> a computer for <code>batteries[i]</code> minutes. You are interested in running <strong>all</strong> <code>n</code> computers <strong>simultaneously</strong> using the given batteries.</p>

<p>Initially, you can insert <strong>at most one battery</strong> into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery <strong>any number of times</strong>. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.</p>

<p>Note that the batteries cannot be recharged.</p>

<p>Return <em>the <strong>maximum</strong> number of minutes you can run all the <code>n</code> computers simultaneously.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2022/01/06/example1-fit.png)
<pre>
<strong>Input:</strong> n = 2, batteries = [3,3,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2022/01/06/example2.png)
<pre>
<strong>Input:</strong> n = 2, batteries = [1,1,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Initially, insert battery 0 into the first computer and battery 2 into the second computer. 
After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer. 
After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
We can run the two computers simultaneously for at most 2 minutes, so we return 2.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= n &lt;= batteries.length &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= batteries[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Suppose <code>sum</code> is the total power of all batteries. In the most ideal case, the answer is <code>sum / n</code> minutes. If the most powerful battery can charge for <code>x</code> minutes and <code> x &gt; sum / n</code>, this battery can charge one computer the whole process by itself. Then, we can find the answer in the remaining batteries and <code>n - 1</code> computers.</p>

<p>Whenever <code>sum / (n - k) &gt;= max(battery)</code>, we can run the remaining <code>n - k</code> computers <code>sum / (n - k)</code> minutes by using batteries evenly. Why? Since we can sort these batteries in descending order and each time use the first <code>n - k</code> batteries to charge remaining computers for <code>1</code> minutes. After <code>x</code> rounds, we must have <code>r &lt; n - k</code> batteries left and all of them are <code>1</code>s. Because if the largest one among these <code>r</code> batteries is larger than <code>1</code>, the previous round would choose it instead of someone with <code>1</code>, which is <code>0</code> now.</p> 


<strong>C++</strong>

```
// Topic     : 2141. Maximum Running Time of N Computers
// Author    : YCX 
// Time      : O(NlogN) 
// Space     : O(N)


class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long sum = accumulate(batteries.begin(), batteries.end(), 0L);
        int m = batteries.size(), k = 0;
        while(batteries[m - 1 - k] > sum / (n - k))
        {
            sum -= batteries[m - 1 - k];
            k++;
        }
        return (sum / (n - k));
    }
};
```
