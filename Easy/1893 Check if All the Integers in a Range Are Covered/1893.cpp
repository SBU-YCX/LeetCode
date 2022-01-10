//  Topic   : 1893. Check if All the Integers in a Range Are Covered
//  Author  : YCX
//  Time    : O(N + M)
//  Space   : O(M)


class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> occupy(52, 0);
        int n = ranges.size();
        for (int i = 0; i < ranges.size(); i++)
        {
            occupy[ranges[i][0]]++;
            occupy[ranges[i][1] + 1]--;
        }
        for (int i = 1; i <= right; i++)
        {
            occupy[i] += occupy[i - 1];
            if (i >= left && occupy[i] == 0)
                return false;
        }
        return true;
    }
};
