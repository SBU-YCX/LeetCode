//  Topic   : 1652. Defuse the Bomb
//  Author  : YCX
//  Time    : O(N + K)
//  Space   : O(N)


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int m = code.size();
        vector<int> sum(m, 0);
        for (int i = 0; i < abs(k); i++)
            sum[0] += code[i];
        for (int j = 1; j < m; j++)
            sum[j] = (sum[j - 1] - code[j - 1] + code[(j - 1 + abs(k)) % m]);
        for (int i = 0; i < m; i++)
        {
            if (k > 0)
                ans.push_back(sum[(i + 1) % m]);
            else if (k < 0)
                ans.push_back(sum[(m + i + k) % m]);
            else
                ans.push_back(0);
        }
        return ans;
    }
};
