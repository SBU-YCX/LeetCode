//  Topic   ：2059. Minimum Operations to Convert Number (https://leetcode.com/problems/minimum-operations-to-convert-number/)
//  Author  : YCX
//  Time    : O(1000 * N)
//  Space   : O(1000)


class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int ans = INT_MAX;
        vector<int> num_x(1001, INT_MAX);
        num_x[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int x = q.front(), m = num_x[x];
            q.pop();
            for (auto i : nums)
            {
                int a = x + i;
                if (a <= 1000 && a >= 0 && num_x[a] > m + 1)
                {
                    num_x[a] = m + 1;
                    q.push(a);
                }
                else if (a == goal)
                    ans = min<int>(ans, m + 1);
                a = x - i;
                if (a <= 1000 && a >= 0 && num_x[a] > m + 1)
                {
                    num_x[a] = m + 1;
                    q.push(a);
                }
                else if (a == goal)
                    ans = min<int>(ans, m + 1);
                a = x ^ i;
                if (a <= 1000 && a >= 0 && num_x[a] > m + 1)
                {
                    num_x[a] = m + 1;
                    q.push(a);
                }
                else if (a == goal)
                    ans = min<int>(ans, m + 1);
            }
        }
        if (goal <= 1000 && goal >= 0)
            ans = min<int>(ans, num_x[goal]);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
