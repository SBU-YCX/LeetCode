//  Topic   : 2131. Longest Palindrome by Concatenating Two Letter Words
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for (auto& s : words)
            m[s]++;
        int ans = 0;
        bool use = false;
        for (auto& p : m)
        {
            if (p.first[0] == p.first[1])
            {
                if (p.second % 2 == 1)
                {
                    if (!use)
                    {
                        ans += 2;
                        use = true;
                    }
                }
                ans += (4 * (p.second / 2));
            }
            else
            {
                string t = p.first;
                reverse(t.begin(), t.end());
                if (!m.count(t))
                    continue;
                int n = min<int>(p.second, m[t]);
                ans += 4 * n;
                p.second -= n;
                m[t] -= n;
                if (m[t] == 0)
                    m.erase(t);
            }
        }
        return ans;
    }
};
