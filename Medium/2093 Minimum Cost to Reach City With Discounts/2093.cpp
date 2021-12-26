//  Topic   : 2093. Minimum Cost to Reach City With Discounts (https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/)
//  Author  : YCX
//  Time    : O(MlogM) [M = N ^ 2]
//  Space   : O(N * K + M)


class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> roads(n);
        for (auto& r : highways)
        {
            roads[r[0]].push_back({r[1], r[2]});
            roads[r[1]].push_back({r[0], r[2]});
        }
        vector<vector<int>> dp(n, vector<int>(discounts + 1, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        pq.push({0, {0, discounts}});
        while (!pq.empty())
        {
            int city = pq.top().first;
            int cost = pq.top().second.first;
            int disc = pq.top().second.second;
            if (city == n - 1)
                break;
            pq.pop();
            for (auto& p : roads[city])
            {
                int nxt = p.first, toll = p.second;
                if (cost + toll < dp[nxt][disc])
                {
                    dp[nxt][disc] = cost + toll;
                    pq.push({nxt, {dp[nxt][disc], disc}});
                }
                toll /= 2;
                if (disc > 0 && cost + toll < dp[nxt][disc - 1])
                {
                    dp[nxt][disc - 1] = cost + toll;
                    pq.push({nxt, {dp[nxt][disc - 1], disc - 1}});
                }
            }
        }
        if (pq.empty())
            return -1;
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

private: 
    struct cmp
    {
        bool operator() (pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
        {
            return a.second.first > b.second.first;
        }
    };
};
