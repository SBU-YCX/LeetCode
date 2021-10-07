# [199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)


## Description:

<p>Given the <code>root</code> of a binary tree, imagine yourself standing on the <strong>right side</strong> of it, return <em>the values of the nodes you can see ordered from top to bottom.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)</br>
<pre>
<strong>Input:</strong> root = [1,2,3,null,5,null,4]
<strong>Output:</strong> [1,3,4]
<strong>Explanation:</strong>
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> root = [1,null,3]
<strong>Output:</strong> [1,3]
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
  <li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using <strong>Depth-First Search</strong>, traverse the whole tree from right to left, meanwhile keeping a record of <code>depth</code> for each node, if <code>depth &gt; ans.length</code>, put that node in the result array <code>and</code>.</p>


<strong>C++</strong>

```
// Topic     : 199. Binary Tree Right Side View (https://leetcode.com/problems/binary-tree-right-side-view/)
// Author    : YCX
// Time      : O(N)
// Space     : O(H)


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightSideView(root, 1, ans);
        return ans;
    }
    
private: 
    void rightSideView(TreeNode* root, int depth, vector<int>& ans) {
        if (!root)
            return;
        if (depth > ans.size())
            ans.push_back(root->val);
        rightSideView(root->right, depth + 1, ans);
        rightSideView(root->left, depth + 1, ans);
        return;
    }
};
```
