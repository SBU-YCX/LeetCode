//  Topic   : 2103. Rings and Rods (https://leetcode.com/problems/rings-and-rods/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length(), m = n / 2, ans = 0;
        unordered_map<int, string> rr;
        for (int i = 0; i < n; i += 2)
        {
            char c = rings[i];
            int p = rings[i + 1] - '0';
            if (!rr.count(p))
                rr[p] = "000";
            if (c == 'B')
                rr[p][0] = '1';
            else if (c == 'G')
                rr[p][1] = '1';
            else
                rr[p][2] = '1';
        }
        for (auto k : rr)
            if (k.second == "111")
                ans++;
        return ans;
    }
};
