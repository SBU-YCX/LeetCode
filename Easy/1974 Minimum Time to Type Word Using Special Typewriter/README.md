# [1974. Minimum Time to Type Word Using Special Typewriter](https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/)


## Description:

<p>There is a special typewriter with lowercase English letters <code>'a'</code> to <code>'z'</code> arranged in a <strong>circle</strong> with a <strong>pointer</strong>. A character can <strong>only</strong> be typed if the pointer is pointing to that character. The pointer is <strong>initially</strong> pointing to the character <code>'a'</code>.</p>

<br/>![ex](https://assets.leetcode.com/uploads/2021/07/31/chart.jpg)

<p>Each second, you may perform one of the following operations:</p>

<ul>
    <li>Move the pointer one character <strong>counterclockwise</strong> or <strong>clockwise</strong>.</li>
    <li>Type the character the pointer is <strong>currently</strong> on.</li>
</ul>

<p>Given a string <code>word</code>, return <em>the <strong>minimum</strong> number of seconds to type out the characters in <code>word</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word = "abc"
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
The characters are printed as follows:
- Type the character 'a' in 1 second since the pointer is initially on 'a'.
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer clockwise to 'c' in 1 second.
- Type the character 'c' in 1 second.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word = "bza"
<strong>Output:</strong> 7
<strong>Explanation:</strong>
The characters are printed as follows:
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer counterclockwise to 'z' in 2 seconds.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'a' in 1 second.
- Type the character 'a' in 1 second.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word = "zjpc"
<strong>Output:</strong> 34
<strong>Explanation:</strong> 
The characters are printed as follows:
- Move the pointer counterclockwise to 'z' in 1 second.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'j' in 10 seconds.
- Type the character 'j' in 1 second.
- Move the pointer clockwise to 'p' in 6 seconds.
- Type the character 'p' in 1 second.
- Move the pointer counterclockwise to 'c' in 13 seconds.
- Type the character 'c' in 1 second.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= word.length &lt;= 100</code></li>
    <li><code>word</code> consists of lowercase English letters.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Follow the instruction and <strong>simulate</strong> the whole process, each time choose a direction with shorter distance, i.e., counterclockwise (<code>26 - (word[i + 1] - word[i])</code>) or clockwise (<code>word[i + 1] - word[i]</code>).</p>


<strong>C++</strong>

```
//  Topic   : 1974. Minimum Time to Type Word Using Special Typewriter
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0, n = word.length();
        char p = 'a';
        for (int i = 0; i < n; i++)
        {
            if (word[i] != p)
            {
                int dist = abs(word[i] - p);
                ans += min<int>(dist, 26 - dist);
                p = word[i];
            }
            ans += 1;
        }
        return ans;
    }
};
```