//  Topic   ：2063. Vowels of All Substrings (https://leetcode.com/problems/vowels-of-all-substrings/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    long long countVowels(string word) {
        long long n = word.length(), ans = 0;
        for (int i = 0; i < n; i++)
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
                ans += (n - i) * (i + 1);
        return ans;
    }
};
