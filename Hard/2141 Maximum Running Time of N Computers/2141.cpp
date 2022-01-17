// Topic     : 2141. Maximum Running Time of N Computers
// Author    : YCX 
// Time      : O(NlogN) 
// Space     : O(N)


class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long sum = accumulate(batteries.begin(), batteries.end(), 0L);
        int m = batteries.size(), k = 0;
        while(batteries[m - 1 - k] > sum / (n - k))
        {
            sum -= batteries[m - 1 - k];
            k++;
        }
        return (sum / (n - k));
    }
};
