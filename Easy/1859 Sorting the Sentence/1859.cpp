//  Topic   : 1859. Sorting the Sentence
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string sortSentence(string s) {
        string ans = "";
        string word = "";
        int num = 1;
        vector<string> words(9);
        s += " ";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                int cur = word[word.length() - 1] - '0';
                num = max<int>(cur, num);
                words[cur - 1] = word.substr(0, word.length() - 1);
                word = "";
            }
            else
                word += s[i];
        }
        for (int i = 0; i < num; i++)
        {
            ans += words[i];
            if (i != num - 1)
                ans += " ";
        }
        return ans;
    }
};
