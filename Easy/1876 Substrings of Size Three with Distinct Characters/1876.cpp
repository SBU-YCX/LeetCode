//  Topic   : 1876. Substrings of Size Three with Distinct Characters
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i < s.length() - 2; i++)
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i])
                ans += 1;
        return ans;
    }
};
