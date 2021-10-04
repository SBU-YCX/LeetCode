//  Topic   ：45. Jump Game II (https://leetcode.com/problems/jump-game-ii/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), max_idx_nxt = 0, max_idx_cur = 0, ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            max_idx_nxt = max<int>(max_idx_nxt, i + nums[i]);
            if (i == max_idx_cur)
            {
                ans++;
                max_idx_cur = max_idx_nxt;
            }
        }
        return ans;
    }
};
