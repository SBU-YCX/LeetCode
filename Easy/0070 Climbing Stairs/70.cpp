//  Topic   : 70. Climbing Stairs (https://leetcode.com/problems/climbing-stairs/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2, ans;
        if (n == 1)
            return a;
        else if (n == 2)
            return b;
        else
        {
            for (int i = n - 3; i >= 0; i--)
            {
                ans = a + b;
                a = b;
                b = ans;
            }
        }
        return ans;
    }
};
