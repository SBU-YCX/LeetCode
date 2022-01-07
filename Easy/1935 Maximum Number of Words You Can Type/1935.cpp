//  Topic   : 1935. Maximum Number of Words You Can Type
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(M)


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (auto& c : brokenLetters)
            broken[c - 'a'] = true;
        int ans = 0, n = text.length();
        bool success = true;
        for (int i = 0; i <= n; i++)
        {
            if (i == n || text[i] == ' ')
            {
                if (success)
                    ans++;
                success = true;
            }
            else if (broken[text[i] - 'a'])
                success = false;
        }
        return ans;
    }
};
