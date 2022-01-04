//  Topic   : 2011. Final Value of Variable After Performing Operations
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0, m = operations.size();
        for (int i = 0; i < m; i++)
        {
            if (operations[i][1] == '+')
                ans++;
            else
                ans--;
        }
        return ans;
    }
};
