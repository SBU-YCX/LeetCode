# [2024. Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)


## Description:

<p>A teacher is writing a test with <code>n</code> true/false questions, with <code>'T'</code> denoting true and <code>'F'</code> denoting false. He wants to confuse the students by <strong>maximizing</strong> the number of <strong>consecutive</strong> questions with the <strong>same</strong> answer (multiple trues or multiple falses in a row).</p>
<p>You are given a string <code>answerKey</code>, where <code>answerKey[i]</code> is the original answer to the <code>i<sup>th</sup></code> question. In addition, you are given an integer <code>k</code>, the maximum number of times you may perform the following operation:</p>
<ul>
    <li>Change the answer key for any question to <code>'T'</code> or <code>'F'</code> (i.e., set <code>answerKey[i]</code> to <code>'T'</code> or <code>'F'</code>).</li>
</ul>
<p>Return <em>the <strong>maximum</strong> number of consecutive <code>'T'</code>s or <code>'F'</code>s in the answer key after performing the operation at most <code>k</code> times.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> answerKey = "TTFF", k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> answerKey = "TFFT", k = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> answerKey = "TTFTTFTT", k = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
In both cases, there are five consecutive 'T's.
</pre>


## Constraints:

<ul>
  <li><code>n == answerKey.length</code></li>
  <li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
  <li><code>answerKey[i]</code> is either <code>'T'</code> or <code>'F'</code></li>
  <li><code>1 &lt;= k &lt;= n</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can divide this problem into two subproblems, one is finding the maximum number of consecutive <code>'T'</code>s by converting at most <code>k</code> <code>'F'</code>s, the other is finding the maximum number of consecutive <code>'F'</code>s by converting at most <code>k</code> <code>'T'</code>s. Each subproblem can be solved by sliding window, and the global answer is the maximum between these two local answers.</p>


<strong>C++</strong>

```
//  Topic   ：2024. Maximize the Confusion of an Exam (https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length(), l = -1, r = 0, m = 0, ans = 0;
        while (r < n)
        {
            if (answerKey[r] == 'F')
                m += 1;
            while (m > k)
            {
                l++;
                if (answerKey[l] == 'F')
                    m -= 1;
            }
            ans = max<int>(ans, r - l);
            r++;
        }
        l = -1, r = 0, m = 0;
        while (r < n)
        {
            if (answerKey[r] == 'T')
                m += 1;
            while (m > k)
            {
                l++;
                if (answerKey[l] == 'T')
                    m -= 1;
            }
            ans = max<int>(ans, r - l);
            r++;
        }
        return ans;
    }
};
```
