//  Topic   ：448. Find All Numbers Disappeared in an Array (https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
//  Author  : YCX
//  Time    : O(N) average, O(N^2) worst
//  Space   : O(N)


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> appear;
        for (int i = 0; i < n; i++)
            appear[nums[i]] = 1;
        for (int i = 1; i <= n; i++)
            if (!appear.count(i))
                ans.push_back(i);
        return ans;
    }
};
