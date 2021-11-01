//  Topic   ：2039. The Time When the Network Becomes Idle (https://leetcode.com/problems/the-time-when-the-network-becomes-idle/)
//  Author  : YCX
//  Time    : O(M + N)
//  Space   : O(M + N)


class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size(), m = edges.size(), ans = 0;
        vector<int> dist(n, INT_MAX);
        unordered_map<int, vector<int>> connect;
        for (int i = 0; i < m; i++)
        {
            connect[edges[i][0]].push_back(edges[i][1]);
            connect[edges[i][1]].push_back(edges[i][0]);
        }
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int p = q.front();
            int d = dist[p];
            q.pop();
            for (auto i : connect[p])
                if (dist[i] > d + 1)
                {
                    dist[i] = d + 1;
                    q.push(i);
                }
        }
        for (int i = 1; i < n; i++)
            ans = max<int>(ans, (dist[i] * 2 - 1) / patience[i] * patience[i] + dist[i] * 2);
        return ans + 1;
    }
};
