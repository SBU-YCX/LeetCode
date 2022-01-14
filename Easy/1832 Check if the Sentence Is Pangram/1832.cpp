//  Topic   : 1832. Check if the Sentence Is Pangram
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(26)


class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> appear(26, 0);
        for (int i = 0; i < sentence.length(); i++)
            appear[sentence[i] - 'a'] = 1;
        for (int i = 0; i < 26; i++)
            if (appear[i] == 0)
                return false;
        return true;
    }
};
