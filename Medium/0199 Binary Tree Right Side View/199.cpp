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
