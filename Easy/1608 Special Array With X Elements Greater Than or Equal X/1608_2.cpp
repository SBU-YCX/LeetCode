//  Topic   : 1608. Special Array With X Elements Greater Than or Equal X
//  Author  : YCX
//  Time    : O(NlogN + logN)
//  Space   : O(logN)


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 1, n = nums.size(), r = n - 1;
        if (nums[0] >= n)
            return n;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[n - m] >= m && nums[n - m - 1] < m)
                return m;
            else if (nums[n - m - 1] >= m)
                l = m + 1;
            else 
                r = m - 1;
        }
        return -1;
    }
};
