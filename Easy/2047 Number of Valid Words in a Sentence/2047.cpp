//  Topic   : 2047. Number of Valid Words in a Sentence (https://leetcode.com/problems/number-of-valid-words-in-a-sentence/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int countValidWords(string sentence) {
        int l = 0, r = sentence.length(), ans = 0; 
        while (l < r)
        {
            int p = sentence.find(' ', l);
            if (p == -1)
                p = r;
            string word = sentence.substr(l, p - l);
            if (word.length() != 0 && isValid(word))
                ans++;
            l = p + 1;
        }
        return ans;
    }

private: 
    bool isValid(string word)
    {
        int n = word.length(), np = 0, nh = 0;
        for (int i = 0; i < n; i++)
        {
            if (word[i] <= '9' && word[i] >= '0')
                return false;
            else if (word[i] == '-')
            {
                nh++;
                if (nh >= 2)
                    return false;
                if (i == 0)
                    return false;
                else if (i == n - 1)
                    return false;
                else if ((word[i - 1] > 'z' || word[i - 1] < 'a') || (word[i + 1] > 'z' || word[i + 1] < 'a'))
                    return false;
            }
            else if (word[i] == '!' || word[i] == '.' || word[i] == ',')
            {
                np++;
                if (np >= 2 || i != n - 1)
                    return false;
            }
        }
        return true;
    }
};
