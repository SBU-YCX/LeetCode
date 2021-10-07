// Topic     : 1442. Count Triplets That Can Form Two Arrays of Equal XOR (https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)
// Author    : YCX
// Time      : O(N^2)
// Space     : O(N)


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int> prexor(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prexor[i] = prexor[i - 1] ^ arr[i - 1];
        for (int i = 1; i <= n; i++)
            for (int k = i + 1; k <= n; k++)
                if (prexor[k] == prexor[i - 1])
                    ans += (k - i);
        return ans;
    }
};
