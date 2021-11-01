//  Topic   ：2044. Count Number of Maximum Bitwise-OR Subsets (https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)
//  Author  : YCX
//  Time    : O(M * N) [M is the maximum bitwise-or result]
//  Space   : O(M)


class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxv = 0;
        for (auto i : nums)
            maxv |= i;
        unordered_map<int, int> ways;
        ways[0] = 1;
        for (auto i : nums)
        {
            unordered_map<int, int> subways;
            for (auto j : ways)
                subways[j.first | i] += j.second;
            for (auto j : subways)
                ways[j.first] += j.second;
        }
        return ways[maxv];
    }
};
