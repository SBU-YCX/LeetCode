//  Topic   : 2146. K Highest Ranked Items Within a Price Range
//  Author  : YCX
//  Time    : O(NlogK)
//  Space   : O(N)


class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<int> dirs = {0, 1, 0, -1, 0};
        priority_queue<tuple<int, int, int, int>> pq;
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = 0;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second, d = visited[x][y], v = grid[x][y];
            q.pop();
            if (v <= pricing[1] && v >= pricing[0])
            {
                pq.push({d, v, x, y});
                if (pq.size() > k)
                    pq.pop();
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0 || visited[nx][ny] <= d + 1)
                    continue;
                visited[nx][ny] = d + 1;
                q.push({nx, ny});
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            auto t = pq.top();
            ans.push_back({get<2>(t), get<3>(t)});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
