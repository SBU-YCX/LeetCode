// Topic     : 2076. Process Restricted Friend Requests (https://leetcode.com/problems/process-restricted-friend-requests/)
// Author    : YCX
// Time      : O(M * N * logN)
// Space     : O(N)


class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        int m = restrictions.size();
        vector<vector<int>> root(n, vector<int>(2, 1));
        for (int i = 0; i < n; i++)
            root[i][0] = i;
        vector<bool> ans;
        for (auto& r : requests)
        {
            int rt1 = find(root, r[0]), rt2 = find(root, r[1]);
            if (rt1 == rt2)
                ans.push_back(true);
            else if (check(restrictions, root, rt1, rt2))
            {
                ans.push_back(true);
                uni(root, rt1, rt2);
            }
            else
                ans.push_back(false);
        }
        return ans;
    }
    
private: 
    int find(vector<vector<int>>& root, int node)
    {
        if (root[node][0] == node)
            return node;
        return root[node][0] = find(root, root[node][0]);
    }
    
    void uni(vector<vector<int>>& root, int rt1, int rt2)
    {
        if (root[rt1][1] > root[rt2][1])
            root[rt2][0] = rt1;
        else if (root[rt1][1] < root[rt2][1])
            root[rt1][0] = rt2;
        else
        {
            root[rt1][0] = rt2;
            root[rt2][1]++;
        }
    }
    
    bool check(vector<vector<int>>& restrictions, vector<vector<int>>& root, int rt1, int rt2)
    {
        for (auto& r : restrictions)
        {
            int p1 = find(root, r[0]), p2 = find(root, r[1]);
            if (p1 == rt1 && p2 == rt2 || p1 == rt2 && p2 == rt1)
                return false;
        }
        return true;
    }
};
