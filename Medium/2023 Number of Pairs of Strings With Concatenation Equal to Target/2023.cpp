//  Topic   ：2023. Number of Pairs of Strings With Concatenation Equal to Target (https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ans = 0, l = target.length();
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++)
            m[nums[i]]++;
        for (auto s : m)
        {
            int k = s.first.length();
            if (k > l)
                continue;
            if (s.first == target.substr(0, k))
            {
                string t = target.substr(k);
                ans += s.second * m[t];
                if (s.first == t)
                    ans -= m[t];
            }
        }
        return ans;
    }
};
