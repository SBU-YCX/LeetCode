//  Topic   : 2094. Finding 3-Digit Even Numbers (https://leetcode.com/problems/finding-3-digit-even-numbers/)
//  Author  : YCX
//  Time    : O((10 ^ 3))
//  Space   : O(N ^ 3)


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++)
            freq[digits[i]]++;
        vector<int> ans;
        for (int i = 100; i <= 999; i += 2)
        {
            int d1 = i / 100, d2 = (i % 100) / 10, d3 = i % 10;
            freq[d1]--;
            freq[d2]--;
            freq[d3]--;
            if (freq[d1] >= 0 & freq[d2] >= 0 & freq[d3] >= 0)
                ans.push_back(i);
            freq[d1]++;
            freq[d2]++;
            freq[d3]++;
        }  
        return ans;
    }
};
