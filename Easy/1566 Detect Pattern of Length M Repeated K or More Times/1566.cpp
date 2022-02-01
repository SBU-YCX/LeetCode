//  Topic   : 1566. Detect Pattern of Length M Repeated K or More Times
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int c = 0, n = arr.size();
        for (int i = 0; i < n - m; i++)
        {
            if (arr[i] != arr[i + m])
                c = 0;
            else
                c++;
            if (c == m * (k - 1))
                return true;
        }
        return false;
    }
};
