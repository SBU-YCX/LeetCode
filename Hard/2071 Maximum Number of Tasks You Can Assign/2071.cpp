// Topic     : 2071. Maximum Number of Tasks You Can Assign (https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2071%20Maximum%20Number%20of%20Tasks%20You%20Can%20Assign)
// Time      : O(logK * KlogK) where K = min(M, N) 
// Space     : O(K)


class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int l = 0, r = min<int>(tasks.size(), workers.size());
        while (l < r)
        {
            int m = (l + r + 1) / 2, k = 0;
            multiset<int> s(workers.end() - m, workers.end());
            for (int i = m - 1; i >= 0; i--)
            {
                auto j = prev(s.end());
                if (*j < tasks[i])
                {
                    j = s.lower_bound(tasks[i] - strength);
                    if (j == s.end() || ++k > pills)
                        break;
                }
                s.erase(j);
            }
            if (s.empty())
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
