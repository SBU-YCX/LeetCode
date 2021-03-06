//  Topic   ：2058. Find the Minimum and Maximum Number of Nodes Between Critical Points (https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 1;
        vector<int> critical;
        ListNode* cur = head->next, * prev = head;
        while (cur->next)
        {
            if (cur->val > prev->val && cur->val > cur->next->val || cur->val < prev->val && cur->val < cur->next->val)
                critical.push_back(i);
            i++;
            prev = prev->next;
            cur = cur->next;
        }
        if (critical.size() < 2)
            return {-1, -1};
        int n = critical.size(), mind = INT_MAX, maxd;
        maxd = critical[n - 1] - critical[0];
        for (int j = 1; j < n; j++)
            mind = min<int>(mind, critical[j] - critical[j - 1]);
        return {mind, maxd};
    }
};
