//  Topic   : 2085. Count Common Words With One Occurrence (https://leetcode.com/problems/count-common-words-with-one-occurrence/)
//  Author  : YCX
//  Time    : O(N1 + N2)
//  Space   : O(N1 + N2)


class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> f1, f2;
        for (auto& w : words1)
            f1[w]++;
        for (auto& w : words2)
            f2[w]++;
        int ans = 0;
        for (auto& p : f1)
            if (f2[p.first] == 1 && p.second == 1)
                ans++;
        return ans;
    }
};
