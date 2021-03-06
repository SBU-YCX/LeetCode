// Topic     : 2122. Recover the Original Array (https://leetcode.com/problems/recover-the-original-array/)
// Author    : YCX
// Time      : O(NlogN + N^2)
// Space     : O(N)


class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (auto& i : nums)
            mp[i]++;
        int k, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            k = nums[i] - nums[0];
            if (k % 2)
                continue;
            if (success(k, mp, nums, n))
                break;
        }
        k /= 2;
        vector<int> ans;
        for (auto& low : nums)
        {
            if (mp[low] == 0)
                continue;
            int arr = low + k, high = low + 2 * k;
            mp[high] -= mp[low];
            while (mp[low])
            {
                ans.push_back(arr);
                mp[low]--;
            }
        }
        return ans;
    }
    
private:
    bool success(int k, unordered_map<int, int>& mp, vector<int>& nums, int& n)
    {
        int l = 0;
        auto mq = mp;
        for (auto& low : nums)
        {
            if (mq[low] == 0)
                continue;
            int high = low + k;
            if (!mq.count(high) || mq[high] < mq[low])
                return false;
            l += (2 * mq[low]);
            mq[high] -= mq[low];
            mq[low] = 0;
        }
        return (l == n);
    }
};
