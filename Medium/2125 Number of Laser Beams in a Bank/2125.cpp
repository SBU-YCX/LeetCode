//  Topic   : 2125. Number of Laser Beams in a Bank (https://leetcode.com/problems/number-of-laser-beams-in-a-bank/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(1)


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].length(), ans = 0, prev = 0;
        for (int i = 0; i < m; i++)
        {
            int cur = count(bank[i].begin(), bank[i].end(), '1');
            if (cur != 0)
            {
                ans += (cur * prev);
                prev = cur;
            }
        }
        return ans;
    }
};
