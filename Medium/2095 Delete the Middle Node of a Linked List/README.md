# [2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)


## Description:

<p>You are given the <code>head</code> of a linked list. <strong>Delete</strong> the <strong>middle node</strong>, and return <em>the <code>head</code> of the modified linked list.</em></p>

<p>The <strong>middle node</strong> of a linked list of size <code>n</code> is the <code>⌊n / 2⌋<sup>th</sup></code> node from the <strong>start</strong> using <strong>0-based indexing</strong>, where <code>⌊x⌋</code> denotes the largest integer less than or equal to <code>x</code>.</p>
<ul>
    <li>For <code>n</code> = <code>1</code>, <code>2</code>, <code>3</code>, <code>4</code>, and <code>5</code>, the middle nodes are <code>0</code>, <code>1</code>, <code>1</code>, <code>2</code>, and <code>2</code>, respectively.</p>
</ul>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png)
<pre>
<strong>Input:</strong> head = [1,3,4,7,1,2,6]
<strong>Output:</strong> [1,3,4,1,2,6]
<strong>Explanation:</strong> 
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/11/16/eg2drawio.png)
<pre>
<strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [1,2,4]
<strong>Explanation:</strong> 
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/11/16/eg3drawio.png)
<pre>
<strong>Input:</strong> head = [2,1]
<strong>Output:</strong> [2]
<strong>Explanation:</strong> 
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
</pre>


## Constraints:

<ul>
    <li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
    <li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since this problem requires us to remove the middle node, we can use <strong>fast-slow pointers</strong> to find out the middle one. Specifically, the fast pointer <code>nxt</code> moves 2 steps forward each time while the slow pointer <code>cur</code> moves 1 step forward, so when the fast pointer arrives at the tail of the list, the slow pointer points to the middle node.</p>


<strong>C++</strong>

```
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
```