# [2060. Check if an Original String Exists Given Two Encoded Strings](https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/)


## Description:

<p>An original string, consisting of lowercase English letters, can be encoded by the following steps:</p>

<ul>
    <li>Arbitrarily <strong>split</strong> it into a <strong>sequence</strong> of some number of <strong>non-empty</strong> substrings.</li>
    <li>Arbitrarily choose some elements (possibly none) of the sequence, and <strong>replace</strong> each with <strong>its length</strong> (as a numeric string).</li>
    <li><strong>Concatenate</strong> the sequence as the encoded string.</li>
</ul>

<p>For example, <strong>one way</strong> to encode an original string <code>"abcdefghijklmnop"</code> might be:</p>

<ul>
    <li>Split it as a sequence: <code>["ab", "cdefghijklmn", "o", "p"]</code>.</li>
    <li>Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes <code>["ab", "12", "1", "p"]</code>.</li>
    <li>Concatenate the elements of the sequence to get the encoded string: <code>"ab121p"</code>.</li>
</ul>

<p>Given two encoded strings <code>s1</code> and <code>s2</code>, consisting of lowercase English letters and digits <code>1-9</code> (inclusive), return <em><code>true</code> if there exists an original string that could be encoded as <strong>both</strong> <code>s1</code> and <code>s2</code>. Otherwise, return <code>false</code>.</em></p>

<p><strong>Note:</strong> The test cases are generated such that the number of consecutive digits in <code>s1</code> and <code>s2</code> does not exceed 3.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> s1 = "internationalization", s2 = "i18n"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
It is possible that "internationalization" was the original string.
- "internationalization" 
  -> Split:       ["internationalization"]
  -> Do not replace any element
  -> Concatenate:  "internationalization", which is s1.
- "internationalization"
  -> Split:       ["i", "nternationalizatio", "n"]
  -> Replace:     ["i", "18",                 "n"]
  -> Concatenate:  "i18n", which is s2 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> s1 = "l123e", s2 = "44"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
It is possible that "leetcode" was the original string.
- "leetcode" 
  -> Split:      ["l", "e", "et", "cod", "e"]
  -> Replace:    ["l", "1", "2",  "3",   "e"]
  -> Concatenate: "l123e", which is s1.
- "leetcode" 
  -> Split:      ["leet", "code"]
  -> Replace:    ["4",    "4"]
  -> Concatenate: "44", which is s2.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> s1 = "a5b", s2 = "c5b"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
It is impossible.
- The original string encoded as s1 must start with the letter 'a'.
- The original string encoded as s2 must start with the letter 'c'.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= s1.length, s2.length &lt;= 40</code></li>
    <li><code>s1</code> and <code>s2</code> consist of digits <code>1-9</code> (inclusive), and lowercase English letters only.</li>
    <li>The number of consecutive digits in <code>s1</code> and <code>s2</code> does not exceed <code>3</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can solve this problem using top-down <strong>dynamic programming</strong>, besides the indices <code>i</code> and <code>j</code> of string <code>s1</code> and <code>s2</code>, we also need another dimension <code>d</code> to indicate the number of hidden characters represented by digits, specifically:</p>

<ul>
    <li>if <code>i</code> or <code>j</code> points to a digit, get adjacent digits (at most <code>3</code>), and generate all possible numbers to update <code>d</code> and move the indices</li>
    <li>if <code>i</code> and <code>j</code> points to a letter
        <ul>
            <li>if <code>d != 0</code>, match one hidden character with a letter in the other string, update <code>d</code> and move the index</li>
            <li>if <code>d == 0</code>, match two letters and see if they are the same</li>
        </ul>
    </li>
</ul>


<strong>C++</strong>

```
// Topic     : 2060. Check if an Original String Exists Given Two Encoded Strings (https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2127%20Maximum%20Employees%20to%20Be%20Invited%20to%20a%20Meeting)
// Time      : O(M * N * 2000) 
// Space     : O(M * N * 2000)


class Solution {
public:
    
    bool possiblyEquals(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<vector<bool>>> matched(n1 + 1, vector<vector<bool>>(n2 + 1, vector<bool>(2000, false)));
        return possiblyEquals(s1, s2, 0, 0, 0, matched);
    }
    
private: 
    bool possiblyEquals(string& s1, string& s2, int i, int j, int d, vector<vector<vector<bool>>>& matched)
    {
        int n1 = s1.length(), n2 = s2.length();
        if (i == n1 && j == n2)
            return (d == 0);
        if (!matched[i][j][d + 1000])
        {
            matched[i][j][d + 1000] = true;
            if (i < n1 && isdigit(s1[i]))
            {
                int nd = 0;
                while (i < n1 && isdigit(s1[i]))
                {
                    nd = nd * 10 + (s1[i] - '0');
                    i++;
                    if (possiblyEquals(s1, s2, i, j, d - nd, matched))
                        return true;
                }
                return false;
            }    
            if (j < n2 && isdigit(s2[j]))
            {
                int nd = 0;
                while (j < n2 && isdigit(s2[j]))
                {
                    nd = nd * 10 + (s2[j] - '0');
                    j++;
                    if (possiblyEquals(s1, s2, i, j, d + nd, matched))
                        return true;
                }
                return false;
            }
            if (d > 0)
                return (i < n1 && possiblyEquals(s1, s2, i + 1, j, d - 1, matched));
            else if (d < 0)
                return (j < n2 && possiblyEquals(s1, s2, i, j + 1, d + 1, matched));
            else
                return (i < n1 && j < n2 && s1[i] == s2[j] && possiblyEquals(s1, s2, i + 1, j + 1, d, matched));
        }
        return false;
    }
};
```
