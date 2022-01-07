//  Topic   : 1925. Count Square Sum Triples
//  Author  : YCX
//  Time    : O(N^2)
//  Space   : O(1)


class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 1; i < n; i++)
            for (int j = i; i * i + j * j <= n * n; j++)
            {
                int k = i * i + j * j;
                if (k == int(sqrt(k)) * int(sqrt(k)))
                    ans += 2;
            }
        return ans;
    }
};
