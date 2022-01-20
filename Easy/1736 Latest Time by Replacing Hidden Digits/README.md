# [1736. Latest Time by Replacing Hidden Digits](https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/)


## Description:

<p>You are given a string <code>time</code> in the form of <code>hh:mm</code>, where some of the digits in the string are hidden (represented by <code>?</code>).</p>

<p>The valid times are those inclusively between <code>00:00</code> and <code>23:59</code>.</p>

<p>Return <em>the latest valid time you can get from <code>time</code> by replacing the hidden digits.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> time = "2?:?0"
<strong>Output:</strong> "23:50"
<strong>Explanation:</strong> The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> time = "0?:3?"
<strong>Output:</strong> "09:39"
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> time = "1?:22"
<strong>Output:</strong> "19:22"
<strong>Explanation:</strong>
</pre>


## Constraints:

<ul>
    <li><code>time</code> is in the format <code>hh:mm</code>.</li>
    <li>It is guaranteed that you can produce a valid time from the given string.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Fill the <code>'?'</code> from left to right according to the given numbers and rules.</p>

<ul>
    <li>For hours, <code>hh</code> will be <code>[00, 23]</code>, so
        <ul>
            <li>we try to make <code>time[0] == '2'</code> unless <code>time[1]</code> is given and <code>time[1] &gt; '3'</code></li>
            <li>after <code>time[0]</code> fixed, fill <code>time[1]</code> accordingly</li>
        </ul>
    </li>
    <li>For minutes, <code>mm</code> must be within <code>[00, 59]</code> without exceptions, so the maximum is always <code>59</code></li>
</ul>


<strong>C++</strong>

```
//  Topic   : 1736. Latest Time by Replacing Hidden Digits
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?')
        {
            if (time[1] >= '4' && time[1] <= '9')
                time[0] = '1';
            else
                time[0] = '2';
        }
        if (time[1] == '?')
        {
            if (time[0] == '2')
                time[1] = '3';
            else
                time[1] = '9';
        }
        if (time[3] == '?')
            time[3] = '5';
        if (time[4] == '?')
            time[4] = '9';
        return time;
    }
};
```