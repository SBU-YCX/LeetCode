//  Topic   : 2135. Count Words Obtained After Adding a Letter
//  Author  : YCX
//  Time    : O((M + N) * K) [K is the average length of each word]
//  Space   : O(M * K + K)


class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int m = startWords.size(), n = targetWords.size(), ans = 0;
        unordered_set<string> freq;
        for (int i = 0; i < m; i++)
        {
            string f = string(26, '0');
            for (auto& c : startWords[i])
                f[c - 'a'] = '1';
            freq.insert(f);
        }
        for (auto& w : targetWords)
        {
            string query = string(26, '0');
            for (auto& c : w)
                query[c - 'a'] = '1';
            for (auto& c : w)
            {
                query[c - 'a'] = '0';
                if (freq.count(query))
                {
                    ans++;
                    break;
                }
                query[c - 'a'] = '1';
            }
        }
        return ans;
    }
};
