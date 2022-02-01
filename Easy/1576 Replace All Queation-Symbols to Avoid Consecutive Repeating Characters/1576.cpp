//  Topic   : 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
//  Author  : YCX
//  Time    : O(26 * N)
//  Space   : O(1)


class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '?')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (i == 0)
                    {
                        if (j + 'a' != s[i + 1])
                        {
                            s[i] = j + 'a';
                            break;
                        }
                    } 
                    else if (i == s.length() - 1)
                    {
                        if (j + 'a' != s[i - 1])
                        {
                            s[i] = j + 'a';
                            break;
                        }
                    }
                    else
                    {
                        if (j + 'a' != s[i + 1] && j + 'a' != s[i - 1])
                        {
                            s[i] = j + 'a';
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};
