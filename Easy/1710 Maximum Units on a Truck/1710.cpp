//  Topic   : 1710. Maximum Units on a Truck
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(logN)


class Solution {
public:       
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            ans += boxTypes[i][1] * min(truckSize, boxTypes[i][0]);
            truckSize -= boxTypes[i][0];
            if (truckSize <= 0)
                break;
        }
        return ans;
    }
};
