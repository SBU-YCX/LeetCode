// Topic     : 2111. Minimum Operations to Make the Array K-Increasing (https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)
// Author    : YCX
// Time      : O(NlogN)
// Space     : O(N)


class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < k; i++)
        {
            vector<int> ordered;
            for (int j = i; j < n; j += k)
            {
                if(ordered.size() == 0 || ordered.back() <= arr[j])
                    ordered.push_back(arr[j]);
                else
                    *upper_bound(ordered.begin(), ordered.end(), arr[j]) = arr[j];
            }
            ans += ordered.size();
        }
        return (n - ans);
    }
};
