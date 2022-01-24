//  Topic   : 1704. Determine if String Halves Are Alike
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool halvesAreAlike(string s) {
        int m = s.length();
        int j = m - 1;
        for (int i = 0; i < m / 2; i++)
        {
            if (isVowel(s[i]))
            {
                if (j < m / 2)
                    return false;
                while (!isVowel(s[j]))
                {
                    j--;
                    if (j < m / 2)
                        return false;
                }
                j--;
            }
        }
        for (; j >= m / 2; j--)
            if (isVowel(s[j]))
                return false;
        return true;
    }
    
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};
