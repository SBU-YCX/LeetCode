# [1854. Maximum Population Year](https://leetcode.com/problems/maximum-population-year/)


## Description:

<p>You are given a 2D integer array <code>logs</code> where each <code>logs[i] = [birth<sub>i</sub>, death<sub>i</sub>]</code> indicates the birth and death years of the <code>i<sup>th</sup></code> person.</p>

<p>The <strong>population</strong> of some year <code>x</code> is the number of people alive during that year. The <code>i<sup>th</sup> person is counted in year <code>x</code>'s population if <code>x</code> is in the <strong>inclusive</strong> range <code>[birth<sub>i</sub>, death<sub>i</sub> - 1]</code>. Note that the person is <strong>not</strong> counted in the year that they die.</code>

<p>Return <em>the <strong>earliest</strong> year with the <strong>maximum population</strong>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> logs = [[1993,1999],[2000,2010]]
<strong>Output:</strong> 1993
<strong>Explanation:</strong> The maximum population is 1, and 1993 is the earliest year with this population.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> logs = [[1950,1961],[1960,1971],[1970,1981]]
<strong>Output:</strong> 1960
<strong>Explanation:</strong> The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [3,4,5,6,7,8]
<strong>Output:</strong> 480
<strong>Explanation:</strong> The sum of all XOR totals for every subset is 480.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= logs.length &lt;= 100</code></li>
    <li><code>1950 &lt;= birth<sub>i</sub> &lt; death<sub>i</sub> &lt;= 2050</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a vector <code>population</code> to keep the track of population of each year. For each person <code>i</code>, increase the population by <code>1</code> at <code>logs[i][0]</code> and decrease the population by <code>1</code> at <code>logs[i][1]</code>. Use <strong>line sweep</strong> to accumulate the population.</p>


<strong>C++</strong>

```
//  Topic   : 1854. Maximum Population Year
//  Author  : YCX
//  Time    : O(N + 100)
//  Space   : O(100)


class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(101, 0);
        for (int i = 0; i < logs.size(); i++)
        {
            population[logs[i][0] - 1950] += 1;
            population[logs[i][1] - 1950] -= 1;
        }
        int ans = 1950, num = population[0];
        for (int i = 1; i < population.size(); i++)
        {
            population[i] += population[i - 1];
            if (population[i] > num)
            {
                num = population[i];
                ans = 1950 + i;
            }
        }
        return ans;
    }
};
```