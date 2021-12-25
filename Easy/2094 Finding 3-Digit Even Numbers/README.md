# [2094. Finding 3-Digit Even Numbers](https://leetcode.com/problems/finding-3-digit-even-numbers/)


## Description:

<p>You are given an integer array <code>digits</code>, where each element is a digit. The array may contain duplicates.</p>

<p>You need to find <strong>all</strong> the <strong>unique</strong> integers that follow the given requirements:</p>
<ul>
    <li>The integer consists of the <strong>concatenation</strong> of <strong>three</strong> elements from <code>digits</code> in <strong>any</strong> arbitrary order.</li>
    <li>The integer does not have <strong>leading zeros</strong>.</li>
    <li>The integer is <strong>even</strong>.</li>
</ul>
<p>For example, if the given <code>digits</code> were <code>[1, 2, 3]</code>, integers <code>132</code> and <code>312</code> follow the requirements.</p>

<p>Return <em>a <strong>sorted</strong> array of the unique integers.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> digits = [2,1,3,0]
<strong>Output:</strong> [102,120,130,132,210,230,302,310,312,320]
<strong>Explanation:</strong> 
All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> digits = [2,2,8,8,2]
<strong>Output:</strong> [222,228,282,288,822,828,882]
<strong>Explanation:</strong> 
The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> digits = [3,7,5]
<strong>Output:</strong> []
<strong>Explanation:</strong> 
No even integers can be formed using the given digits.
</pre>


## Constraints:

<ul>
  <li><code>3 &lt;= digits.length &lt;= 100</code></li>
  <li><code>0 &lt;= digits[i] &lt;= 9</code></li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p>Using <strong>brute force</strong> to enumerate the whole whole <code>digits</code> and try all the possible combinations, find out the required integers and <strong>sort</strong> them.</p>


<strong>C++</strong>

```
//  Topic   : 2094. Finding 3-Digit Even Numbers (https://leetcode.com/problems/finding-3-digit-even-numbers/)
//  Author  : YCX
//  Time    : O((N ^ 3)log(N ^ 3)) [N <= 10]
//  Space   : O(N ^ 3)


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            if (digits[i] == 0)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;
                    if (digits[k] % 2 == 0)
                    {
                        int t = digits[i] * 100 + digits[j] * 10 + digits[k];
                        s.insert(t);
                    }
                }
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};
```


## Solution 2: [Improved]

<strong>Logical Thinking</strong>
<p>In Solution 1, when we check from digits, we may generate duplicated numbers and also need extra time to sort the array. Instead, we can just check all the 3-digit even numbers from 100 to 999 to see if it can be composed of given digits.</p>


<strong>C++</strong>

```
//  Topic   : 2094. Finding 3-Digit Even Numbers (https://leetcode.com/problems/finding-3-digit-even-numbers/)
//  Author  : YCX
//  Time    : O((10 ^ 3))
//  Space   : O(N ^ 3)


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++)
            freq[digits[i]]++;
        vector<int> ans;
        for (int i = 100; i <= 999; i += 2)
        {
            int d1 = i / 100, d2 = (i % 100) / 10, d3 = i % 10;
            freq[d1]--;
            freq[d2]--;
            freq[d3]--;
            if (freq[d1] >= 0 & freq[d2] >= 0 & freq[d3] >= 0)
                ans.push_back(i);
            freq[d1]++;
            freq[d2]++;
            freq[d3]++;
        }  
        return ans;
    }
};
```
