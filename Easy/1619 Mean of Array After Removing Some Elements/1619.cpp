//  Topic   : 1619. Mean of Array After Removing Some Elements
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(1ogN)


class Solution {
public:
    double trimMean(vector<int>& arr) {
        int m = arr.size();
        int n = m / 20;
        double ans = 0;
        sort(arr.begin(), arr.end());
        for (int i = n; i < m - n; i++)
            ans += arr[i];
        return ans / (m - 2 * n);
    }
};
