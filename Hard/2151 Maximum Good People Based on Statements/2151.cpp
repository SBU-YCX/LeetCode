// Topic     : 2151. Maximum Good People Based on Statements
// Author    : YCX 
// Time      : O(N * 2 ^ N) 
// Space     : O(N * 2 ^ N)


class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        unordered_map<int, vector<int>> can, cannot;
        int n = statements.size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (statements[i][j] == 1)
                    can[i].push_back(j);
                else if (statements[i][j] == 0)
                {
                    cannot[j].push_back(i);
                    cannot[i].push_back(j);
                }
            }
        vector<int> good(n, 0);
        backtracking(can, cannot, 0, n, good, ans);
        return ans;
    }
    
private: 
    void backtracking(unordered_map<int, vector<int>>& can, unordered_map<int, vector<int>>& cannot, int k, int& n, vector<int> good, int& ans)
    {
        if (k == n)
        {
            int cur = 0;
            for (auto& i : good)
                if (i == 1)
                    cur++;
            ans = max<int>(ans, cur);
            return;
        }
        if (good[k] == -1)
            backtracking(can, cannot, k + 1, n, good, ans);
        else if (good[k] == 1)
        {
            for (auto& j : can[k])
            {
                if (good[j] == -1)
                    return;
                good[j] = 1;
            }
            for (auto& j : cannot[k])
            {
                if (good[j] == 1)
                    return;
                good[j] = -1;
            }
            backtracking(can, cannot, k + 1, n, good, ans);
        }
        else
        {
            good[k] = 1;
            backtracking(can, cannot, k, n, good, ans);
            good[k] = -1;
            backtracking(can, cannot, k, n, good, ans);
        }
    }
};
