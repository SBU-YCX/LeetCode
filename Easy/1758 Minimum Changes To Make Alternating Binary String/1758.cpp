//  Topic   : 1758. Minimum Changes To Make Alternating Binary String
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minOperations(string s) {
        int op_0 = 0, op_1 = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            if ((i % 2) != (s[i] - '0'))
                op_0 += 1;
            if (((i + 1) % 2) != (s[i] - '0'))
                op_1 += 1;
        }
        return min<int>(op_0, op_1);
    }
};
