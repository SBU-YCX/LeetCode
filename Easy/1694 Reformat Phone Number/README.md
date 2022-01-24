# [1694. Reformat Phone Number](https://leetcode.com/problems/reformat-phone-number/)


## Description:

<p>You are given a phone number as a string <code>number</code>. <code>number</code> consists of digits, spaces <code>' '</code>, and/or dashes <code>'-'</code>.</p>

<p>You would like to reformat the phone number in a certain manner. Firstly, <strong>remove</strong> all spaces and dashes. Then, <strong>group</strong> the digits from left to right into blocks of length 3 <strong>until</strong> there are 4 or fewer digits. The final digits are then grouped as follows:</p>

<ul>
    <li>2 digits: A single block of length 2.</li>
    <li>3 digits: A single block of length 3.</li>
    <li>4 digits: Two blocks of length 2 each.</li>
</ul>

<p>The blocks are then joined by dashes. Notice that the reformatting process should <strong>never</strong> produce any blocks of length 1 and produce <strong>at most</strong> two blocks of length 2.</p>

<p>Return <em>the phone number after formatting.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> number = "1-23-45 6"
<strong>Output:</strong> "123-456"
<strong>Explanation:</strong> The digits are "123456".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 3 digits remaining, so put them in a single block of length 3. The 2nd block is "456".
Joining the blocks gives "123-456".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> number = "123 4-567"
<strong>Output:</strong> "123-45-67"
<strong>Explanation:</strong> The digits are "1234567".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 4 digits left, so split them into two blocks of length 2. The blocks are "45" and "67".
Joining the blocks gives "123-45-67".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> number = "123 4-5678"
<strong>Output:</strong> "123-456-78"
<strong>Explanation:</strong> The digits are "12345678".
Step 1: The 1st block is "123".
Step 2: The 2nd block is "456".
Step 3: There are 2 digits left, so put them in a single block of length 2. The 3rd block is "78".
Joining the blocks gives "123-456-78".
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= number.length &lt;= 100</code></li>
    <li><code>number</code> consists of digits and the characters <code>'-'</code> and <code>' '</code>.</li>
    <li>There are at least <strong>two</strong> digits in <code>number</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>First, collect all the digits, then split them as required.</p>


<strong>C++</strong>

```
//  Topic   : 1694. Reformat Phone Number
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string reformatNumber(string number) {
        string digits = "";
        for (int i = 0; i < number.length(); i++)
            if (number[i] <= '9' && number[i] >= '0')
                digits += number[i];
        string ans = "";
        int n = digits.length();
        switch(n % 3)
        {
            case 0:
                for (int i = 0; i < n - 3; i += 3)
                {
                    ans += digits[i];
                    ans += digits[i + 1];
                    ans += digits[i + 2];
                    ans += '-';
                }
                ans += digits[n - 3];
                ans += digits[n - 2];
                ans += digits[n - 1];  
                break;
            case 1:
                for (int i = 0; i < n - 4; i += 3)
                {
                    ans += digits[i];
                    ans += digits[i + 1];
                    ans += digits[i + 2];
                    ans += '-';
                }
                ans += digits[n - 4];
                ans += digits[n - 3];
                ans += '-';
                ans += digits[n - 2];
                ans += digits[n - 1];  
                break;
            case 2:
                for (int i = 0; i < n - 2; i += 3)
                {
                    ans += digits[i];
                    ans += digits[i + 1];
                    ans += digits[i + 2];
                    ans += '-';
                }
                ans += digits[n - 2];
                ans += digits[n - 1];  
                break;
        }
        return ans;
    }
};
```