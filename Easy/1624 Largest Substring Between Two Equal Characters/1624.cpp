//  Topic   : 1624. Largest Substring Between Two Equal Characters
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(26)


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<int> loc(26, -1);
        for (int i = 0; i < s.length(); i++)
        {
            if (loc[s[i] - 'a'] == -1)
                loc[s[i] - 'a'] = i;
            else
                ans = max<int>(ans, i - loc[s[i] - 'a'] - 1);
        }
        return ans;
    }
};
