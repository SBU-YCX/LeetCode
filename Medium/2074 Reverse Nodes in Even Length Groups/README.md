# [2074. Reverse Nodes in Even Length Groups](https://leetcode.com/problems/reverse-nodes-in-even-length-groups/)


## Description:

<p>You are given the <code>head</code> of a linked list.</p>

<p>The nodes in the linked list are <strong>sequentially</strong> assigned to <strong>non-empty</strong> groups whose lengths form the sequence of the natural numbers (<code>1, 2, 3, 4, ...</code>). The <strong>length</strong> of a group is the number of nodes assigned to it. In other words,</p>
<ul>
    <li>The <code>1<sup>st</sup></code> node is assigned to the first group.</li>
    <li>The <code>2<sup>nd</sup></code> and the <code>3<sup>rd</sup></code> nodes are assigned to the second group.</li>
    <li>The <code>4<sup>th</sup></code>, <code>5<sup>th</sup></code>, and <code>6<sup>th</sup></code> nodes are assigned to the third group, and so on.</li>
</ul>
<p>Note that the length of the last group may be less than or equal to <code>1 + the length of the second to last group</code>.</p>

<p><strong>Reverse</strong> the nodes in each group with an <strong>even</strong> length, and return the <code>head</code> of the modified linked list.</p>


## Examples:

<strong>Example 1:</strong>
<br>![ex1](https://assets.leetcode.com/uploads/2021/10/25/eg1.png)
<pre>
<strong>Input:</strong> head = [5,2,6,3,9,1,7,3,8,4]
<strong>Output:</strong> [5,6,2,3,9,1,4,8,3,7]
<strong>Explanation:</strong> 
- The length of the first group is 1, which is odd, hence no reversal occurrs.
- The length of the second group is 2, which is even, hence the nodes are reversed.
- The length of the third group is 3, which is odd, hence no reversal occurrs.
- The length of the last group is 4, which is even, hence the nodes are reversed.
</pre>

<strong>Example 2:</strong>
<br>![ex2](https://assets.leetcode.com/uploads/2021/10/25/eg2.png)
<pre>
<strong>Input:</strong>head = [1,1,0,6]
<strong>Output:</strong> [1,0,1,6]
<strong>Explanation:</strong> 
- The length of the first group is 1. No reversal occurrs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 1. No reversal occurrs.
</pre>

<strong>Example 3:</strong>
<br>![ex3](https://assets.leetcode.com/uploads/2021/10/28/eg3.png)
<pre>
<strong>Input:</strong> head = [2,1]
<strong>Output:</strong> [2,1]
<strong>Explanation:</strong> 
- The length of the first group is 1. No reversal occurrs.
- The length of the last group is 1. No reversal occurrs.
</pre>

<strong>Example 4:</strong>
<pre>
<strong>Input:</strong>head = [8]
<strong>Output:</strong>[8]
<strong>Explanation:</strong> There is only one group whose length is 1. No reversal occurrs.
</pre>


## Constraints:

<ul>
  <li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
  <li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>The reverse of the list can be done with the help of <strong>stack</strong>.</p>

 
<strong>C++</strong>

```
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
```
