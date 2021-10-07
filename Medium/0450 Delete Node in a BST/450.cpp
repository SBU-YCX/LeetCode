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
