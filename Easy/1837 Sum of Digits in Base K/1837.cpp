//  Topic   : 1837. Sum of Digits in Base K
//  Author  : YCX
//  Time    : O(logN)
//  Space   : O(1)


class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        while (n != 0)
        {
            ans += (n % k);
            n /= k;
        }
        return ans;
    }
};
