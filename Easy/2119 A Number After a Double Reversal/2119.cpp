//  Topic   : 2119. A Number After a Double Reversal (https://leetcode.com/problems/a-number-after-a-double-reversal/)
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0)
            return true;
        int a = num % 10;
        return (a != 0);
    }
};
