//  Topic   ：2048. Next Greater Numerically Balanced Number (https://leetcode.com/problems/next-greater-numerically-balanced-number/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : better than O(N), worse than O(1)


class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> pool = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666};
        int ans = 1224444; 
        string ns = to_string(n);
        for (auto i : pool)
        {
            string cs = to_string(i);
            if (cs.length() < ns.length())
                continue;
            else if (cs.length() > ns.length())
                ans = min<int>(ans, i);
            else
            {
                do
                {
                    if (cs > ns)
                        ans = min<int>(ans, stoi(cs));
                } while (next_permutation(cs.begin(), cs.end()));
            }
        }
        return ans;
    }
};
