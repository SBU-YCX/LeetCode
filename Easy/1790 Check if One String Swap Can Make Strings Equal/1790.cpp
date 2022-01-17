//  Topic   : 1790. Check if One String Swap Can Make Strings Equal
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        vector<vector<char>> cache;
        for (int i = 0; i < s1.length(); i++)
            if (s1[i] != s2[i])
            {
                cache.push_back({s1[i], s2[i]});
                if (cache.size() >= 3)
                    return false;
            }
        if (cache.size() == 1)
            return false;
        if (cache[0][0] == cache[1][1] && cache[0][1] == cache[1][0])
            return true;
        return false;
    }
};
