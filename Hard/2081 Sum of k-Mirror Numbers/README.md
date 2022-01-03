# [2081. Sum of k-Mirror Numbers](https://leetcode.com/problems/sum-of-k-mirror-numbers/  )


## Description:

<p>A <strong>k-mirror number</strong> is a <strong>positive</strong> integer <strong>without leading zeros</strong> that reads the same both forward and backward in base-10 <strong>as well as</strong> in base-k.</p>

<ul>
    <li>For example, <code>9</code> is a 2-mirror number. The representation of <code>9</code> in base-10 and base-2 are <code>9</code> and <code>1001</code> respectively, which read the same both forward and backward.</li>
    <li>On the contrary, <code>4</code> is not a 2-mirror number. The representation of <code>4</code> in base-2 is <code>100</code>, which does not read the same both forward and backward.</li>
</ul>

<p>Given the base <code>k</code> and the number <code>n</code>, return <em>the <strong>sum</strong> of the <code>n</code> <strong>smallest</strong> k-mirror numbers.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> k = 2, n = 5
<strong>Output:</strong> 25
<strong>Explanation:</strong> 
The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
  base-10    base-2
    1          1
    3          11
    5          101
    7          111
    9          1001
Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> k = 3, n = 7
<strong>Output:</strong> 499
<strong>Explanation:</strong> 
The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
  base-10    base-3
    1          1
    2          2
    4          11
    8          22
    121        11111
    151        12121
    212        21212
Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> k = 7, n = 17
<strong>Output:</strong> 20379000
<strong>Explanation:</strong> 
The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
</pre>


## Constraints:

<ul>
    <li><code>2 &lt;= k &lt;= 9</code></li>
    <li><code>1 &lt;= n &lt;= 30</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We <strong>greedily</strong> generate all palindrome numbers of base 10, for each of them, check whether it is also palindrome under base k.</p>


<strong>C++</strong>

```
// Topic     : 2081. Sum of k-Mirror Numbers (https://leetcode.com/problems/sum-of-k-mirror-numbers/)
// Author    : YCX
// Time      : O(F(N)) where F(N) is the number of all palindrome numbers of base 10 smaller than the nth k-mirror number
// Space     : O(F(N))


class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        for (long long level = 1; n > 0; level *= 10)
        {
            for (long long num = level; n > 0 && num < level * 10; num++)
            {
                long long palindodd = genPalind(num, true);
                if (isPalind(palindodd, k))
                {
                    sum += palindodd;
                    n--;
                }
            }
            for (long long num = level; n > 0 && num < level * 10; num++)
            {
                long long palindeven = genPalind(num, false);
                if (isPalind(palindeven, k))
                {
                    sum += palindeven;
                    n--;
                }
            }
        }
        return sum;
    }
    
private: 
    long long genPalind(long long half, bool o2e)
    {
        long long ans = half;
        if (o2e)
            half /= 10;
        while (half)
        {
            ans = ans * 10 + half % 10;
            half /= 10;
        }
        return ans;
    }
    
    bool isPalind(long long& num, int& base)
    {
        string s = toBase(num, base);
        int l = 0, r = s.length() - 1;
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
    
    string toBase(long long num, int& base)
    {
        string ans = "";
        while (num)
        {
            ans += (num % base + '0');
            num /= base;
        }
        return ans;
    }
};
```
