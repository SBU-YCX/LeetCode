# [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


## Description:

<p>Given two integer arrays <code>preorder</code> and <code>inorder</code> where <code>preorder</code> is the preorder traversal of a binary tree and <code>inorder</code> is the inorder traversal of the same tree, construct and return <em>the binary tree</em>.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)</br>
<pre>
<strong>Input:</strong> preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
<strong>Output:</strong> [3,9,20,null,null,15,7]
<strong>Explanation:</strong> 
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> preorder = [-1], inorder = [-1]
<strong>Output:</strong> [-1]
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= preorder.length &lt;= 3000</code></li>
  <li><code>inorder.length == preorder.length</code></li>
  <li><code>-3000 &lt;= preorder[i], inorder[i] &lt;= 3000</code></li>
  <li><code>preorder</code> and <code>inorder</code> consist of <strong>unique</strong> values.</li>
  <li>Each value of <code>inorder</code> also appears in <code>preorder</code>.</li>
  <li><code>preorder</code> is <strong>guaranteed</strong> to be the preorder traversal of the tree.</li>
  <li><code>inorder</code> is <strong>guaranteed</strong> to be the inorder traversal of the tree.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>In <code>preorder</code>, we know the array can be split as <code>[root, left-subtree, right-subtree]</code>, while in <code>inorder</code>, the array can be split as <code>[left-subtree, root, right-subtree]</code>. So we are sure that the first element in <code>preorder</code> is the root and we need to find its index in <code>inorder</code> through a hash table, so that we can get the sizes of both subtrees. Then, we can recursively do the same thing for each subtree. </p>


<strong>C++</strong>

```
//  Topic   ：105. Construct Binary Tree from Preorder and Inorder Traversal (https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> idx;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            idx[inorder[i]] = i;
        TreeNode* ans = buildTree(preorder, idx, 0, 0, n);
        return ans;
    }
    
private: 
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int>& idx, int root_p, int begin, int end) {
        if (begin >= end)
            return nullptr;
        int root_val = preorder[root_p];
        TreeNode* root = new TreeNode(root_val);
        int i = idx[root_val];
        root->left = buildTree(preorder, idx, root_p + 1, begin, i);
        root->right = buildTree(preorder, idx, root_p + 1 + i - begin, i + 1, end);
        return root;
    }
};
```
