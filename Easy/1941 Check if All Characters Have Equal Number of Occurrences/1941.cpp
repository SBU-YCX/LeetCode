//  Topic   : 1941. Check if All Characters Have Equal Number of Occurrences
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.length(), k = 0, m = 25;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;
        while (m >= 0 && freq[m] == 0)
            m--;
        k = freq[m];
        while (m >= 0)
        {
            if (freq[m] != k && freq[m] != 0)
                return false;
            m--;
        }
        return true;
    }
};
