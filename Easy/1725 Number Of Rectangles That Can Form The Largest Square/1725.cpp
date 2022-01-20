//  Topic   : 1725. Number Of Rectangles That Can Form The Largest Square
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size(), maxs = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            int side = min<int>(rectangles[i][0], rectangles[i][1]);
            if (side > maxs)
            {
                maxs = side;
                ans = 1;
            }
            else if (side == maxs)
                ans++;
        }
        return ans;
    }
};
