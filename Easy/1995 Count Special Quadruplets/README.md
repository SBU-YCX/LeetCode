# [1995. Count Special Quadruplets](https://leetcode.com/problems/count-special-quadruplets/)


## Description:

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, return <em>the number of <strong>distinct</strong> quadruplets <code>(a, b, c, d)</code> such that:</em></p>

<ul>
    <li><code>nums[a] + nums[b] + nums[c] == nums[d]</code>, and</li>
    <li><code>a &lt; b &lt; c &lt; d</code></li>
</ul>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3,6]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only quadruplet that satisfies the requirement is (0, 1, 2, 3) because 1 + 2 + 3 == 6.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [3,3,6,4,5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no such quadruplets in [3,3,6,4,5].
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,1,3,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 4 quadruplets that satisfy the requirement are:
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5
</pre>


## Constraints:

<ul>
    <li><code>4 &lt;= nums.length &lt;= 50</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution 1:

<strong>Logical Thinking</strong>
<p>Enumerate with <strong>brute force</strong>.</p>


<strong>C++</strong>

```
//  Topic   : 1995. Count Special Quadruplets
//  Author  : YCX
//  Time    : O(N^4)
//  Space   : O(1)


class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int d = 3; d < n; d++)
            for (int a = 0; a < d; a++)
                for (int b = a + 1; b < d; b++)
                    for (int c = b + 1; c < d; c++)
                        if (nums[a] + nums[b] + nums[c] == nums[d])
                            ans += 1;
        return ans;
    }
};
```


## Solution 2: [Improved]

<strong>Logical Thinking</strong>
<p>Actually, we can use a <strong>hash table</strong> to reduce the time complexity, specifically, we store the frequencies of <code>nums[d]</code> in <code>f</code>, then, for each triplet <code>(a, b, c)</code>, we only need to add the frequency of <code>nums[a] + nums[b] + nums[c]</code> when <code>d</code> in the range of <code>[c + 1, n - 1]</code>.</p>


<strong>C++</strong>

```
//  Topic   : 1995. Count Special Quadruplets
//  Author  : YCX
//  Time    : O(N^3)
//  Space   : O(N)


class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> f;
        f[nums[n - 1]]++;
        for (int c = n - 2; c >= 2; c--)
        {
            for (int b = c - 1; b >= 1; b--)
                for (int a = b - 1; a >= 0; a--)
                {
                    int d = nums[a] + nums[b] + nums[c];
                    ans += f[d];
                }
            f[nums[c]]++;
        }
        return ans;
    }
};
```
