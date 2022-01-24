//  Topic   : 1678. Goal Parser Interpretation
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string interpret(string command) {
        string ans = "";
        stack<char> cache;
        for (int i = 0; i < command.length(); i++)
        {
            if (command[i] == 'G')
                ans += command[i];
            else if (command[i] == '(')
                cache.push(command[i]);
            else if (command[i] == ')')
            {
                if (!cache.empty() && cache.top() == '(')
                {
                    ans += 'o';
                    cache.pop();
                }
            }
            else if (command[i] == 'a')
            {
                cache.pop();
                ans += command[i];
            }
            else
                ans += command[i];
            
        }
        return ans;
    }
};
