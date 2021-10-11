# [1983. Widest Pair of Indices With Equal Range Sum](https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/)


## Description:




## Examples:




## Constraints:



## Solution:

<strong>Logical Thinking</strong>



<strong>C++</strong>

```
// Topic     : 1983. Widest Pair of Indices With Equal Range Sum (https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/)
// Author    : YCX
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ans = 0;
        vector<int> presum1(n + 1, 0), presum2(n + 1, 0);
        unordered_map<int, int> diff;
        diff[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            presum1[i] = presum1[i - 1] + nums1[i - 1];
            presum2[i] = presum2[i - 1] + nums2[i - 1];
            int d = presum1[i] - presum2[i];
            if (diff.count(d) == 0)
                diff[d] = i;
            else
                ans = max<int>(ans, i - diff[d]);
        }
        return ans;
    }
};
```
