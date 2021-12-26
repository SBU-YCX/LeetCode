//  Topic   : 2120. Execution of All Suffix Instructions Staying in a Grid (https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/)
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(1)


class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.length();
        int ld = -startPos[1], rd = n - 1 - startPos[1], ud = -startPos[0], bd = n - 1 - startPos[0];
        unordered_map<char, pair<int, int>> dirs = {{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
        vector<vector<int>> move(m, vector<int>(2, 0));
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++)
        {
            int dx = 0, dy = 0;
            for (int j = i; j < m; j++)
            {
                dx += dirs[s[j]].first;
                dy += dirs[s[j]].second;
                if (dx < ud || dx > bd || dy < ld || dy > rd)
                {
                    ans[i] = j - i;
                    break;
                }
            } 
            if (ans[i] == -1)
                ans[i] = m - i;
        }   
        return ans;
    }
};
