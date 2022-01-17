//  Topic   : 2139. Minimum Moves to Reach Target Score
//  Author  : YCX
//  Time    : O(logN)
//  Space   : O(1)


class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target != 1)
        {
            if (maxDoubles == 0)
            {
                ans += (target - 1);
                break;
            }
            if (target % 2 == 1)
            {
                target -= 1;
                ans++;
            }
            else
            {
                target /= 2;
                ans++;
                maxDoubles--;
            }
        }
        return ans;
    }
};
