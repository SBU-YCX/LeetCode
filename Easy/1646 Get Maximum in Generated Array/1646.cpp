//  Topic   : 1646. Get Maximum in Generated Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int getMaximumGenerated(int n) {
        int ans = 0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> nums(n + 1, 0);
        nums[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
                nums[i] = nums[i / 2];
            else
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            ans = max<int>(ans, nums[i]);
        }
        return ans;
    }
};
