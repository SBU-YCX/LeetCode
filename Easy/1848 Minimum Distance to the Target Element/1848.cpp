//  Topic   : 1848. Minimum Distance to the Target Element
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int m = nums.size();
        for (int i = 0; i <= max<int>(start, m - start); i++)
        {
            if (start + i < m && nums[start + i] == target)
                return i;
            if (start - i >= 0 && nums[start - i] == target)
                return i;
        }
        return 0;
    }
};
