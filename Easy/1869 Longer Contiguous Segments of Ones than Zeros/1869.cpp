//  Topic   : 1869. Longer Contiguous Segments of Ones than Zeros
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool checkZeroOnes(string s) {
        int n0 = 0, n1 = 0;
        int n = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                n += 1;
            else
            {
                if (s[i - 1] == '0')
                    n0 = max<int>(n0, n);
                else
                    n1 = max<int>(n1, n);
                n = 1;
            }
        }
        if (s[s.length() - 1] == '0')
            n0 = max<int>(n0, n);
        else
            n1 = max<int>(n1, n);
        return (n1 > n0);
    }
};
