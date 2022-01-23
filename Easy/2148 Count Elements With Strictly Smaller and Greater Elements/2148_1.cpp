//  Topic   : 2148. Count Elements With Strictly Smaller and Greater Elements
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(logN)


class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && nums[i] == nums[0])
            i++;
        while (j >= 0 && nums[j] == nums[n - 1])
            j--;
        return max<int>(0, j - i + 1);
    }
};
