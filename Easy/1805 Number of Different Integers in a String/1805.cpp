//  Topic   : 1816. Truncate Sentence
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> ans;
        string num = "";
        word += " ";
        bool zero = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (isdigit(word[i]))
            {
                if (word[i] == '0' && num.length() == 0)
                {
                    zero = true;
                    continue;
                }
                num += word[i];
            }
            else
            {
                if (num.length() == 0 && zero)
                    num += '0';
                if (num.length() != 0)
                    ans.insert(num);
                num = "";
                zero = false;
            }
        }
        return ans.size();
    }
};
