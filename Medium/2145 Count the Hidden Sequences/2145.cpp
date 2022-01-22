//  Topic   : 2145. Count the Hidden Sequences
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long minv = 0, maxv = 0, sum = 0;
        for (auto& d : differences)
        {
            sum += d;
            maxv = max<long>(maxv, sum);
            minv = min<long>(minv, sum);
        }
        long ans = max<long>(0, (upper - maxv) - (lower - minv) + 1);
        return ans;
    }
};
