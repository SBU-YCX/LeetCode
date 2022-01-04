//  Topic   : 1995. Count Special Quadruplets
//  Author  : YCX
//  Time    : O(N^4)
//  Space   : O(1)


class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int d = 3; d < n; d++)
            for (int a = 0; a < d; a++)
                for (int b = a + 1; b < d; b++)
                    for (int c = b + 1; c < d; c++)
                        if (nums[a] + nums[b] + nums[c] == nums[d])
                            ans += 1;
        return ans;
    }
};
