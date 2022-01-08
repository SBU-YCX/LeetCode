//  Topic   : 2130. Maximum Twin Sum of a Linked List
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> q;
        ListNode* cur = head;
        while (cur)
        {
            q.push_back(cur->val);
            cur = cur->next;
        }
        int ans = 0, n = q.size(), l = 0, r = n - 1;
        while (l < r)
        {
            ans = max<int>(ans, q[l] + q[r]);
            l++;
            r--;
        }
        return ans;
    }
};
