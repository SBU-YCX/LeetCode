//  Topic   : 1688. Count of Matches in Tournament
//  Author  : YCX
//  Time    : O(logN)
//  Space   : O(1)


class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
                ans += n;
            }
            else
            {
                n /= 2;
                ans += n;
                n += 1;
            }
        }
        return ans;
    }
};
