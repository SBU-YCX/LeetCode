//  Topic   : 2086. Minimum Number of Buckets Required to Collect Rainwater from Houses (https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.length(), ans = 0;
        for (int i = 0; i < n - 2; i++)
            if (street[i] == 'H' && street[i + 1] == '.' && street[i + 2] == 'H')
            {
                ans++;
                street[i] = 'X';
                street[i + 1] = 'B';
                street[i + 2] = 'X';
            }
        for (int i = 0; i < n; i++)
            if (street[i] == 'H')
            {
                if (i > 0 && street[i - 1] == '.')
                {
                    ans++;
                    street[i] = 'X';
                    street[i - 1] = 'B';
                }
                else if (i < n - 1 && street[i + 1] == '.')
                {
                    ans++;
                    street[i] = 'X';
                    street[i + 1] = 'B';
                }
            }
        for (int i = 0; i < n; i++)
            if (street[i] == 'H')
                return -1;
        return ans;
    }
};
