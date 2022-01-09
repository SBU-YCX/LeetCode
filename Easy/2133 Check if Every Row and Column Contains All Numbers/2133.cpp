//  Topic   : 2133. Check if Every Row and Column Contains All Numbers
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(N)


class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            string s = string(n, '0');
            for (int j = 0; j < n; j++)
                s[matrix[i][j] - 1] = '1';
            if (s != string(n, '1'))
                return false;
        }
        for (int j = 0; j < n; j++)
        {
            string t = string(n, '0');
            for (int i = 0; i < n; i++)
                t[matrix[i][j] - 1] = '1';
            if (t != string(n, '1'))
                return false;
        }
        return true;
    }
};
