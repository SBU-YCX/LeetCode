// Topic     : 2050. Parallel Courses III (https://leetcode.com/problems/parallel-courses-iii/)
// Author    : YCX
// Time      : O(M + N)
// Space     : O(M + N)


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m = relations.size(), k = 0, ans = 0;
        vector<int> prev(n, 0);
        unordered_map<int, vector<int>> next;
        for (int i = 0; i < m; i++)
        {
            next[relations[i][0]].push_back(relations[i][1]);
            prev[relations[i][1] - 1]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
            if (prev[i] == 0)
                pq.push({time[i], i + 1});
        while (!pq.empty())
        {
            int end = pq.top().first;
            int course = pq.top().second;
            pq.pop();
            ans = max<int>(ans, end);
            for (auto i : next[course])
            {
                prev[i - 1]--;
                if (prev[i - 1] == 0)
                    pq.push({time[i - 1] + end, i});
            }
        }
        return ans;
    }
};
