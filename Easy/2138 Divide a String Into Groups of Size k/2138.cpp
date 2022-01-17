//  Topic   : 2138. Divide a String Into Groups of Size k
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(K)


class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;
        for (int i = 0; i < n; i += k)
        {
            if (i + k > n)
                ans.push_back(s.substr(i) + string(i + k - n, fill));
            else
                ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};
