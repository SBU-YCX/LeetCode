//  Topic   : 1854. Maximum Population Year
//  Author  : YCX
//  Time    : O(N + 100)
//  Space   : O(100)


class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(101, 0);
        for (int i = 0; i < logs.size(); i++)
        {
            population[logs[i][0] - 1950] += 1;
            population[logs[i][1] - 1950] -= 1;
        }
        int ans = 1950, num = population[0];
        for (int i = 1; i < population.size(); i++)
        {
            population[i] += population[i - 1];
            if (population[i] > num)
            {
                num = population[i];
                ans = 1950 + i;
            }
        }
        return ans;
    }
};
