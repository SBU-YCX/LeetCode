# [2117. Abbreviating the Product of a Range](https://leetcode.com/problems/abbreviating-the-product-of-a-range/)


## Description:

<p>You are given two positive integers <code>left</code> and <code>right</code> with <code>left &lt;= right</code>. Calculate the <strong>product</strong> of all integers in the <strong>inclusive</strong> range <code>[left, right]</code>.</p>

<p>Since the product may be very large, you will <strong>abbreviate</strong> it following these steps:</p>
<ul>
    <li><p>Count all <strong>trailing</strong> zeros in the product and <strong>remove</strong> them. Let us denote this count as <code>C</code>.</p>
        <p>For example, there are <code>3</code> trailing zeros in <code>1000</code>, and there are <code>0</code> trailing zeros in <code>546</code>.</p></li>
    <li><p>Denote the remaining number of digits in the product as <code>d</code>. If <code>d &gt; 10</code>, then express the product as <code>&lt;pre&gt;...&lt;suf&gt;</code> where <code>&lt;pre&gt;</code> denotes the <strong>first</strong> <code>5</code> digits of the product, and <code>&lt;suf&gt;</code> denotes the <strong>last</strong> <code>5</code> digits of the product after <strong>removing</strong> all trailing zeros. If <code>d &lt;= 10</code>, we keep it unchanged.</p>
        <p>For example, we express <code>1234567654321</code> as <code>12345...54321</code>, but <code>1234567</code> is represented as <code>1234567</code>.</p></li>
    <li><p>Finally, represent the product as a <strong>string</strong> <code>"&lt;pre&gt;...&lt;suf&gt;eC"</code>.</p>
        <p>For example, <code>12345678987600000</code> will be represented as <code>"12345...89876e5"</code>.</p></li>
</ul>
<p>Return <em>a string denoting the <strong>abbreviated product</strong> of all integers in the <strong>inclusive</strong> range [left, right].</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> left = 1, right = 4
<strong>Output:</strong> "24e0"
<strong>Explanation:</strong> 
The product is 1 × 2 × 3 × 4 = 24.
There are no trailing zeros, so 24 remains the same. The abbreviation will end with "e0".
Since the number of digits is 2, which is less than 10, we do not have to abbreviate it further.
Thus, the final representation is "24e0". 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> left = 2, right = 11
<strong>Output:</strong> "399168e2"
<strong>Explanation:</strong> 
The product is 39916800.
There are 2 trailing zeros, which we remove to get 399168. The abbreviation will end with "e2".
The number of digits after removing the trailing zeros is 6, so we do not abbreviate it further.
Hence, the abbreviated product is "399168e2".  
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/11/17/productdrawio.png)
<pre>
<strong>Input:</strong> left = 999998, right = 1000000
<strong>Output:</strong> "99999...00002e6"
<strong>Explanation:</strong> 
The above diagram shows how we abbreviate the product to "99999...00002e6".
- It has 6 trailing zeros. The abbreviation will end with "e6".
- The first 5 digits are 99999.
- The last 5 digits after removing trailing zeros is 00002.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= left &lt;= right &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can separately keep <code>&lt;pre&gt;</code> and <code>&lt;suf&gt;</code> and multiply them with each number <code>i</code> within the interval. Before multiplication, <code>&lt;pre&gt;</code>, <code>&lt;suf&gt;</code> and <code>i</code> should remove all the tailing zeros. Pay attention, we need to keep more than <code>5</code> digits for the intermediate results because when <code>i</code> is large, the digits after the first <code>5</code> ones in <code>&lt;pre&gt;</code>  will also affect the first <code>5</code> digits in result. And each step, using modulation to remove the redundant digits.</p>


<strong>C++</strong>

```
// Topic     : 2117. Abbreviating the Product of a Range (https://leetcode.com/problems/abbreviating-the-product-of-a-range/)
// Author    : YCX
// Time      : O(N)
// Space     : O(1)


class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int c = 0;
        long long pre = 1, suf = 1, mod = 1e12;
        for (int i = left; i <= right; i++)
        {
            long long cur(i);
            pre *= cur;
            while (pre > mod)
                pre /= 10;
            suf *= cur;
            while (suf % 10 == 0)
            {
                suf /= 10;
                c++;
            }
            suf %= mod;
        }
        string pres = to_string(pre), sufs = to_string(suf), ans = "";
        if (sufs.length() <= 10)
            ans = sufs + "e" + to_string(c);
        else
        {
            if (sufs.length() < 5)
                sufs = string(5 - sufs.length(), '0') + sufs;
            ans = pres.substr(0, 5) + "..." + sufs.substr(sufs.length() - 5) + "e" + to_string(c);
        }
        return ans;
    }
};
```
