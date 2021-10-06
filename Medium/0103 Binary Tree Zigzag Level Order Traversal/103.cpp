//  Topic   ：103. Binary Tree Zigzag Level Order Traversal (https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(H)


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
