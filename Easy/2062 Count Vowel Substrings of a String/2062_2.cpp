//  Topic   : 2062. Count Vowel Substrings of a String (https://leetcode.com/problems/count-vowel-substrings-of-a-string/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countVowelSubstrings(string word) {
        int l = 0, r = word.length(), p = 0, q = 0, v = 0, ans = 0;
        unordered_map<char, int> num;
        while (l < r)
        {
            if (word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u')
            {
                num[word[l]]++;
                if (num[word[l]] == 1)
                    v++;
                while (q < l && v == 5)
                {
                    num[word[q]]--;
                    if (num[word[q]] == 0)
                        v--;
                    q++;
                }
                ans += (q - p);
            }
            else
            {
                p = q = l + 1;
                v = 0;
                num['a'] = num['e'] = num['i'] = num['o'] = num['u'] = 0;
            }
            l++;
        }
        return ans;
    }
};
