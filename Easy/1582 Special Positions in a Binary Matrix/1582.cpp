//  Topic   : 1582. Special Positions in a Binary Matrix
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(N ^ 2)


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> numCol(m, 0);
        unordered_map<int, vector<int>> numRow;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1)
                {
                    numRow[j].push_back(i);
                    numCol[i] += 1;
                }
        int ans = 0;
        unordered_map<int, vector<int>>::iterator iter = numRow.begin();
        while (iter != numRow.end())
        {
            if (iter->second.size() == 1 && numCol[iter->second[0]] == 1)
                ans += 1;
            iter++;
        }
        return ans;
    }
};
