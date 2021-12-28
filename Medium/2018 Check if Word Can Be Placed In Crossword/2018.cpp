//  Topic   ：2018. Check if Word Can Be Placed In Crossword (https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/)
//  Author  : YCX
//  Time    : O(M * N)
//  Space   : O(M * N)


class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> boardT(n, vector<char>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                boardT[j][i] = board[i][j];
        string rword = string(word.rbegin(), word.rend());
        return check(board, word) || check(board, rword) || check(boardT, word) || check(boardT, rword);
    }
    
private: 
    bool check(vector<vector<char>>& board, string& word)
    {
        int m = board.size(), n = board[0].size(), l = word.length();
        vector<vector<int>> matched(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (j == 0 || board[i][j - 1] == '#' || matched[i][j - 1] != -1)
                {
                    int k = (j == 0) ? 0 : (matched[i][j - 1] + 1);
                    if (board[i][j] == ' ' || board[i][j] == word[k])
                    {
                        if (k == l - 1)
                        {
                            if (j == n - 1 || board[i][j + 1] == '#')
                                return true;
                        }
                        else
                            matched[i][j] = k;
                    }
                }
        return false;
    }
    
};
