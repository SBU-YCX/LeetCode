# [2109. Adding Spaces to a String](https://leetcode.com/problems/adding-spaces-to-a-string/)


## Description:

<p>You are given a <strong>0-indexed</strong> string <code>s</code> and a <strong>0-indexed</strong> integer array <code>spaces</code> that describes the indices in the original string where spaces will be added. Each space should be inserted <strong>before</strong> the character at the given index.
<ul>
    <li>For example, given <code>s = "EnjoyYourCoffee"</code> and <code>spaces = [5, 9]</code>, we place spaces before <code>'Y'</code> and <code>'C'</code>, which are at indices <code>5</code> and <code>9</code> respectively. Thus, we obtain <code>"Enjoy Your Coffee"</code>.</li>
</ul>
<p>Return <em>the modified string <strong>after</strong> the spaces have been added.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
<strong>Output:</strong> "Leetcode Helps Me Learn"
<strong>Explanation:</strong>
The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
We then place spaces before those characters.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s = "icodeinpython", spaces = [1,5,7,9]
<strong>Output:</strong> "i code in py thon"
<strong>Explanation:</strong> 
The indices 1, 5, 7, and 9 correspond to the underlined characters in "icodeinpython".
We then place spaces before those characters.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s = "spacing", spaces = [0,1,2,3,4,5,6]
<strong>Output:</strong> " s p a c i n g"
<strong>Explanation:</strong> 
We are also able to place spaces before the first character of the string.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
  <li><code>s</code> consists only of lowercase and uppercase English letters.</li>
  <li><code>1 &lt;= spaces.length &lt;= 3 * 10<sup>5</sup></code></li>
  <li><code>0 &lt;= spaces[i] &lt;= s.length - 1</code></li>
  <li>All the values of <code>spaces</code> are <strong>strictly increasing</strong>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use <storng>Two Pointers</strong>, <code>i</code> for <code>s</code> and <code>j</code> for <code>spaces</code>, if <code>i == spaces[j]</code>, add an extra <code>' '</code> to the answer string, and move <code>j</code> forward.</p>

 
<strong>C++</strong>

```
//  Topic   ：2109. Adding Spaces to a String (https://leetcode.com/problems/adding-spaces-to-a-string/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0, j = 0, m = s.length(), n = spaces.size();
        while (i < m)
        {
            if (j < n && i == spaces[j])
            {
                ans += ' ';
                j++;
            }
            ans += s[i];
            i++;
        }
        return ans;
    }
};
```
