//  Topic   : 1816. Truncate Sentence
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string truncateSentence(string s, int k) {
        int l = 0, r = s.length(), m = 0;
        while (l < r)
        {
            int p = s.find(' ', l);
            if (p == -1)
                p = r;
            m++;
            if (m == k)
            {
                r = p;
                break;
            }
            l = p + 1;
        }
        return s.substr(0, r);
    }
};
