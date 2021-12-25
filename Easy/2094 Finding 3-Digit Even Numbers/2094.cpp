//  Topic   : 2094. Finding 3-Digit Even Numbers (https://leetcode.com/problems/finding-3-digit-even-numbers/)
//  Author  : YCX
//  Time    : O((N ^ 3)log(N ^ 3)) [N <= 10]
//  Space   : O(N ^ 3)


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            if (digits[i] == 0)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;
                    if (digits[k] % 2 == 0)
                    {
                        int t = digits[i] * 100 + digits[j] * 10 + digits[k];
                        s.insert(t);
                    }
                }
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};
