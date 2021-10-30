//  Topic   : 2053. Kth Distinct String in an Array (https://leetcode.com/problems/kth-distinct-string-in-an-array/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for (auto i : arr)
            m[i]++;
        for (auto i : arr)
            if (m[i] == 1)
            {
                k--;
                if (k == 0)
                    return i;
            }
        return "";
    }
};
