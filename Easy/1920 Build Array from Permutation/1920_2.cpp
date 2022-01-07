//  Topic   : 1920. Build Array from Permutation
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums[i] += (n * (nums[nums[i]] % n));
        for (int i = 0; i < n; i++)
            nums[i] /= n;
        return nums;
    }
};
