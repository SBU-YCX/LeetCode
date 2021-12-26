// Topic     : 2092. Find All People With Secret (https://leetcode.com/problems/find-all-people-with-secret/)
// Author    : YCX
// Time      : O(NlogN + M)
// Space     : O(N + M)


class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knows(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> tell;
        for (auto& p : meetings)
        {
            tell[p[0]].push_back({p[1], p[2]});
            tell[p[1]].push_back({p[0], p[2]});
        }
        knows[0] = 0;
        knows[firstPerson] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> spread;
        spread.push({0, 0});
        spread.push({firstPerson, 0});
        while (!spread.empty())
        {
            int cur = spread.top().first;
            int time = spread.top().second;
            spread.pop();
            for (auto& nxt : tell[cur])
                if (nxt.second < knows[nxt.first] && nxt.second >= time)
                {
                    knows[nxt.first] = nxt.second;
                    spread.push({nxt.first, nxt.second});
                }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (knows[i] < INT_MAX)
                ans.push_back(i);
        return ans;
    }
    
private: 
    struct cmp
    {
        bool operator() (pair<int, int>& a, pair<int, int>& b)
        {
            return a.second < b.second;
        }
    };
};
