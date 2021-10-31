# [2058. Find the Minimum and Maximum Number of Nodes Between Critical Points](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)


## Description:

<p>A <strong>critical point</strong> in a linked list is defined as <strong>either</strong> a <strong>local maxima</strong>> or a <strong>local minima</strong>.</p>
<p>A node is a <strong>local maxima</strong> if the current node has a value <strong>strictly greater</strong> than the previous node and the next node.</p>
<p>A node is a <strong>local minima</strong> if the current node has a value <strong>strictly smaller</strong> than the previous node and the next node.</p>
<p>Note that a node can only be a local maxima/minima if there exists <strong>both</strong> a previous node and a next node.</p>
<p>Given a linked list <code>head</code>, return <em>an array of length 2 containing <code>[minDistance, maxDistance]</code> where <code>minDistance</code> is the <strong>minimum distance</strong> between <strong>any two distinct</strong> critical points and <code>maxDistance</code> is the <strong>maximum distance</strong> between <strong>any two distinct</strong> critical points. If there are fewer than two critical points, return <code>[-1, -1]</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/13/a1.png)</br>
<pre>
<strong>Input:</strong> head = [3,1]
<strong>Output:</strong> [-1,-1]
<strong>Explanation:</strong> 
There are no critical points in [3,1].
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/10/13/a2.png)</br>
<pre>
<strong>Input:</strong> head = [5,3,1,2,5,1,2]
<strong>Output:</strong> [1,3]
<strong>Explanation:</strong>
There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
</pre>

<strong>Example 3:</strong>
<br/>![ex3](https://assets.leetcode.com/uploads/2021/10/14/a5.png)</br>
<pre>
<strong>Input:</strong> head = [1,3,2,2,3,2,2,2,7]
<strong>Output:</strong> [3,3]
<strong>Explanation:</strong>
There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
</pre>

<strong>Example 4:</strong>
<br/>![ex4](https://assets.leetcode.com/uploads/2021/10/13/a4.png)</br>
<pre>
<strong>Input:</strong> head = [2,3,3,2]
<strong>Output:</strong> [-1,-1]
<strong>Explanation:</strong>
There are no critical points in [2,3,3,2].
</pre>


## Constraints:

<ul>
  <li>The number of nodes in the list is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
  <li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Go through the whole list and check each node whether it is a local minimum or maximum. Store all the indices of critical points in an array, the maximum distance is the distance between the first and the last critical points, and the minimum distance can be obtained by traverse the critical points array. </p>

 
<strong>C++</strong>

```
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
```
