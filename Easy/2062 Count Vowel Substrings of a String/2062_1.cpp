//  Topic   : 2062. Count Vowel Substrings of a String (https://leetcode.com/problems/count-vowel-substrings-of-a-string/)
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(1)


class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            string flag = "00000";
            for (int j = i; j < n; j++)
            {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
                {
                    if (word[j] == 'a')
                        flag[0] = '1';
                    else if (word[j] == 'e')
                        flag[1] = '1';
                    else if (word[j] == 'i')
                        flag[2] = '1';
                    else if (word[j] == 'o')
                        flag[3] = '1';
                    else 
                        flag[4] = '1';
                    if (flag == "11111")
                        ans++;
                }
                else
                    break;
            }
        }
        return ans;
    }
};
