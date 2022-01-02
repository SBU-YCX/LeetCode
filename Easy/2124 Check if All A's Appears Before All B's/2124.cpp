//  Topic   : 2124. Check if All A's Appears Before All B's (https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool checkString(string s) {
        int pa = s.find_last_of('a'), pb = s.find('b');
        if (pa == -1 || pb == -1)
            return true;
        return (pa < pb);
    }
};
