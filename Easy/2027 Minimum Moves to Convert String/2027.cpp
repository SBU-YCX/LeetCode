//  Topic   : 2027. Minimum Moves to Convert String (https://leetcode.com/problems/minimum-moves-to-convert-string/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length(), l = 0, r = n - 1, ans = 0;
        while (r >= 0 && s[r] == 'O')
            r--;
        while (l <= r)
        {
            if (s[l] == 'O')
                l++;
            else
            {
                ans += 1;
                l += 3;
            }
        }
        return ans;
    }
};
