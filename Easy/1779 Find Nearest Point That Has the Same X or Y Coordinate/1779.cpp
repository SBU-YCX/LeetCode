//  Topic   : 1779. Find Nearest Point That Has the Same X or Y Coordinate
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int dist, n = points.size(), ans = 2e4, ans_coord = -1;
        for (int i = 0; i < n; i++)
        {
            if (points[i][0] == x)
            {
                dist = abs(points[i][1] - y);
                if (dist < ans)
                {
                    ans = dist;
                    ans_coord = i;
                }
            }
            if (points[i][1] == y)
            {
                dist = abs(points[i][0] - x);
                if (dist < ans)
                {
                    ans = dist;
                    ans_coord = i;
                }
            }
        }
        return ans_coord;
    }
};
