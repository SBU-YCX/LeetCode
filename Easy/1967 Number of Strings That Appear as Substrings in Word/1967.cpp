//  Topic   : 1967. Number of Strings That Appear as Substrings in Word
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(1)


class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (int i = 0; i < patterns.size(); i++)
        {
            size_t found = word.find(patterns[i]);
            if (found != string::npos)
                ans += 1;
        } 
        return ans;
    }
};
