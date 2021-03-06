//  Topic   : 2126. Destroying Asteroids (https://leetcode.com/problems/destroying-asteroids/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(1)


class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long massl = mass;
        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] <= massl)
                massl += asteroids[i];
            else
                return false;
        }
        return true;
    }
};
