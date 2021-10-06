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
