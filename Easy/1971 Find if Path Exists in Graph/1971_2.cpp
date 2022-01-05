//  Topic   : 1971. Find if Path Exists in Graph
//  Author  : YCX
//  Time    : O(MlogN)
//  Space   : O(N)


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> group(n, 0);
        for (int i = 0; i < n; i++)
            group[i] = i;
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            int root1 = findRoot(group, edges[i][0]);
            int root2 = findRoot(group, edges[i][1]);
            if (root1 != root2)
                group[root1] = root2;
        }
        return (findRoot(group, start) == findRoot(group, end));
    }
    
private: 
    int findRoot(vector<int>& group, int node)
    {
        if (group[node] == node)
            return node;
        return findRoot(group, group[node]);
    }
};
