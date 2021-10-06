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
