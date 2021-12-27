//  Topic   : 2078. Two Furthest Houses With Different Colors (https://leetcode.com/problems/two-furthest-houses-with-different-colors/)
//  Author  : YCX
//  Time    : O(N ^ 2)
//  Space   : O(N)


class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_map<int, int> idx;
        int n = colors.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            bool exist = false;
            for (auto& j : idx)
            {
                if (j.first != colors[i])
                    ans = max<int>(ans, i - j.second);
                else
                    exist = true;
            }
            if (!exist)
                idx[colors[i]] = i;
        }
        return ans;
    }
};
