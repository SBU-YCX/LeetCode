# [2096. Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)


## Description:

<p>You are given the <code>root</code> of a <strong>binary tree</strong> with <code>n</code> nodes. Each node is uniquely assigned a value from <code>1</code> to <code>n</code>. You are also given an integer <code>startValue</code> representing the value of the start node <code>s</code>, and a different integer <code>destValue</code> representing the value of the destination node <code>t</code>.</p>

<p>Find the <strong>shortest path</strong> starting from node <code>s</code> and ending at node <code>t</code>. Generate step-by-step directions of such path as a string consisting of only the <strong>uppercase</strong> letters <code>'L'</code>, <code>'R'</code>, and <code>'U'</code>. Each letter indicates a specific direction:</p>
<ul>
    <li><code>'L'</code> means to go from a node to its <strong>left child</strong> node.</li>
    <li><code>'R'</code> means to go from a node to its <strong>right child</strong> node.</li>
    <li><code>'U'</code> means to go from a node to its <strong>parent</strong> node.</li>
</ul>
<p>Return <em>the step-by-step directions of the <strong>shortest path</strong> from node <code>s</code> to node <code>t</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/11/15/eg1.png)
<pre>
<strong>Input:</strong> root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
<strong>Output:</strong> "UURL"
<strong>Explanation:</strong> 
The shortest path is: 3 → 1 → 5 → 2 → 6.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2021/11/15/eg2.png)
<pre>
<strong>Input:</strong> root = [2,1], startValue = 2, destValue = 1
<strong>Output:</strong> "L"
<strong>Explanation:</strong> 
The shortest path is: 2 → 1.
</pre>


## Constraints:

<ul>
    <li>The number of nodes in the tree is <code>n</code>.</li>
    <li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= Node.val &lt;= n</code></li>
    <li>All the values in the tree are <strong>unique</strong>.</li>
    <li><code>1 &lt;= startValue, destValue &lt;= n</code></li>
    <li><code>startValue != destValue</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>For this <strong>tree</strong>-related problem, we actually need to find the lowest common ancestor of <code>s</code> and <code>t</code>. So, we can traverse the whole tree in <strong>post-order</strong> and store the nodes in paths to the root from <code>s</code> and <code>t</code> into two vectors <code>pts</code> and <code>ptd</code> respectively. Then, go through both vectors backward and ignore the same nodes in both of them. After that, for each remaining element in <code>pts</code>, add an <code>'U'</code> to the answer, while for each remaining ones in <code>ptd</code>, add the corresponding character <code>'L'</code> or <code>'R'</code>.</p>


<strong>C++</strong>

```
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
```