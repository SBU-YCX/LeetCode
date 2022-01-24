//  Topic   : 1708. Largest Subarray Length K
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        auto i = max_element(nums.begin(), nums.end() - k + 1);
        return vector<int>(i, i + k);
    }
};
