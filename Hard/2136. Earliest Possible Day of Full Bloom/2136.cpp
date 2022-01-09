// Topic     : 2136. Earliest Possible Day of Full Bloom
// Author    : YCX 
// Time      : O(NlogN) 
// Space     : O(N)


class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = growTime.size(), t = 0, ans = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
            pq.push({growTime[i], plantTime[i]});
        while (!pq.empty())
        {
            t += pq.top().second;
            ans = max<int>(ans, pq.top().first + t);
            pq.pop();
        }
        return ans;
    }
};
