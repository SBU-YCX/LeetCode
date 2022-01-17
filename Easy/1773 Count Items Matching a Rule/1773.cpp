//  Topic   : 1773. Count Items Matching a Rule
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        if (ruleKey == "type")
        {
            for (int i = 0; i < items.size(); i++)
                if (items[i][0] == ruleValue)
                    ans += 1;
        }
        else if (ruleKey == "color")
        {
            for (int i = 0; i < items.size(); i++)
                if (items[i][1] == ruleValue)
                    ans += 1;
        }
        else
        {
            for (int i = 0; i < items.size(); i++)
                if (items[i][2] == ruleValue)
                    ans += 1;
        }
        return ans;
    }
};
