//  Topic   : 1952. Three Divisors
//  Author  : YCX
//  Time    : O(sqrt(N))
//  Space   : O(1)


class Solution {
public:
    bool isThree(int n) {
        if (n == 1)
            return false;
        int num = 2;
        for (int i = int(sqrt(n)) + 1; i < n; i++)
            if (n % i == 0)
                return false;
        if (int(sqrt(n)) * int(sqrt(n)) == n)
            return true;
        return false;
    }
};
