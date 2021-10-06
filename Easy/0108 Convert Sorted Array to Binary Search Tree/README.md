# [108. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)


## Description:

<p>Given an integer array <code>nums</code> where the elements are sorted in <strong>ascending order</strong>, convert <em>it to a <strong>height-balanced</strong> binary search tree.</em></p>
<p>A <strong>height-balanced</strong> binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.</p>


## Examples:

<strong>Example 1:</strong>
<p>![ex1.1](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)</p>
<pre>
<strong>Input:</strong> nums = [-10,-3,0,5,9]
<strong>Output:</strong> [0,-3,9,-10,null,5]
<strong>Explanation:</strong> [0,-10,5,null,-3,null,9] is also accepted:
<p>![ex1.2](https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg)</p>
</pre>

<strong>Example 2:</strong>
<p>![ex2](https://assets.leetcode.com/uploads/2021/02/18/btree.jpg)</p>
<pre>
<strong>Input:</strong> nums = [1,3]
<strong>Output:</strong> [3,1]
<strong>Explanation:</strong> [1,3] and [3,1] are both a height-balanced BSTs.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
  <li><code>nums</code>  is sorted in a <strong>strictly increasing</strong> order.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>To build a height-balanced tree, we need to try to make the left sub-tree and right-subtree have the same height, i.e. we can find the middle element of <code>nums</code> as the <code>root</code>, then left half is the left-subtree and right half is the right-subtree. Recursively, we do this for each subtree so that no two subtrees of a node have heights different by more than one.</p>


<strong>C++</strong>

```
//  Topic   ：108. Convert Sorted Array to Binary Search Tree (https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(logN)


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    
private: 
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (start < mid)
            root->left = sortedArrayToBST(nums, start, mid);
        if (mid < end - 1)
            root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};
```