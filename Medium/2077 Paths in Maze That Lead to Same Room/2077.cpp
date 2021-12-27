//  Topic   : 2077. Paths in Maze That Lead to Same Room (https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/)
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(N)


class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        for (auto& e : corridors)
        {
            connect[e[0] - 1][e[1] - 1] = true;
            connect[e[1] - 1][e[0] - 1] = true;
        }
        int ans = 0;
        for (auto& e : corridors)
        {
            int n1 = e[0] - 1, n2 = e[1] - 1;
            for (int i = 0; i < n; i++)
                if (connect[i][n1] && connect[i][n2])
                    ans++;
        }
        return (ans / 3);
    }
};
