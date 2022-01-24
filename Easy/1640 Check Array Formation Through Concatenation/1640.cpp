//  Topic   : 1640. Check Array Formation Through Concatenation
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(M)


class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> ht;
        int n = arr.size(), m = pieces.size();
        for (int i = 0; i < m; i++)
            ht[pieces[i][0]] = i;
        for (int i = 0; i < n;)
        {
            if (!ht.count(arr[i]))
                return false;
            int j = ht[arr[i]];
            for (int k = 0; k < pieces[j].size();)
            {
                if (arr[i] == pieces[j][k])
                {
                    i++;
                    k++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
