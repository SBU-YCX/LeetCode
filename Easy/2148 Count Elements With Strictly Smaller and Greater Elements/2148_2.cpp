//  Topic   : 2148. Count Elements With Strictly Smaller and Greater Elements
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countElements(vector<int>& nums) {
        auto [minv, maxv] = minmax_element(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] < *maxv && nums[i] > *minv)
                ans++;
        return ans;
    }
};
