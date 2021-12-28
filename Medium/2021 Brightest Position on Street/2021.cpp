//  Topic   ：2021. Brightest Position on Street (https://leetcode.com/problems/brightest-position-on-street/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        int n = lights.size(), s = 0, t = 0, k = INT_MIN, ans = 0, bright = 0;
        for (int i = 0; i < n; i++)
        {
            s = lights[i][0] - lights[i][1];
            t = lights[i][0] + lights[i][1];
            lights[i][0] = s;
            lights[i][1] = t;
            k = max<int>(k, t);
            ans = min<int>(ans, s);
        }
        sort(lights.begin(), lights.end());
        s = 0, t = ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (; t <= k;)
        {
            t = lights[s][0];
            while (!pq.empty() && pq.top() < t)
                pq.pop();
            while (s < n && lights[s][0] == t)
            {
                pq.push(lights[s][1]);
                s++;
            }
            int m = pq.size();
            if (m > bright)
            {
                bright = m;
                ans = t;
            }
            if (s == n)
                break;
        }
        return ans;
    }
};
