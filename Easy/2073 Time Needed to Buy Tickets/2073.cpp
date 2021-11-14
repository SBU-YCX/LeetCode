//  Topic   : 2073. Time Needed to Buy Tickets (https://leetcode.com/problems/time-needed-to-buy-tickets/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, target = tickets[k], n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            if (i <= k)
                ans += min<int>(tickets[i], target);
            else
                ans += min<int>(tickets[i], target - 1);
        }
        return ans;
    }
};
