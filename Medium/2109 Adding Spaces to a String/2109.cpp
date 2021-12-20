//  Topic   ：2109. Adding Spaces to a String (https://leetcode.com/problems/adding-spaces-to-a-string/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0, j = 0, m = s.length(), n = spaces.size();
        while (i < m)
        {
            if (j < n && i == spaces[j])
            {
                ans += ' ';
                j++;
            }
            ans += s[i];
            i++;
        }
        return ans;
    }
};
