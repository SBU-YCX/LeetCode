//  Topic   : 1732. Find the Highest Altitude
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(), ans = max<int>(0, gain[0]);
        for (int i = 1; i < n; i++)
        {
            gain[i] += gain[i - 1];
            ans = max<int>(ans, gain[i]);
        }
        return ans;
    }
};
