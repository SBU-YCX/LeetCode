# [1700. Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)


## Description:

<p>The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers <code>0</code> and <code>1</code> respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.</p>

<p>The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a <strong>stack</strong>. At each step:</p>

<ul>
    <li>If the student at the front of the queue <strong>prefers</strong> the sandwich on the top of the stack, they will <strong>take it</strong> and leave the queue.</li>
    <li>Otherwise, they will <strong>leave it</strong> and go to the queue's end.</li>
</ul>

<p>This continues until none of the queue students want to take the top sandwich and are thus unable to eat.</p>

<p>You are given two integer arrays <code>students</code> and <code>sandwiches</code> where <code>sandwiches[i]</code> is the type of the <code>i<sup>th</sup></code> sandwich in the stack (<code>i = 0</code> is the top of the stack) and <code>students[j]</code> is the preference of the <code>j<sup>th</sup></code> student in the initial queue (<code>j = 0</code> is the front of the queue). Return <em>the number of students that are unable to eat.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> students = [1,1,0,0], sandwiches = [0,1,0,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= students.length, sandwiches.length &lt;= 100</code></li>
    <li><code>students.length == sandwiches.length</code></li>
    <li><code>sandwiches[i]</code> is <code>0</code> or <code>1</code>.</li>
    <li><code>students[i]</code> is <code>0</code> or <code>1</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Suppose there are <code>num_st</code> students prefer <code>1</code> and there are <code>num_sa</code> sandwiches are <code>1</code>s.</p>

<ul>
    <li>if <code>num_st > num_sa</code>, there are <code>num_st - num_sa</code> students who prefers <code>1</code> left, correspondingly, there should be the same number of sandwiches <code>0</code> left. Since the sandwiches are taken in order, we need to find the <code>(num_st - num_sa)<sup>th</sup></code> sandwiches <code>0</code> from right.</li>
    <li>if <code>num_st < num_sa</code>, there are <code>num_sa - num_st</code> sandwiches <code>1</code> left. Since the sandwiches are taken in order, we need to find the <code>(num_sa - num_st)<sup>th</sup></code> sandwiches <code>1</code> from right.</li>
</ul>


<strong>C++</strong>

```
//  Topic   : 1700. Number of Students Unable to Eat Lunch
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int num_st = 0, num_sa = 0;
        for (int i = 0; i < students.size(); i++)
            if (students[i] == 1)
                num_st += 1;
        for (int j = 0; j < sandwiches.size(); j++)
            if (sandwiches[j] == 1)
                num_sa += 1;
        if (num_st > num_sa)
        {
            int num_0 = 0;
            for (int j = sandwiches.size() - 1; j >= 0; j--)
                if (sandwiches[j] == 0)
                {
                    num_0 += 1;
                    if (num_0 == num_st - num_sa)
                        return sandwiches.size() - j;
                }
        }
        else if (num_st < num_sa)
        {
            int num_1 = 0;
            for (int j = sandwiches.size() - 1; j >= 0; j--)
                if (sandwiches[j] == 1)
                {
                    num_1 += 1;
                    if (num_1 == num_sa - num_st)
                        return sandwiches.size() - j;
                }
        }
        return 0;
    }
};
```