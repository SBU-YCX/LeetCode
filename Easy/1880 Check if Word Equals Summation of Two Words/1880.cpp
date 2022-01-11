//  Topic   : 1880. Check if Word Equals Summation of Two Words
//  Author  : YCX
//  Time    : O(N1 + N2 + N3)
//  Space   : O(1)


class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < firstWord.length(); i++)
            a = a * 10 + (firstWord[i] - 'a');
        for (int j = 0; j < secondWord.length(); j++)
            b = b * 10 + (secondWord[j] - 'a');
        for (int k = 0; k < targetWord.length(); k++)
            c = c * 10 + (targetWord[k] - 'a');
        return (a + b == c);
    }
};
