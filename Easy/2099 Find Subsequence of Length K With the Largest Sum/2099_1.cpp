//  Topic   : 2099. Find Subsequence of Length K With the Largest Sum (https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size(), m = n - k;
        vector<int> idx;
        for (int i = 0; i < n; i++)
            idx.push_back(i);
        sort(idx.begin(), idx.end(), [&nums](int a, int b) {return nums[a] > nums[b];});
        idx.resize(k);
        sort(idx.begin(), idx.end());
        vector<int> ans;
        for (auto& i : idx)
            ans.push_back(nums[i]);
        return ans;
    }
};
