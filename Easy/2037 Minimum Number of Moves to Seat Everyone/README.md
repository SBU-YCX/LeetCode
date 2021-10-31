# [2037. Minimum Number of Moves to Seat Everyone](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/)


## Description:

<p>There are <code>n</code> seats and <code>n</code> students in a room. You are given an array <code>seats</code> of length <code>n</code>, where <code>seats[i]</code> is the position of the <code>i<sup>th</sup></code> seat. You are also given the array <code>students</code> of length <code>n</code>, where <code>students[j]</code> is the position of the <code>j<sup>th</sup></code> student.</p>
<p>You may perform the following move any number of times:</p>
<ul>
  <li>Increase or decrease the position of the <code>i<sup>th</sup></code> student by <code>1</code> (i.e., moving the <code>i<sup>th</sup></code> student from position <code>x</code> to <code>x + 1</code> or <code>x - 1</code>)</li>
</ul>
<p>Return <em>the <strong>minimum number of moves</strong> required to move each student to a seat such that no two students are in the same seat.</em></p>
<p>Note that there may be multiple seats or students in the <strong>same</strong> position at the beginning.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> seats = [3,1,5], students = [2,7,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The students are moved as follows:
- The first student is moved from from position 2 to position 1 using 1 move.
- The second student is moved from from position 7 to position 5 using 2 moves.
- The third student is moved from from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> seats = [4,1,5,9], students = [1,3,2,6]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The students are moved as follows:
- The first student is not moved.
- The second student is moved from from position 3 to position 4 using 1 move.
- The third student is moved from from position 2 to position 5 using 3 moves.
- The fourth student is moved from from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used. 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> seats = [2,2,6,6], students = [1,3,2,6]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The students are moved as follows:
- The first student is moved from from position 1 to position 2 using 1 move.
- The second student is moved from from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used. 
</pre>


## Constraints:

<ul>
  <li><code>n == seats.length == students.length</code></li>
  <li><code>1 &lt;= n &lt;= 100</code></li>
  <li><code>1 &lt;= seats[i], students[j] &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>In order to obtain the minimum number of moves, we need to map the student with the smallest index to the seat with the smallest index, and then the next smallest pair and so on. So we <storng>Sort</strong> both <code>seats</code> and <code>students</code>, and match them one by one.</p>


<strong>C++</strong>

```
//  Topic   : 2037. Minimum Number of Moves to Seat Everyone (https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = seats.size(), ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(seats[i] - students[i]);
        return ans;
    }
};
```
