//  Topic   : 1974. Minimum Time to Type Word Using Special Typewriter
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0, n = word.length();
        char p = 'a';
        for (int i = 0; i < n; i++)
        {
            if (word[i] != p)
            {
                int dist = abs(word[i] - p);
                ans += min<int>(dist, 26 - dist);
                p = word[i];
            }
            ans += 1;
        }
        return ans;
    }
};
