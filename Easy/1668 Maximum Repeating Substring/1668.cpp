//  Topic   : 1668. Maximum Repeating Substring
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(N)


class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m = sequence.length(), n = word.length();
        if (m < n)
            return 0;
        int ans = 0;
        vector<int> match(m + 1, 0);
        for (int i = m - n; i >= 0; i--)
        {
            if (sequence.substr(i, n) == word)
                match[i] = 1 + match[i + n];
            else
                match[i] = 0;
            ans = max<int>(ans, match[i]);
        }
        return ans;       
    }
};
