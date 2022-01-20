//  Topic   : 1752. Check if Array Is Sorted and Rotated
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool check(vector<int>& nums) {
        bool end = false;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1])
            {
                if (end)
                    return false;
                end = true;
            }
        if (end && nums[nums.size() - 1] > nums[0])
            return false;
        return true;
    }
};
