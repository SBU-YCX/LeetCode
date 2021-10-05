//  Topic   ：1249. Minimum Remove to Make Valid Parentheses (https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "", t = "";
        int n = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                n += 1;
                t += s[i];
            }
            else if (s[i] == ')')
            {
                if (n >= 1)
                {
                    n -= 1;
                    t += s[i];
                }
            }
            else
                t += s[i];
        }
        n = 0;
        for (int j = t.length() - 1; j >= 0; j--)
        {
            if (t[j] == ')')
            {
                n += 1;
                ans += t[j];
            }
            else if (t[j] == '(')
            {
                if (n >= 1)
                {
                    n -= 1;
                    ans += t[j];
                }
            }
            else
                ans += t[j];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
