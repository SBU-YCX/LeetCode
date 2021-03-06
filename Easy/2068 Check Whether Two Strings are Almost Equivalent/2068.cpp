//  Topic   : 2068. Check Whether Two Strings are Almost Equivalent (https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/)
//  Author  : YCX
//  Time    : O(N1 + N2)
//  Space   : O(1)


class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> freq(26, 0);
        for (auto c : word1)
            freq[c - 'a']++;
        for (auto c : word2)
            freq[c - 'a']--;
        for (auto l : freq)
            if (l > 3 || l < -3)
                return false;
        return true;
    }
};
