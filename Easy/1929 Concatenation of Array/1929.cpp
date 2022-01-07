//  Topic   : 1929. Concatenation of Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);
        return nums;
    }
};
