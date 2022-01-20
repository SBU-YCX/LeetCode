//  Topic   : 1742. Maximum Number of Balls in a Box
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> count(46, 0);
        for (int i = lowLimit; i <= highLimit; i++)
            count[box(i)] += 1;
        int ans = 0;
        for (int j = 1; j <= 45; j++)
            ans = max<int>(ans, count[j]);
        return ans;
    }
    
    int box(int ball) {
        int ans = 0;
        while (ball != 0)
        {
            ans += (ball % 10);
            ball /= 10;
        }
        return ans;
    }
};
