# 2023. Number of Pairs of Strings With Concatenation Equal to Target


## Description:

<p>Given an array of <strong>digit</strong> strings <code>nums</code> and a <strong>digit</strong> string <code>target</code>, return <em>the number of pairs of indices <code>(i, j)</code> (where <code>i != j</code>) such that the <strong>concatenation</strong> of <code>nums[i] + nums[j]</code> equals <code>target</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = ["777","7","77","77"], target = "7777"
<strong>Output:</strong> 4
<strong>Explanation:</strong> Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = ["123","4","12","34"], target = "1234"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Valid pairs are:
- (0, 1): "123" + "4"
- (2, 3): "12" + "34"
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = ["1","1","1"], target = "11"
<strong>Output:</strong> 6
<strong>Explanation:</strong> Valid pairs are:
- (0, 1): "1" + "1"
- (1, 0): "1" + "1"
- (0, 2): "1" + "1"
- (2, 0): "1" + "1"
- (1, 2): "1" + "1"
- (2, 1): "1" + "1"
</pre>


## Constraints:

<ul>
  <li><code>2 &lt;= nums.length &lt;= 100</code></li>
  <li><code>1 &lt;= nums[i].length &lt;= 100</code></li>
  <li><code>2 &lt;= target.length &lt;= 100</code></li>
  <li><code>nums[i]</code> and <code>target</code> consist of digits.</li>
  <li><code>nums[i]</code> and <code>target</code> do not have leading zeros.</li>
</ul>


## Solution1:

<strong>Logical Thinking</strong>
<p>For each pair of strings in <code>nums</code>, check whether they can form the <code>target</code>. </p>


<strong>C++</strong>

```
//  Topic   ：2023. Number of Pairs of Strings With Concatenation Equal to Target (https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/)
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(N^2)

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                if (nums[i] + nums[j] == target)
                    ans += 1;
                if (nums[j] + nums[i] == target)
                    ans += 1;
            }
        return ans;
    }
};
```


## Solution2: (Improved)

<strong>Logical Thinking</strong>
<p>Using a map to store the frequencies of all strings in <code>nums</code>. For each item in map, check whether it is a prefix of <code>target</code>, then check whether the remaining substring of <code>target</code> is in the map and its frequency (<code>O(1)</code>). Pay attention, if the remaining suffix is equal to the prefix, the answer should minus the frequency of the prefix.</p>


<strong>C++</strong>

```
//  Topic   ：2023. Number of Pairs of Strings With Concatenation Equal to Target (https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ans = 0, l = target.length();
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++)
            m[nums[i]]++;
        for (auto s : m)
        {
            int k = s.first.length();
            if (k > l)
                continue;
            if (s.first == target.substr(0, k))
            {
                string t = target.substr(k);
                ans += s.second * m[t];
                if (s.first == t)
                    ans -= m[t];
            }
        }
        return ans;
    }
};
```
