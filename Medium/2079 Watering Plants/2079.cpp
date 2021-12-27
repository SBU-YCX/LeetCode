//  Topic   : 2079. Watering Plants (https://leetcode.com/problems/watering-plants/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size(), r = capacity, ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (r >= plants[j])
            {
                ans++;
                r -= plants[j];
            }
            else
            {
                ans += (2 * j + 1);
                r = capacity - plants[j];
            }
        }
        return ans;
    }
};
