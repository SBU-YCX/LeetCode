//  Topic   : 1560. Most Visited Sector in a Circular Track
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(N)


class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> visit(n, 0);
        visit[rounds[0] - 1] = 1;
        int m = rounds.size(), most = 0;
        for (int i = 0; i < m - 1; i++)
        {
            int end, start = rounds[i];
            if (rounds[i + 1] >= start)
                end = rounds[i + 1];
            else
                end = rounds[i + 1] + n;
            for (int j = start; j <= end - 1; j++)
            {
                visit[j % n]++;
                most = max<int>(most, visit[j % n]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (visit[i] == most)
                ans.push_back(i + 1);
        return ans;
    }
};
