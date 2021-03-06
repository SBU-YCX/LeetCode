//  Topic   ：2064. Minimized Maximum of Products Distributed to Any Store (https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)
//  Author  : YCX
//  Time    : O(N * logM) [M is the maximum value of the array, <= 1e5]
//  Space   : O(1)


class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int r = *max_element(quantities.begin(), quantities.end()), l = 1, ans;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (ok(quantities, m, n))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    
private: 
    bool ok(vector<int>& quantities, int maxv, int n)
    {
        int m = 0, i = 0, j = quantities.size();
        while (i < j)
        {
            m += quantities[i] / maxv;
            if (quantities[i] % maxv)
                m++;
            i++;
        }
        return (m <= n);
    }
};
