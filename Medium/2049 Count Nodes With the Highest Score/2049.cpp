//  Topic   ：2049. Count Nodes With the Highest Score (https://leetcode.com/problems/count-nodes-with-the-highest-score/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size(), ans = 0;
        long long maxv = 0; 
        vector<int> nodes(n, 1), children(n, 0);
        unordered_map<int, vector<int>> child;
        for (int i = 0; i < n; i++)
        {
            child[parents[i]].push_back(i);
            if (i != 0)
                children[parents[i]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (children[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == 0)
                continue;
            children[parents[cur]]--;
            nodes[parents[cur]] += nodes[cur];
            if (children[parents[cur]] == 0)
                q.push(parents[cur]);
        }
        for (int i = 0; i < n; i++)
        {
            long long prod = max<long long>(1, n - nodes[i]);
            for (int j = 0; j < child[i].size(); j++)
                prod *= nodes[child[i][j]];
            if (prod > maxv)
            {
                maxv = prod;
                ans = 1;
            }
            else if (prod == maxv)
                ans++;
        }
        return ans;
    }
};
