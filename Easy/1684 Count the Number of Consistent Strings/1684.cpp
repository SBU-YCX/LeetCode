//  Topic   : 1684. Count the Number of Consistent Strings
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(N)


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        vector<int> allow(26, 0);
        int is;
        for (int i = 0; i < allowed.length(); i++)
            allow[allowed[i] - 'a'] = 1;
        for (int j = 0; j < words.size(); j++)
        {
            is = true;
            for (int k = 0; k < words[j].length(); k++)
                if (allow[words[j][k] - 'a'] == 0)
                {
                    is = false;
                    break;
                }
            if (is)
                ans += 1;
        }
        return ans;
    }
};
