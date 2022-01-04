# [2011. Final Value of Variable After Performing Operations](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/)


## Description:

<p>There is a programming language with only <strong>four</strong> operations and <strong>one</strong> variable <code>X</code>:</p>

<ul>
    <li><code>++X</code> and <code>X++</code> <strong>increments</strong> the value of the variable <code>X</code> by <code>1</code>.</li>
    <li><code>--X</code> and <code>X--</code> <strong>decrements</strong> the value of the variable <code>X</code> by <code>1</code>.</li>
</ul>

<p>Initially, the value of <code>X</code> is <code>0</code>.</p>

<p>Given an array of strings <code>operations</code> containing a list of operations, return <em>the <strong>final</strong> value of <code>X</code> after performing all the operations.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> operations = ["--X","X++","X++"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> operations = ["++X","++X","X++"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> operations = ["X++","++X","--X","X--"]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= operations.length &lt;= 100</code></li>
    <li><code>operations[i]</code> will be either <code>"++X"</code>, <code>"X++"</code>, <code>"--X"</code>, or <code>"X--"</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p><strong>Simulate</strong> the whole process. When we check each operation <code>operations[i]</code>, we only need to care about the middle character, i.e., <code>operations[i][1]</code>, because no matter <code>"X++"</code> or <code>"++X"</code>, the middle character is <code>"+"</code>, similarly, <code>"X--"</code> and <code>"--X"</code> share <code>"-"</code> as the middle character.</p>


<strong>C++</strong>

```
//  Topic   : 2011. Final Value of Variable After Performing Operations
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0, m = operations.size();
        for (int i = 0; i < m; i++)
        {
            if (operations[i][1] == '+')
                ans++;
            else
                ans--;
        }
        return ans;
    }
};
```
