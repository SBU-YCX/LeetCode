# [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)


## Description:

<p>Given the <code>root</code> of a binary tree, return <em>the zigzag level order traversal of its nodes' values.</em> (i.e., from left to right, then right to left for the next level and alternate between).</p>


## Examples:

<strong>Example 1:</strong>
<p>![ex](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)</p>
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[20,9],[15,7]]
<strong>Explanation:</strong> 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
<strong>Explanation:</strong> 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
  <li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using Depth-First Search to traverse the whole tree, while keeping a record of the depth of each node, if <code>depth</code> is odd, add a new node value from right to left; otherwise, add a new node value from left to right.</p>


<strong>C++</strong>

```
//  Topic   ：103. Binary Tree Zigzag Level Order Traversal (https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(H) [H is the depth of the tree]


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        zigzagLevelOrder(root, 1, ans);
        return ans;
    }
    
private: 
    void zigzagLevelOrder(TreeNode* root, int depth, vector<vector<int>>& ans) {
        if (!root)
            return;
        if (depth > ans.size())
            ans.push_back({root->val});
        else
        {
            if (depth % 2 == 1)
                ans[depth - 1].push_back(root->val);
            else
                ans[depth - 1].insert(ans[depth - 1].begin(), root->val);
        }
        zigzagLevelOrder(root->left, depth + 1, ans);
        zigzagLevelOrder(root->right, depth + 1, ans);   
    }
};
```
