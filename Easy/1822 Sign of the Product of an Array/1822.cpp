//  Topic   : 1822. Sign of the Product of an Array
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int arraySign(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                return 0;
            else if (nums[i] < 0)
                num += 1;
        }
        if (num % 2 == 0)
            return 1;
        else
            return -1;
    }
};
