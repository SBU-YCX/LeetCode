//  Topic   : 1791. Find Center of Star Graph
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
    }
};
