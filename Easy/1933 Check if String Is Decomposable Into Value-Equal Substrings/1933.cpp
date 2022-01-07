//  Topic   : 1933. Check if String Is Decomposable Into Value-Equal Substrings
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool isDecomposable(string s) {
        int n = s.length(), num2 = 0, i = 0;
        for (; i <= n - 2; i += 3)
        {
            if (s[i] == s[i + 1])
            {
                if (i == n - 2)
                {
                    if (num2 == 1)
                        return false;
                    else 
                        return true;
                }
                if (s[i] != s[i + 2])
                {
                    if (num2 == 1)
                        return false;
                    num2 += 1;
                    i -= 1;
                }
            }
            else
                return false;
        }
        if (i != n || num2 == 0)
            return false;
        return true;
    }
};
