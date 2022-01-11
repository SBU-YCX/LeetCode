//  Topic   : 1863. Sum of All Subset XOR Totals
//  Author  : YCX
//  Time    : O(2 ^ N)
//  Space   : O(N)


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        track(nums, 0, 0, ans);
        return ans;
    }
    
private: 
    void track(vector<int>& nums, int i, int x, int& ans) {
        if (i == nums.size())
            return;
        x ^= nums[i];
        ans += x;
        track(nums, i + 1, x, ans);
        x ^= nums[i];
        track(nums, i + 1, x, ans);
    }
};
