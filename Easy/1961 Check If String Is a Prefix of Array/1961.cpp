//  Topic   : 1961. Check If String Is a Prefix of Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string t = "";
        for (int i = 0; i < words.size(); i++)
        {
            t += words[i];
            if (s == t)
                return true;
        }
        return false;
    }
};
