//  Topic   : 1768. Merge Strings Alternately
//  Author  : YCX
//  Time    : O(max(M, N))
//  Space   : O(1)


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        string ans = "";
        if (m >= n)
        {
            for (int i = 0; i < n; i++)
            {
                ans += word1[i];
                ans += word2[i];
            }
            for (int j = n; j < m; j++)
                ans += word1[j];
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                ans += word1[i];
                ans += word2[i];
            }
            for (int j = m; j < n; j++)
                ans += word2[j];
        }
        return ans;
    }
};
