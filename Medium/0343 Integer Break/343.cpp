//  Topic   ：343. Integer Break (https://leetcode.com/problems/integer-break/)
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(N)


class Solution {
public:
    int integerBreak(int n) {
        vector<int> prod(n + 1, 0);
        prod[2] = 1;
        for (int i = 3; i <= n; i++)
            for (int j = 1; j < i; j++)
                prod[i] = max<int>(prod[i], j * max<int>(prod[i - j], i - j));
        return prod[n];
    }
};
