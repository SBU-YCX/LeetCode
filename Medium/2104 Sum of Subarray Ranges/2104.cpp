//  Topic   : 2104. Sum of Subarray Ranges (https://leetcode.com/problems/sum-of-subarray-ranges/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long maxsum = 0, minsum = 0;
        vector<int> maxr(n, n), minr(n, n);
        stack<int> maxs, mins;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!maxs.empty() && nums[maxs.top()] < nums[i])
                maxs.pop();
            while (!mins.empty() && nums[mins.top()] > nums[i])
                mins.pop();
            if (maxs.empty())
                maxr[i] = n - i;
            else
                maxr[i] = maxs.top() - i;
            if (mins.empty())
                minr[i] = n - i;
            else
                minr[i] = mins.top() - i;
            maxs.push(i);
            mins.push(i);
        }
        while (!maxs.empty())
            maxs.pop();
        while (!mins.empty())
            mins.pop();
        for (int i = 0; i < n; i++)
        {
            while (!maxs.empty() && nums[maxs.top()] <= nums[i])
                maxs.pop();
            while (!mins.empty() && nums[mins.top()] >= nums[i])
                mins.pop();
            if (maxs.empty())
                maxsum += (long long)nums[i] * (maxr[i] * (i + 1));
            else
                maxsum += (long long)nums[i] * (maxr[i] * (i - maxs.top()));
            if (mins.empty())
                minsum += (long long)nums[i] * (minr[i] * (i + 1));
            else
                minsum += (long long)nums[i] * (minr[i] * (i - mins.top()));
            maxs.push(i);
            mins.push(i);
        }
        return (maxsum - minsum);
    }
};
