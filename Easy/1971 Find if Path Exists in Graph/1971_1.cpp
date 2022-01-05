//  Topic   : 1971. Find if Path Exists in Graph
//  Author  : YCX
//  Time    : O(M + N)
//  Space   : O(M + N)


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        int m = edges.size();
        unordered_map<int, vector<int>> connect;
        for (int i = 0; i < m; i++)
        {
            connect[edges[i][0]].push_back(edges[i][1]);
            connect[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == end)
                return true;
            for (auto& nxt : connect[cur])
                if (!visited[nxt])
                {
                    visited[nxt] = true;
                    q.push(nxt);
                }
        }
        return false;
    }
};
