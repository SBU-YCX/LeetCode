//  Topic   ：2116. Check if a Parentheses String Can Be Valid (https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length(), k = 0;
        deque<int> pos;
        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0')
                pos.push_back(i);
            else
            {
                if (s[i] == '(')
                    k++;
                else
                    k--;
                if (k < 0)
                {
                    if (pos.empty())
                        return false;
                    int j = pos.front();
                    pos.pop_front();
                    locked[j] = '1';
                    s[j] = '(';
                    k++;
                }
            }
        }
        k = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (locked[i] == '0')
                continue;
            else
            {
                if (s[i] == ')')
                    k++;
                else
                    k--;
                if (k < 0)
                {
                    if (pos.empty() || pos.back() < i)
                        return false;
                    pos.pop_back();
                    k++;
                }
            }
        }
        return ((k == 0) && (pos.size() % 2 == 0));
    }
};
