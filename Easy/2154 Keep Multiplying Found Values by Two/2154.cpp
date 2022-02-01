//  Topic   : 2154. Keep Multiplying Found Values by Two
//  Author  : YCX
//  Time    : O(logM) [M is the maximum value]
//  Space   : O(N)


class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> v(1001, 0);
        for (auto& i: nums)
            v[i] = 1;
        while (original <= 1000 && v[original] == 1)
            original *= 2;
        return original;
    }
};
