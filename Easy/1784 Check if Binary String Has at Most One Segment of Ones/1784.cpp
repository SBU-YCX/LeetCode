//  Topic   : 1784. Check if Binary String Has at Most One Segment of Ones
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool checkOnesSegment(string s) {
        int r = s.length(), l = s.find('0');
        if (l == -1)
            return true;
        int p = s.find('1', l);
        return (p == -1);
    }
};
