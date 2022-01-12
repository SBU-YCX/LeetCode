//  Topic   : 1844. Replace All Digits with Characters
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.length(); i += 2)
            s[i] = (s[i - 1] + (s[i] - '0'));
        return s;
    }
};
