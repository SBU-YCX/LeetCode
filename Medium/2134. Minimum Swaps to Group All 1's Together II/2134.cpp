//  Topic   : 2134. Minimum Swaps to Group All 1's Together II
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        int l = 1, s = accumulate(nums.begin(), nums.begin() + k, 0), ans = k - s;
        while (l < n)
        {
            s -= nums[l - 1];
            s += nums[(l + k - 1) % n];
            ans = min<int>(ans, k - s);
            l++;
        }
        return ans;
    }
};
