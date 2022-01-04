//  Topic   : 2000. Reverse Prefix of Word
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int p = word.find(ch) + 1;
        reverse(word.begin(), word.begin() + p);
        return word;
    }
};
