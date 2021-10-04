//  Topic   ：55. Jump Game (https://leetcode.com/problems/jump-game/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > max_index)
                return false;
            max_index = max<int>(max_index, i + nums[i]);
        }
        return true;
    }
};
