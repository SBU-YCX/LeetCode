//  Topic   : 1979. Find Greatest Common Divisor of Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [minv, maxv] = minmax_element(nums.begin(), nums.end());
        return __gcd(*minv, *maxv);
    }
};
