//  Topic   ：2054. Two Best Non-Overlapping Events (https://leetcode.com/problems/two-best-non-overlapping-events/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int m = events.size(), maxv = 0, ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto i : events)
        {
            while (!q.empty() && q.top().first < i[0])
            {
                maxv = max<int>(maxv, q.top().second);
                q.pop();
            }
            ans = max<int>(ans, maxv + i[2]);
            q.push({i[1], i[2]});
        }
        return ans;
    }
    
private: 
    struct cmp
    {
        bool operator() (pair<int, int>& a, pair<int, int>& b)
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
};
