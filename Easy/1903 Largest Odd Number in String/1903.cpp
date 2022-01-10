//  Topic   : 1903. Largest Odd Number in String
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int i;
        for (i = n - 1; i >= 0; i--)
            if ((num[i] - '0') % 2)
                break;
        return num.substr(0, i + 1);
    }
};
