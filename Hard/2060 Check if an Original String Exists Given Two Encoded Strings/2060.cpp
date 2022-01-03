// Topic     : 2060. Check if an Original String Exists Given Two Encoded Strings (https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2060%20Check%20if%20an%20Original%20String%20Exists%20Given%20Two%20Encoded%20Strings)
// Time      : O(M * N * 2000) 
// Space     : O(M * N * 2000)


class Solution {
public:
    
    bool possiblyEquals(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<vector<bool>>> matched(n1 + 1, vector<vector<bool>>(n2 + 1, vector<bool>(2000, false)));
        return possiblyEquals(s1, s2, 0, 0, 0, matched);
    }
    
private: 
    bool possiblyEquals(string& s1, string& s2, int i, int j, int d, vector<vector<vector<bool>>>& matched)
    {
        int n1 = s1.length(), n2 = s2.length();
        if (i == n1 && j == n2)
            return (d == 0);
        if (!matched[i][j][d + 1000])
        {
            matched[i][j][d + 1000] = true;
            if (i < n1 && isdigit(s1[i]))
            {
                int nd = 0;
                while (i < n1 && isdigit(s1[i]))
                {
                    nd = nd * 10 + (s1[i] - '0');
                    i++;
                    if (possiblyEquals(s1, s2, i, j, d - nd, matched))
                        return true;
                }
                return false;
            }    
            if (j < n2 && isdigit(s2[j]))
            {
                int nd = 0;
                while (j < n2 && isdigit(s2[j]))
                {
                    nd = nd * 10 + (s2[j] - '0');
                    j++;
                    if (possiblyEquals(s1, s2, i, j, d + nd, matched))
                        return true;
                }
                return false;
            }
            if (d > 0)
                return (i < n1 && possiblyEquals(s1, s2, i + 1, j, d - 1, matched));
            else if (d < 0)
                return (j < n2 && possiblyEquals(s1, s2, i, j + 1, d + 1, matched));
            else
                return (i < n1 && j < n2 && s1[i] == s2[j] && possiblyEquals(s1, s2, i + 1, j + 1, d, matched));
        }
        return false;
    }
};
