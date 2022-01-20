//  Topic   : 1748. Sum of Unique Elements
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto& i : nums)
            freq[i]++;
        int ans = 0;
        for (auto& p : freq)
            if (p.second == 1)
                ans += p.first;
        return ans;
    }
};
