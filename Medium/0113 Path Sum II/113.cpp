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
