//  Topic   : 1614. Maximum Nesting Depth of the Parentheses
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int maxDepth(string s) {
        int n = s.length(), ans = 0;
        stack<char> pa;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                pa.push('(');
            else if (s[i] == ')')
                pa.pop();
            ans = max<int>(ans, pa.size());
        }
        return ans;
    }
};
