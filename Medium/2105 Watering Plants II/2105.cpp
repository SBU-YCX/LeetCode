//  Topic   : 2105. Watering Plants II (https://leetcode.com/problems/watering-plants-ii/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l = 0, r = plants.size() - 1, ans = 0, ca = capacityA, cb = capacityB;
        while (l <= r)
        {
            if (l == r)
            {
                int cf, c = max<int>(ca, cb);
                if (c == ca)
                    cf = capacityA;
                else
                    cf = capacityB;
                if (c < plants[l])
                    ans++;
            }
            else
            {
                if (ca >= plants[l])
                    ca -= plants[l];
                else
                {
                    ans++;
                    ca = capacityA - plants[l];
                }
                if (cb >= plants[r])
                    cb -= plants[r];
                else
                {
                    ans++;
                    cb = capacityB - plants[r];
                }
            }
            l++;
            r--;
        }
        return ans;
    }
};
