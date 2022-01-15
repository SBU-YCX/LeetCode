//  Topic   : 1796. Second Largest Digit in a String
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(10)


class Solution {
public:
    int secondHighest(string s) {
        vector<int> cache(10, 0);
        for (int i = 0; i < s.length(); i++)
            if (s[i] <= '9' && s[i] >= '0')
                cache[s[i] - '0'] = 1;
        int second = 0;
        for (int j = 9; j >= 0; j--)
            if (cache[j] == 1)
            {
                second += 1;
                if (second == 2)
                    return j;
            }
        return -1;
    }
};
