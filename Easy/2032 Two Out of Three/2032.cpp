//  Topic   : 2032. Two Out of Three (https://leetcode.com/problems/two-out-of-three/)
//  Author  : YCX
//  Time    : O(N = N1 + N2 + N3)
//  Space   : O(N = N1 + N2 + N3)


class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int n1 = nums1.size(), n2 = nums2.size(), n3 = nums3.size(); 
        unordered_map<int, string> m;
        for (int i = 0; i < n1; i++)
        {
            if (m.count(nums1[i]) == 0)
                m[nums1[i]] = "001";
            else
                m[nums1[i]][2] = '1';
        }
        for (int i = 0; i < n2; i++)
        {
            if (m.count(nums2[i]) == 0)
                m[nums2[i]] = "010";
            else
                m[nums2[i]][1] = '1';
        }
        for (int i = 0; i < n3; i++)
        {
            if (m.count(nums3[i]) == 0)
                m[nums3[i]] = "100";
            else
                m[nums3[i]][0] = '1';
        }
        vector<int> ans;
        for (auto i : m)
            if (i.second == "101" || i.second == "110" || i.second == "011" || i.second == "111")
                ans.push_back(i.first);
        return ans;
    }
};
© 2021 GitHub, Inc.
Terms
Privacy
Secur
