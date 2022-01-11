//  Topic   : 1886. Determine Whether Matrix Can Be Obtained By Rotation
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(M * N)


class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> tmp = mat;
        for (int i = 0; i <= 3; i++)
        {
            if (equal(tmp, target))
                return true;
            tmp = rotate(tmp);
        }
        return false;
    }
    
private: 
    vector<vector<int>> rotate(vector<vector<int>> mat) {
        int n = mat.size();
        vector<vector<int>> new_mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                new_mat[j][n - 1 - i] = mat[i][j];
        return new_mat;
    }
    
    bool equal(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] != b[i][j])
                    return false;
        return true;
    }
};
