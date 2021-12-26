//  Topic   : 2096. Step-By-Step Directions From a Binary Tree Node to Another (https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<int> pts;
        vector<pair<int, char>> ptd;
        find(root, startValue, destValue, pts, ptd);
        int m = pts.size(), n = ptd.size(), i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0)
        {
            if (pts[i] == ptd[j].first)
            {
                i--;
                j--;
            }
            else
                break;
        }
        string ans = "";
        i++;
        j++;
        while (i > 0)
        {
            ans += "U";
            i--;
        }
        while (j > 0)
        {
            ans += ptd[j].second;
            j--;
        }
        return ans;
    }
    
private: 
    pair<bool, bool> find(TreeNode* root, int sv, int dv, vector<int>& pts, vector<pair<int, char>>& ptd)
    {
        if (!root)
            return {0, 0};
        auto left = find(root->left, sv, dv, pts, ptd);
        auto right = find(root->right, sv, dv, pts, ptd);
        int fs = 0, fd = 0;
        if (root->val == sv)
            fs = 1;
        if (root->val == dv)
            fd = 1;
        if (fs || left.first || right.first)
            pts.push_back(root->val);
        if (fd || left.second || right.second)
        {
            if (left.second)
                ptd.push_back({root->val, 'L'});
            else if (right.second)
                ptd.push_back({root->val, 'R'});
            else
                ptd.push_back({root->val, 'X'});
        }
        return {fs || left.first || right.first, fd || left.second || right.second};
    }
};
