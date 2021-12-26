//  Topic   : 2095. Delete the Middle Node of a Linked List (https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* ans = new ListNode();
        ans->next = head;
        ListNode* cur = ans->next, * nxt = ans->next->next;
        if (!nxt)
            return nullptr;
        while (nxt->next && nxt->next->next)
        {
            nxt = nxt->next->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return (ans->next);
    }
};
