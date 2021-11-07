# [2062. Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string/)


## Description:

<p>A <strong>substring</strong> is a contiguous (non-empty) sequence of characters within a string.</p>

<p>A <strong>vowel substring</strong> is a substring that <strong>only</strong> consists of vowels (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>) and has <strong>all five</strong> vowels present in it.</p>

<p>Given a string <code>word</code>, return <em>the number of <strong>vowel substrings</strong> in <code>word</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> word = "aeiouu"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The vowel substrings of word are as follows (underlined):
- "[aeiou]u"
- "[aeiouu]"
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> word = "unicornarihan"
<strong>Output:</strong> 0
<strong>Explanation:</strong> Not all 5 vowels are present, so there are no vowel substrings.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> word = "cuaieuouac"
<strong>Output:</strong> 7
<strong>Explanation:</strong> The vowel substrings of word are as follows (underlined):
- "c[uaieuo]uac"
- "c[uaieuou]ac"
- "c[uaieuoua]c"
- "cu[aieuo]uac"
- "cu[aieuou]ac"
- "cu[aieuoua]c"
- "cua[ieuoua]c"
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong> word = "bbaeixoubb"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only substrings that contain all five vowels also contain consonants, so there are no vowel substrings.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= word.length &lt;= 100</code></li>
  <li><code>word</code> consists of lowercase English letters only.</li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p>Use <strong>brute force</strong> to check substrings starting with each character. Here, a mask <code>flag</code> is used to indicate whether a vowel in [<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>] has appeared, if current character is a vowel and the mask is <code>"11111"</code>, answer is increased by <code>1</code>; if the current character is not a vowel, break the current loop and check the substrings starting with the next character.</p>


<strong>C++</strong>

```
//  Topic   : 2062. Count Vowel Substrings of a String (https://leetcode.com/problems/count-vowel-substrings-of-a-string/)
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(1)


class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            string flag = "00000";
            for (int j = i; j < n; j++)
            {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
                {
                    if (word[j] == 'a')
                        flag[0] = '1';
                    else if (word[j] == 'e')
                        flag[1] = '1';
                    else if (word[j] == 'i')
                        flag[2] = '1';
                    else if (word[j] == 'o')
                        flag[3] = '1';
                    else 
                        flag[4] = '1';
                    if (flag == "11111")
                        ans++;
                }
                else
                    break;
            }
        }
        return ans;
    }
};
```

## Solution 2:

<strong>Logical Thinking</strong>
<p>We can also use <strong>sliding window</strong> to solve this problem. We need to right boundary of the window so that the substring with all 5 vowels. Then, we try to shift the left boundary to keep all kinds of vowels still in the window, then the steps of shifting is the number of all vowels substrings ending with the current vowel character. If the current character is not a vowel, just reset all the counters and make both boundaries to the right of it. </p>


<strong>C++</strong>

```
//  Topic   : 2062. Count Vowel Substrings of a String (https://leetcode.com/problems/count-vowel-substrings-of-a-string/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countVowelSubstrings(string word) {
        int l = 0, r = word.length(), p = 0, q = 0, v = 0, ans = 0;
        unordered_map<char, int> num;
        while (l < r)
        {
            if (word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u')
            {
                num[word[l]]++;
                if (num[word[l]] == 1)
                    v++;
                while (q < l && v == 5)
                {
                    num[word[q]]--;
                    if (num[word[q]] == 0)
                        v--;
                    q++;
                }
                ans += (q - p);
            }
            else
            {
                p = q = l + 1;
                v = 0;
                num['a'] = num['e'] = num['i'] = num['o'] = num['u'] = 0;
            }
            l++;
        }
        return ans;
    }
};
```
