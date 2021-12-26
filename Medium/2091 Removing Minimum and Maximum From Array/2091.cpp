//  Topic   : 2091. Removing Minimum and Maximum From Array (https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto [miniter, maxiter] = minmax_element(nums.begin(), nums.end());
        int minidx = miniter - nums.begin();
        int maxidx = maxiter - nums.begin();
        int n = nums.size();
        if (minidx > maxidx)
            swap(minidx, maxidx);
        int ans = min<int>(minidx + 1 + n - maxidx, min<int>(maxidx + 1, n - minidx));
        return ans;
    }
};
