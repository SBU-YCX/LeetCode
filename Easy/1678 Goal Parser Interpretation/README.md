# [1678. Goal Parser Interpretation](https://leetcode.com/problems/goal-parser-interpretation/)


## Description:

<p>You own a <strong>Goal Parser</strong> that can interpret a string <code>command</code>. The <code>command</code> consists of an alphabet of <code>"G"</code>, <code>"()"</code> and/or <code>"(al)"</code> in some order. The Goal Parser will interpret <code>"G"</code> as the string <code>"G"</code>, <code>"()"</code> as the string <code>"o"</code>, and <code>"(al)"</code> as the string <code>"al"</code>. The interpreted strings are then concatenated in the original order.</p>

<p>Given the string <code>command</code>, return <em>the <strong>Goal Parser</strong>'s interpretation of <code>command</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> command = "G()(al)"
<strong>Output:</strong> "Goal"
<strong>Explanation:</strong> The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> command = "G()()()()(al)"
<strong>Output:</strong> "Gooooal"
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> command = "(al)G(al)()()G"
<strong>Output:</strong> "alGalooG"
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= command.length &lt;= 100</code></li>
    <li><code>command</code> consists of <code>"G"</code>, <code>"()"</code>, and/or <code>"(al)"</code> in some order.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Check each character one-by-one, use a <strong>stack</strong> to store <code>'('</code>, if we enconter a <code>')'</code> and there is <code>'('</code> in the stack, interprete them as a <code>'o'</code>, else if we meet an <code>'a'</code>, pop out one <code>'('</code> from the stack.</p>


<strong>C++</strong>

```
//  Topic   : 1678. Goal Parser Interpretation
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string interpret(string command) {
        string ans = "";
        stack<char> cache;
        for (int i = 0; i < command.length(); i++)
        {
            if (command[i] == 'G')
                ans += command[i];
            else if (command[i] == '(')
                cache.push(command[i]);
            else if (command[i] == ')')
            {
                if (!cache.empty() && cache.top() == '(')
                {
                    ans += 'o';
                    cache.pop();
                }
            }
            else if (command[i] == 'a')
            {
                cache.pop();
                ans += command[i];
            }
            else
                ans += command[i];
            
        }
        return ans;
    }
};
```