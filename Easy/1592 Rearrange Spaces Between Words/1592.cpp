//  Topic   : 1592. Rearrange Spaces Between Words
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string reorderSpaces(string text) {
        int num = 0, n = text.length();
        queue<string> words;
        string s = "";
        for (int i = 0; i < n; i++)
        {
            if (text[i] == ' ')
            {
                if (s.length() > 0)
                    words.push(s);
                num += 1;
                s = "";
            }
            else
                s += text[i];
        }
        if (s.length() > 0)
            words.push(s);
        string ans = "";
        if (words.size() == 1)
        {
            ans += words.front();
            for (int i = 0; i < num; i++)
                ans += " ";
            return ans;
        }
        int k = num / (words.size() - 1), r = num % (words.size() - 1);
        string ks = "", rs = "";
        for (int i = 0; i < k; i++)
            ks += " ";
        for (int j = 0; j < r; j++)
            rs += " ";
        while (!words.empty())
        {
            ans += words.front();
            words.pop();
            if (words.empty())
                break;
            ans += ks;
        }
        ans += rs;
        return ans;
    }
};
