# [1109. Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)


## Description:

<p>There are <code>n</code> flights that are labeled from <code>1</code> to <code>n</code>.</p>
<p>You are given an array of flight bookings <code>bookings</code>, where <code>bookings[i] = [first<aub>i</aub>, last<aub>i</aub>, seats<aub>i</aub>]</code> represents a booking for flights <code>first<aub>i</aub></code> through <code>last<aub>i</aub></code> (<strong>inclusive</strong>) with <code>seats<aub>i</aub></code> seats reserved for <strong>each flight</strong> in the range.</p>
<p>Return <em>an array <code>answer</code> of length <code>n</code>, where <code>answer[i]</code> is the total number of seats reserved for flight <code>i</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
<strong>Output:</strong> [10,55,45,25,25]
<strong>Explanation:</strong>
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> bookings = [[1,2,10],[2,2,15]], n = 2
<strong>Output:</strong> [10,25]
<strong>Explanation:</strong> 
Flight labels:        1   2
Booking 1 reserved:  10  10
Booking 2 reserved:      15
Total seats:         10  25
Hence, answer = [10,25]
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
  <li><code>1 &lt;= bookings.length &lt;= 2 * 10<sup>4</sup></code></li>
  <li><code>bookings[i].length == 3</code></li>
  <li><code>1 &lt;= first<sub>i</sub> &lt;= last<sub>i</sub> &lt;= n</code></li>
  <li><code>1 &lt;= seats<sub>i</sub> = 10<sup>4</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>For each booking, we just set the seats changes at the start and end flights, then with the help of <strong>Prefix Sum</strong>, we can iteratively update all the flights with all the bookings.</p>


<strong>C++</strong>

```
// Topic     : 1109. Corporate Flight Bookings (https://leetcode.com/problems/corporate-flight-bookings/)
// Author    : YCX
// Time      : O(M + N)
// Space     : O(N)


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m = bookings.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < m; i++)
        {
            ans[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < n)
                ans[bookings[i][1]] -= bookings[i][2];
        }
        for (int i = 1; i < n; i++)
            ans[i] += ans[i - 1];
        return ans;
    }
};
```
