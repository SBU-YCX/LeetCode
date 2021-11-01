//  Topic   ：2038. Remove Colored Pieces if Both Neighbors are the Same Color (https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length(), nA = 0, nB = 0, l = 0;
        for (int r = 1; r <= n; r++)
        {
            if (r == n || colors[r] != colors[l])
            {
                if (colors[l] == 'A')
                    nA += max<int>(r - l - 2, 0);
                else
                    nB += max<int>(r - l - 2, 0);
                l = r;
            }
        }
        return nA > nB;
    }
};
