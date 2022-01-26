//  Topic   : 1608. Special Array With X Elements Greater Than or Equal X
//  Author  : YCX
//  Time    : O(NlogN + N)
//  Space   : O(logN)


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        if (nums[0] >= m)
            return m;
        if (nums[m - 1] < 0)
            return 0;
        for (int i = 1; i < m - 1; i++)
            if (nums[m - i] >= i && nums[m - i - 1] < i)
                return i;
        return -1;
    }
};
