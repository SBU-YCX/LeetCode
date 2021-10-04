//  Topic   ：45. Jump Game II (https://leetcode.com/problems/jump-game-ii/)
//  Author  : YCX
//  Time    : O(N * N)
//  Space   : O(N)


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> num(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] >= n - 1 - i)
                num[i] = 1;
            else if (nums[i] == 0)
                num[i] = 1e5;
            else
            {
                int min_num = 1e5;
                for (int j = 1; j <= nums[i]; j++)
                    min_num = min<int>(min_num, num[i + j]);
                num[i] = min_num + 1;
            }
        }
        return num[0];
    }
};
