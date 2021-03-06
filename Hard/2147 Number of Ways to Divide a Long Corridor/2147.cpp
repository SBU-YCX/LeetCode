// Topic     : 2147. Number of Ways to Divide a Long Corridor
// Author    : YCX 
// Time      : O(N) 
// Space     : O(1)


class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        long long ns = 0, np = 0, ans = 1, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
            {
                ns++;
                if (!(ns % 2))
                {
                    if (ns != 2)
                        ans = (ans * (np + 1)) % mod;
                    np = 0;
                }
            }
            else if (!(ns % 2))
                np++;
        }
        if (ns % 2 || ns == 0)
            return 0;
        return ans;
    }
};
