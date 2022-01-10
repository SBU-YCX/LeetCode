//  Topic   : 1897. Redistribute Characters to Make All Strings Equal
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(1)


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26, 0);
        int m = words.size();
        for (int i = 0; i < m; i++)
        {
            int n = words[i].size();
            for (int j = 0; j < n; j++)
                freq[words[i][j] - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++)
            if (freq[i] % m != 0)
                return false;
        return true;
    }
};
