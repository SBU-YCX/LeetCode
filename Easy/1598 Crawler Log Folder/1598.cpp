//  Topic   : 1598. Crawler Log Folder
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folders;
        int m = logs.size();
        for (int i = 0; i < m; i++)
        {
            if (logs[i] == "./")
                continue;
            else if (logs[i] == "../")
            {
                if (!folders.empty())
                    folders.pop();
            }
            else
                folders.push(logs[i]);
        }
        return folders.size();
    }
};
