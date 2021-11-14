//  Topic   ：2074. Reverse Nodes in Even Length Groups (https://leetcode.com/problems/reverse-nodes-in-even-length-groups/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        stack<ListNode*> s, t;
        ListNode* ans = new ListNode(), * cur1 = head, * cur2 = ans, *nxt;
        int k = 1;
        while (cur1)
        {
            int j = 0;
            while (j < k)
            {
                if (!cur1)
                    break;
                nxt = cur1->next;
                cur1->next = nullptr;
                s.push(cur1);
                cur1 = nxt;
                j++;
            }
            j = s.size();
            if (j % 2)
            {
                while (!s.empty())
                {
                    t.push(s.top());
                    s.pop();
                }
                while (!t.empty())
                {
                    cur2->next = t.top();
                    cur2 = cur2->next;
                    t.pop();
                }
            }
            else
                while (!s.empty())
                {
                    cur2->next = s.top();
                    cur2 = cur2->next;
                    s.pop();
                }
            k++;
        }
        return ans->next;
    }
};
