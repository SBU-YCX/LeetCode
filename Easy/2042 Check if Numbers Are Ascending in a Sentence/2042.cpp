//  Topic   : 2042. Check if Numbers Are Ascending in a Sentence (https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool areNumbersAscending(string s) {
        s += " ";
        int i = 0, n = s.length(), p = 0;
        while (i < n)
        {
            int j = s.find(' ', i);
            string num = s.substr(i, j - i);
            bool isNum = true;
            for (auto k : num)
                if (k > '9' || k < '0')
                {
                    isNum = false;
                    break;
                }
            if (isNum)
            {
                int q = stoi(num);
                if (q <= p)
                    return false;
                p = q;
            }
            i = j + 1;
        }
        return true;
    }
};
