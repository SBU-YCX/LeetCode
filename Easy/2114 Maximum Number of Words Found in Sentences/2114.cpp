//  Topic   : 2114. Maximum Number of Words Found in Sentences (https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/)
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(1)


class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = count(sentences[i].begin(), sentences[i].end(), ' ') + 1;
            ans = max<int>(ans, cnt);
        }
        return ans;
    }
};
