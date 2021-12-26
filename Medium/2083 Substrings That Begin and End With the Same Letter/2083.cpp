//  Topic   : 2083. Substrings That Begin and End With the Same Letter (https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    long long numberOfSubstrings(string s) {
        vector<int> freq(26, 0);
        long long ans = 0;
        for (auto& c : s)
        {
            freq[c - 'a']++;
            ans += freq[c - 'a'];
        }
        return ans;
    }
};
