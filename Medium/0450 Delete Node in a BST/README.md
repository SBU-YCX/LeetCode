# [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)


## Description:

<p>Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.</p>
<p>Basically, the deletion can be divided into two stages:</p>
<ol>
    <li>Search for a node to remove.</li>
    <li>If the node is found, delete the node.</li>
</ol>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1.1](https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg)</br>
<pre>
<strong>Input:</strong> root = [5,3,6,2,4,null,7], key = 3
<strong>Output:</strong> [5,4,6,2,null,null,7]
<strong>Explanation:</strong> Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
</pre>
<br/>![ex1.2](https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg)</br>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> root = [5,3,6,2,4,null,7], key = 0
<strong>Output:</strong> [5,3,6,2,4,null,7]
<strong>Explanation:</strong> The tree does not contain a node with value = 0.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> root = [], key = 0
<strong>Output:</strong> []
<strong>Explanation:</strong>
</pre>


## Constraints:

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>].</code></li>
  <li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
  <li>Each node has a <strong>unique</strong> value.</code></li>
  <li><code>root</code> is a valid binary search tree.</li>
  <li><code>-10<sup>5</sup> &lt;= key &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Firstly, we need to search the target node needed to be deleted in the BST. If <code>node</code> is a leaf node, just set it to <code>nullptr</code>; otherwise, we can replace it with its neighbor according values, i.e. the left-most leaf node of its right-subtree or right-most leaf node of its left-subtree, and then, just delete that neighbor.</p>


<strong>C++</strong>

```
// Topic     : 450. Delete Node in a BST (https://leetcode.com/problems/delete-node-in-a-bst/)
// Author    : YCX
// Time      : O(H)
// Space     : O(H)


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            if (!root->left && !root->right)
                root = nullptr;
            else if (root->right)
            {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
            else
            {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
    
private: 
    int successor(TreeNode* root)
    {
        TreeNode* cur = root->right;
        while (cur->left)
            cur = cur->left;
        return cur->val;
    }
    
    int predecessor(TreeNode* root)
    {
        TreeNode* cur = root->left;
        while (cur->right)
            cur = cur-> right;
        return cur->val;
    }
};
```
