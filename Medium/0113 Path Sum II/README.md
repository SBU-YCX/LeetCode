# [113. Path Sum II](https://leetcode.com/problems/path-sum-ii/)


## Description:

<p>Given the <code>root</code> of a binary tree and an integer <code>targetSum</code>, return <em>all <strong>root-to-leaf</strong> paths where the sum of the node values in the path equals <code>targetSum</code>. Each path should be returned as a list of the node <strong>values</strong>, not node references.</em></p>
<p>A <strong>root-to-leaf</strong> path is a path starting from the root and ending at any leaf node. A <strong>leaf</strong> is a node with no children.</p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)</br>
<pre>
<strong>Input:</strong> root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
<strong>Output:</strong> [[5,4,11,2],[5,8,4,5]]
<strong>Explanation:</strong> There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)</br>
<pre>
<strong>Input:</strong> root = [1,2,3], targetSum = 5
<strong>Output:</strong> []
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> root = [1,2], targetSum = 0
<strong>Output:</strong> []
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 5000]</code>.</li>
  <li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
  <li><code>-1000 &lt;= targetSum &lt;= 1000</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Using <strong>Depth-First Search</strong> and <strong>Recursion</strong>, for each <code>node</code>, recursively find <code>targetSum == targetSum - node->val</code> in its left-subtree and right-subtree.</p>


<strong>C++</strong>

```
// Topic     : 113. Path Sum II (https://leetcode.com/problems/path-sum-ii/)
// Author    : YCX
// Time      : O(N * H)
// Space     : O(H)


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        if (root && !root->left && !root->right)
        {
            if (root->val == targetSum)
                ans.push_back({root->val});
            return ans;
        }
        vector<vector<int>> l_ans = pathSum(root->left, targetSum - root->val);
        for (int i = 0; i < l_ans.size(); i++)
        {
            l_ans[i].insert(l_ans[i].begin(), root->val);
            ans.push_back(l_ans[i]);
        }
        vector<vector<int>> r_ans = pathSum(root->right, targetSum - root->val);
        for (int i = 0; i < r_ans.size(); i++)
        {
            r_ans[i].insert(r_ans[i].begin(), root->val);
            ans.push_back(r_ans[i]);
        }
        return ans;
    }
};
```
