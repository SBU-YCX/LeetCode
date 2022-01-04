//  Topic   : 1995. Count Special Quadruplets
//  Author  : YCX
//  Time    : O(N^3)
//  Space   : O(N)


class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> f;
        f[nums[n - 1]]++;
        for (int c = n - 2; c >= 2; c--)
        {
            for (int b = c - 1; b >= 1; b--)
                for (int a = b - 1; a >= 0; a--)
                {
                    int d = nums[a] + nums[b] + nums[c];
                    ans += f[d];
                }
            f[nums[c]]++;
        }
        return ans;
    }
};
