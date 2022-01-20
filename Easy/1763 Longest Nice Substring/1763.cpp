//  Topic   : 1763. Longest Nice Substring
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string longestNiceSubstring(string s) {
        return longestNiceSubstring(s, 0, s.length());
    }
    
private: 
    string longestNiceSubstring(string s, int start, int end)
    {
        vector<vector<int>> freq(26, vector<int>(2, 0));
        for (int i = start; i < end; i++)
        {
            if (s[i] <= 'z' && s[i] >= 'a')
                freq[s[i] - 'a'][0] = 1;
            else if (s[i] <= 'Z' && s[i] >= 'A')
                freq[s[i] - 'A'][1] = 1;
        }
        string ans = "";
        int begin = start - 1;
        for (int i = start; i <= end; i++)
        {
            if (i == end || (s[i] <= 'Z' && s[i] >= 'A' && freq[s[i] - 'A'][0] + freq[s[i] - 'A'][1] == 1) || (s[i] <= 'z' && s[i] >= 'a' && freq[s[i] - 'a'][0] + freq[s[i] - 'a'][1] == 1))
            {
                if (i == end && begin == start - 1)
                    return s.substr(start, end - start);
                string res = longestNiceSubstring(s, begin + 1, i);
                if (res.length() > ans.length())
                    ans = res;
                begin = i;
            }
        }
        return ans;
    }
};
