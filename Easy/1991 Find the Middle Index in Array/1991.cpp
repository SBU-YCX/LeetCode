//  Topic   : 1991. Find the Middle Index in Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + nums[i];
        for (int i = 1; i <= n; i++)
        {
            int left = sum[i - 1];
            int right = sum[n] - sum[i];
            if (left == right)
                return i - 1;
        }
        return -1;
    }
};
