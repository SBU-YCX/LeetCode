//  Topic   : 2149. Rearrange Array Elements by Sign
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> ans(n, 0);
        for (int k = 0; k < n; k += 2)
        {
            while (i < n && nums[i] < 0)
                i++;
            ans[k] = nums[i];
            i++;
            while (j < n && nums[j] > 0)
                j++;
            ans[k + 1] = nums[j];
            j++;
        }
        return ans;
    }
};
